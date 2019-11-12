#pragma once
#include "tinyxml2.h"
#include <string>
#include <vector>

class XMLHelper
{
private:
    XMLHelper () { };
public:

    static simExtCollada::tinyxml2::XMLElement *GetChildElement(simExtCollada::tinyxml2::XMLElement* rootNode,const std::string& childName);
    static simExtCollada::tinyxml2::XMLElement *GetChildElement(simExtCollada::tinyxml2::XMLElement* rootNode,const std::string& childName,bool SearchAnyDepth);
    static simExtCollada::tinyxml2::XMLElement *GetChildElement(simExtCollada::tinyxml2::XMLElement* rootNode,const std::string& childName,const std::string& attributeName,const std::string& attributeValue);
    static simExtCollada::tinyxml2::XMLElement *GetChildElement(simExtCollada::tinyxml2::XMLElement* rootNode,const std::string& attributeName,const std::string& attributeValue);
    static bool GetElementAttribute(simExtCollada::tinyxml2::XMLElement* node,const std::string attributeName,std::string& attributeValue);
    static std::vector<simExtCollada::tinyxml2::XMLElement*> GetChildElements(simExtCollada::tinyxml2::XMLElement* rootNode,const std::string& childName);
};
