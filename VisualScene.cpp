#include "VisualScene.h"

const std::string& VisualScene::getSceneID() const
{
    return m_SceneID;
}

void VisualScene::setSceneID(const std::string& SceneID)
{
    m_SceneID = SceneID;
}

const std::string& VisualScene::getName() const
{
    return m_Name;
}

void VisualScene::setName(const std::string& Name)
{
    m_Name = Name;
}

bool VisualScene::hasName() const
{
    return m_Name.length()>0;
}

std::vector<SceneNode>& VisualScene::getSceneNodes()
{
    return m_SceneNodes;
}

const std::vector<SceneNode>& VisualScene::getSceneNodes() const
{
    return m_SceneNodes;
}
