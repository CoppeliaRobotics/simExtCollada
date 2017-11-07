#pragma once
#include "tinyxml2.h"
#include <string>
#include <vector>

class XMLHelper
{
private:
    XMLHelper () { };
public:

    static tinyxml2::XMLElement *GetChildElement(tinyxml2::XMLElement* rootNode,const std::string& childName);
    static tinyxml2::XMLElement *GetChildElement(tinyxml2::XMLElement* rootNode,const std::string& childName,bool SearchAnyDepth);
    static tinyxml2::XMLElement *GetChildElement(tinyxml2::XMLElement* rootNode,const std::string& childName,const std::string& attributeName,const std::string& attributeValue);
    static tinyxml2::XMLElement *GetChildElement(tinyxml2::XMLElement* rootNode,const std::string& attributeName,const std::string& attributeValue);
    static bool GetElementAttribute(tinyxml2::XMLElement* node,const std::string attributeName,std::string& attributeValue);
    static std::vector<tinyxml2::XMLElement*> GetChildElements(tinyxml2::XMLElement* rootNode,const std::string& childName);
};
