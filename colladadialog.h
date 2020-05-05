#ifndef COLLADADIALOG_H
#define COLLADADIALOG_H

#include <QDialog>
#include "COLLADAImporter.h"
#include "COLLADAExporter.h"

struct SSimulationThreadCommand
{
    int cmdId;
    std::vector<bool> boolParams;
    std::vector<int> intParams;
    std::vector<float> floatParams;
    std::vector<std::string> stringParams;
};

enum { MAKE_VISIBLE_CMD=0,
       IMPORT_CMD,
       EXPORT_CMD,
 };

namespace Ui {
    class CColladaDialog;
}

class CColladaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CColladaDialog(QWidget *parent = 0);
    ~CColladaDialog();

    static bool canOutputMsg(int msgType);
    static void outputMsg(int msgType,const char* msg);
    void refresh();

    void makeVisible(bool visible);
    bool getVisible();

    int dialogMenuItemHandle;

    void reject();

    int getVertices(const COLLADAImporter* importer,const mat4& parentMatrix,const SceneNode* node,std::vector<float>& vertices,int& nodeCount);
    bool addNodeToScene(const COLLADAImporter* importer,const mat4& parentMatrix,int parentObjectID,const SceneNode* node,float jointAndDummySizes,bool onlyShapes,std::vector<float>* _allVert,std::vector<int>* _allInd,float importScale);
    SceneNode* addObjectNodeForExport(int objectID,int parentObjectID);
    void addAllMeshesToExporter(COLLADAExporter* exp);

    void simulationAboutToStart();
    void mainScriptAboutToBeCalled();
    void renderingPassAboutToBeCalled();
    void simulationEnded();

    int importSingleGroupedShape(const char* pathAndFile,bool preserveColors,float scaling);

    void addCommand(SSimulationThreadCommand cmd);
    void handleCommands();
    void setSimulationStopped(bool stopped);

private:
    std::vector<SSimulationThreadCommand> _simulThreadCommands;

    float _importScaling;
    float _exportScaling;
    bool _mergeImported;
    bool _ungroupImported;
    bool _importMeshesOnly;
    bool _exportAnimation;
    bool _exportShapesOnly;
    bool _simulationStopped;

private slots:


    void on_qqMergeImport_clicked();

    void on_qqImportMeshesOnly_clicked();

    void on_qqImportScalingFactor_editingFinished();

    void on_qqImport_clicked();

    void on_qqExportAnimation_clicked();

    void on_qqExportShapesOnly_clicked();

    void on_qqExportScalingFactor_editingFinished();

    void on_qqExport_clicked();

    void on_qqImportUngroup_clicked();

private:
    Ui::CColladaDialog *ui;
};

#endif // COLLADADIALOG_H
