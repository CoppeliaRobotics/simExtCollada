#pragma once

#include <string>
#include <vector>
#include "Transformation.h"

class SceneNode
{
private:
    std::string m_MeshID;
    std::string m_Name; 
    std::vector<Transformation*> m_Transformations;
    std::vector<std::pair<std::string,std::string> > m_MaterialBindings;            // symbol to material id pairs
    std::vector<SceneNode> m_Children;
public:
    
    SceneNode();
    SceneNode(const SceneNode& scnode);

    ~SceneNode();
    bool containsMesh() const ;

    const std::string& getName() const;
    void setName(const std::string& Name);
    bool hasName() const;

    const std::string& getMeshID() const;
    void setMeshID(const std::string& MeshID);
    const std::vector<Transformation*>& getTransformations() const;
    void addTransformation(const Transformation& Transformation);
    
    const std::vector<std::pair<std::string,std::string> >& getMaterialBindings() const;
    std::vector<std::pair<std::string,std::string> >& getMaterialBindings();
    const std::vector<SceneNode>& getChildren() const;  
    std::vector<SceneNode>& getChildren();

    
};
