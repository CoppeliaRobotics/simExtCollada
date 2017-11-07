#pragma once

#include <vector>
#include "SceneNode.h"

class VisualScene
{
private:
    std::vector<SceneNode> m_SceneNodes;
    std::string m_SceneID;
    std::string m_Name;
public:
    
    std::vector<SceneNode>& getSceneNodes();
    const std::vector<SceneNode>& getSceneNodes() const;
    const std::string& getName() const;
    void setName(const std::string& Name);
    bool hasName() const;
    const std::string& getSceneID() const;
    void setSceneID(const std::string& SceneID);
};
