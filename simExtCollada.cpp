#include "simExtCollada.h"
#include "simLib.h"
#include <iostream>
#include "colladadialog.h"

#ifdef _WIN32
    #include <direct.h>
#endif /* _WIN32 */

#if defined (__linux) || defined (__APPLE__)
    #include <string.h>
    #define _stricmp(x,y) strcasecmp(x,y)
#endif

#define PLUGIN_VERSION 6 // 6 since 25/7/2016 (multiple file import), 5 since 14/12/2015 (headless mode detect), 4 since 14/5/2015, 3 since 26/11/2014, 2 since 10/1/2014 (new lock)

LIBRARY simLib;
CColladaDialog* colladaDialog=NULL;

// This is the plugin start routine (called just once, just after the plugin was loaded):
SIM_DLLEXPORT unsigned char simStart(void* reservedPointer,int reservedInt)
{
    // Dynamically load and bind CoppeliaSim functions:
     // ******************************************
     // 1. Figure out this plugin's directory:
     char curDirAndFile[1024];
 #ifdef _WIN32
     _getcwd(curDirAndFile, sizeof(curDirAndFile));
 #elif defined (__linux) || defined (__APPLE__)
     getcwd(curDirAndFile, sizeof(curDirAndFile));
 #endif
     std::string currentDirAndPath(curDirAndFile);
     // 2. Append the CoppeliaSim library's name:
     std::string temp(currentDirAndPath);
 #ifdef _WIN32
     temp+="/coppeliaSim.dll";
 #elif defined (__linux)
     temp+="/libcoppeliaSim.so";
 #elif defined (__APPLE__)
     temp+="/libcoppeliaSim.dylib";
 #endif /* __linux || __APPLE__ */
    // 3. Load the CoppeliaSim library:
    simLib=loadSimLibrary(temp.c_str());
    if (simLib==NULL)
    {
        CColladaDialog::outputMsg(sim_verbosity_errors,"simExtCollada: error: could not find or correctly load the CoppeliaSim library. Cannot start 'Collada' plugin.");
        return(0); // Means error, CoppeliaSim will unload this plugin
    }
    if (getSimProcAddresses(simLib)==0)
    {
        CColladaDialog::outputMsg(sim_verbosity_errors,"simExtCollada: error: could not find all required functions in the CoppeliaSim library. Cannot start 'Collada' plugin.");
        unloadSimLibrary(simLib);
        return(0); // Means error, CoppeliaSim will unload this plugin
    }
    // ******************************************

    // Check the version of CoppeliaSim:
    // ******************************************
    int simVer;
    simGetIntegerParameter(sim_intparam_program_version,&simVer);
    if (simVer<20604) // if CoppeliaSim version is smaller than 2.06.04
    {
        CColladaDialog::outputMsg(sim_verbosity_errors,"simExtCollada: error: sorry, your CoppeliaSim copy is somewhat old. Cannot start 'Collada' plugin.");
        unloadSimLibrary(simLib);
        return(0); // Means error, CoppeliaSim will unload this plugin
    }
    // ******************************************

    // Check if CoppeliaSim runs in headless mode:
    // ******************************************
    if (simGetBooleanParameter(sim_boolparam_headless)>0)
    {
        CColladaDialog::outputMsg(sim_verbosity_errors,"simExtCollada: error: CoppeliaSim runs in headless mode. Cannot start 'Collada' plugin.");
        unloadSimLibrary(simLib);
        return(0); // Means error, CoppeliaSim will unload this plugin
    }
    // ******************************************

    QWidget* pMainWindow = (QWidget*)simGetMainWindow(1);
    colladaDialog=new CColladaDialog(pMainWindow); // The plugin dialog
    simAddModuleMenuEntry("",1,&colladaDialog->dialogMenuItemHandle);
    simSetModuleMenuItemState(colladaDialog->dialogMenuItemHandle,1,"COLLADA import/export...");

    return(PLUGIN_VERSION); // initialization went fine, we return the version number of this plugin (can be queried with simGetModuleName)
}

// This is the plugin end routine (called just once, when CoppeliaSim is ending, i.e. releasing this plugin):
SIM_DLLEXPORT void simEnd()
{
    // Here you could handle various clean-up tasks
    delete colladaDialog;
    unloadSimLibrary(simLib); // release the library
}

// This is the plugin messaging routine (i.e. CoppeliaSim calls this function very often, with various messages):
SIM_DLLEXPORT void* simMessage(int message,int* auxiliaryData,void* customData,int* replyData)
{ // This is called quite often. Just watch out for messages/events you want to handle
    // Keep following 6 lines at the beginning and unchanged:
    static bool refreshDlgFlag=true;
    int errorModeSaved;
    simGetIntegerParameter(sim_intparam_error_report_mode,&errorModeSaved);
    simSetIntegerParameter(sim_intparam_error_report_mode,sim_api_errormessage_ignore);
    void* retVal=NULL;

    // Here we can intercept many messages from CoppeliaSim (actually callbacks).
    // For a complete list of messages that you can intercept/react with, search for "sim_message_eventcallback"-type constants
    // in the CoppeliaSim user manual.

    if (message==sim_message_eventcallback_refreshdialogs)
        refreshDlgFlag=true; // CoppeliaSim dialogs were refreshed. Maybe a good idea to refresh this plugin's dialog too

    if (message==sim_message_eventcallback_menuitemselected)
    { // A custom menu bar entry was selected..
        if (auxiliaryData[0]==colladaDialog->dialogMenuItemHandle)
        {
            colladaDialog->makeVisible(!colladaDialog->getVisible()); // Toggle visibility of the dialog
        }
    }

    if (message==sim_message_eventcallback_colladaplugin)
    {
        if (auxiliaryData[0]==0)
            replyData[0]=PLUGIN_VERSION; // this is the version number of this plugin
        if (auxiliaryData[0]==1)
            replyData[0]=colladaDialog->importSingleGroupedShape((const char*)customData,(auxiliaryData[1]&1)!=0,float(auxiliaryData[2])/1000.0f);
    }

    if (message==sim_message_eventcallback_instancepass)
    { // It is important to always correctly react to events in CoppeliaSim. This message is the most convenient way to do so:
        colladaDialog->handleCommands();
        colladaDialog->setSimulationStopped(simGetSimulationState()==sim_simulation_stopped);

        int flags=auxiliaryData[0];
        bool sceneContentChanged=((flags&(1+2+4+8+16+32+64+256))!=0); // object erased, created, model or scene loaded, und/redo called, instance switched, or object scaled since last sim_message_eventcallback_instancepass message
        bool instanceSwitched=((flags&64)!=0);

        if (instanceSwitched)
        {
            // React to an instance switch here!!
        }

        if (sceneContentChanged)
        {
            refreshDlgFlag=true;
        }
    }
    if ((message==sim_message_eventcallback_guipass)&&refreshDlgFlag)
    { // handle refresh of the plugin's dialog:
        colladaDialog->refresh(); // Refresh the dialog
        refreshDlgFlag=false;
    }

    if (message==sim_message_eventcallback_simulationabouttostart)
    {
        colladaDialog->simulationAboutToStart();
    }
    if (message==sim_message_eventcallback_mainscriptabouttobecalled)
    {
        colladaDialog->mainScriptAboutToBeCalled();
    }
    if (message==sim_message_eventcallback_beforerendering)
    { // we are still in the main SIM thread!
        colladaDialog->renderingPassAboutToBeCalled();
    }
    if (message==sim_message_eventcallback_simulationended)
    {
        colladaDialog->simulationEnded();
    }

    // You can add many more messages to handle here

    // Keep following unchanged:
    simSetIntegerParameter(sim_intparam_error_report_mode,errorModeSaved); // restore previous settings
    return(retVal);
}

