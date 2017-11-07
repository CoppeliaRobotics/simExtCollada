#include "Mesh.h"

const std::string& Mesh::getID() const
{
    return m_ID;
}

void Mesh::setID(const std::string& ID)
{
    m_ID = ID;
}

std::vector<TriangleGroup>& Mesh::getTriangleGroups()
{
    return m_TriangleGroups;
}
const std::vector<TriangleGroup>& Mesh::getTriangleGroups() const
{
    return m_TriangleGroups;
}

std::vector<vec3>& Mesh::getVertices()
{
    return m_Vertices;
}

const std::vector<vec3>& Mesh::getVertices() const
{
    return m_Vertices;
}

const std::string& Mesh::getName() const
{
    return m_Name;
}

void Mesh::setName(const std::string& Name)
{
    m_Name = Name;
}

bool Mesh::hasName() const
{
    return m_Name.length()>0;
}

std::vector<PolygonGroup>& Mesh::getPolygonGroups()
{
    return m_PolygonGroups;
}

const std::vector<PolygonGroup>& Mesh::getPolygonGroups() const
{
    return m_PolygonGroups;
}
