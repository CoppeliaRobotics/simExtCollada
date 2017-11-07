#include "XMLHelper.h"

using namespace tinyxml2;

XMLElement *XMLHelper::GetChildElement(tinyxml2::XMLElement* rootNode,const std::string& childName,bool SearchAnyDepth)
{
    if(rootNode == NULL) {
        return NULL;
    }

    XMLElement* node = rootNode->FirstChildElement();

    while(node != NULL) {               
        if(std::string(node->Name()) == childName) {
            return node;
        }
        
        if((node->FirstChildElement() != NULL) && SearchAnyDepth) {
            XMLElement* result = GetChildElement(node,childName,SearchAnyDepth);
            if(result != NULL)
                return result;
        }
        node = node->NextSiblingElement();
    }
    return NULL;
}

XMLElement *XMLHelper::GetChildElement(tinyxml2::XMLElement* rootNode,const std::string& childName)
{
    return GetChildElement(rootNode,childName,false);
}


XMLElement *XMLHelper::GetChildElement(tinyxml2::XMLElement* rootNode, const std::string& attributeName,const std::string& attributeValue)
{
    if(rootNode == NULL) {
        return NULL;
    }

    XMLElement* node = rootNode->FirstChildElement();

    while(node != NULL) {   
        if(node->Attribute(attributeName.c_str()) != NULL) {
            if(std::string(node->Attribute(attributeName.c_str())) == attributeValue) {
                return node;
            }
        }
        
        if(node->FirstChildElement() != NULL) {
            XMLElement* result = GetChildElement(node,attributeName,attributeValue);
            if(result != NULL)
                return result;
        }
        node = node->NextSiblingElement();
    }
    return NULL;
}

XMLElement *XMLHelper::GetChildElement(tinyxml2::XMLElement* rootNode, const std::string& childName,const std::string& attributeName,const std::string& attributeValue)
{
    if(rootNode == NULL) {
        return NULL;
    }

    XMLElement* node = rootNode->FirstChildElement();

    while(node != NULL) {   
        if((std::string(node->Name()) == childName) && (node->Attribute(attributeName.c_str()) != NULL)) {
            if(std::string(node->Attribute(attributeName.c_str())) == attributeValue) {
                return node;
            }
        }
        
        if(node->FirstChildElement() != NULL) {
            XMLElement* result = GetChildElement(node,childName,attributeName,attributeValue);
            if(result != NULL)
                return result;
        }
        node = node->NextSiblingElement();
    }
    return NULL;
}

std::vector<tinyxml2::XMLElement*> XMLHelper::GetChildElements(tinyxml2::XMLElement* rootNode,const std::string& childName)
{
    std::vector<XMLElement*> elements;

    if(rootNode == NULL) {
        return elements;
    }

    XMLElement* node = rootNode->FirstChildElement();

    while(node != NULL) {               
        if(std::string(node->Name()) == childName) {
            elements.push_back(node);
        }
        node = node->NextSiblingElement();
    }
    return elements;
}

bool XMLHelper::GetElementAttribute(tinyxml2::XMLElement* node,const std::string attributeName,std::string& attributeValue)
{
    if(node == NULL)
        return false;
    if(node->Attribute(attributeName.c_str()) != NULL) {
        attributeValue = std::string(node->Attribute(attributeName.c_str()));
        return true;
    }
    else
        return false;
}
