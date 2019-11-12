#pragma once

#include "Mesh.h"
#include <string>
#include <vector>
#include <boost/unordered_map.hpp>
#include "tinyxml2.h"
#include "Material.h"
#include "SceneNode.h"
#include "VisualScene.h"
#include "Matrix.h"
#include "Translate.h"
#include "Scale.h"
#include "Rotate.h"

class COLLADAImporter
{
private:
    std::vector<Mesh> m_Meshes;
    boost::unordered_map<std::string,Material> m_Materials;
    std::vector<VisualScene> m_VisualScenes;
    std::string m_PrimarySceneID;

    Matrix LoadXMLMatrix(simExtCollada::tinyxml2::XMLElement* matrix);
    Translate LoadXMLTranslation(simExtCollada::tinyxml2::XMLElement* translation);
    Rotate LoadXMLRotation(simExtCollada::tinyxml2::XMLElement* rotation);
    Scale  LoadXMLScale(simExtCollada::tinyxml2::XMLElement* scale);
    bool LoadGeometry(simExtCollada::tinyxml2::XMLElement* geometryNode,boost::unordered_map <std::string, std::vector<float> >& floatarrays);
    bool LoadMaterial(simExtCollada::tinyxml2::XMLElement* colladaRootNode,const std::string& id); 
    void LoadScene(simExtCollada::tinyxml2::XMLElement* sceneNode);
    void visitNode(simExtCollada::tinyxml2::XMLElement* node,SceneNode* parentNode,std::vector<SceneNode>& rootScene);
    void LoadFloatArrays(simExtCollada::tinyxml2::XMLElement *geometryNode, boost::unordered_map<std::string, std::vector<float> >& map);
public:
    bool  LoadFile(const std::string& filename);
    const std::vector<Mesh>& getMeshes() const; 
    const boost::unordered_map<std::string,Material>& getMaterials() const;
    const std::vector<VisualScene>& getVisualScenes() const;
    const std::string& getPrimarySceneID() const;
};
