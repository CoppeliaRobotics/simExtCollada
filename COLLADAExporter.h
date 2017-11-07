#pragma once

#include "Mesh.h"
#include <string>
#include <vector>
#include <boost/unordered_map.hpp>
#include "Material.h"
#include "SceneNode.h"
#include "VisualScene.h"
#include "mat4.h"
#include "tinyxml2.h"

class COLLADAExporter
{
private:
    
    int m_NextPosSourceID;
    int m_NextNormalSourceID;
    int m_NextGeometryID;
    int m_NextNodeID;

    std::vector<Mesh> m_Meshes;
    std::vector<std::pair<std::string,Material> > m_Materials;
    std::vector<VisualScene> m_VisualScenes;

    std::string m_PrimarySceneID;

    void SaveSceneNode(tinyxml2::XMLElement* parentNode,const SceneNode& scene);
    void SaveSceneNodes(tinyxml2::XMLElement* rootNode);
    void SaveMaterials(tinyxml2::XMLElement *rootNode);
    void SaveSource(tinyxml2::XMLElement* parentNode,const std::vector<vec3>& values,const std::string& sourceid,const std::string& sourcename);
    bool SaveGeometry(tinyxml2::XMLElement* geometriesNode,const Mesh& mesh);

public: 

    bool  SaveFile(const std::string& filename);
    const std::vector<Mesh>& getMeshes() const; 
    std::vector<Mesh>& getMeshes();

    const std::vector<std::pair<std::string,Material> >& getMaterials() const;
    std::vector<std::pair<std::string,Material> >& getMaterials();

    const std::vector<VisualScene>& getVisualScenes() const;
    std::vector<VisualScene>& getVisualScenes();

    const std::string& getPrimarySceneID() const;
    void setPrimarySceneID(const std::string& PrimarySceneID);
};
