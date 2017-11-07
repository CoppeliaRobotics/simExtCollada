#include "TriangleGroup.h"

std::vector<int>& TriangleGroup::getTriangleIndices() 
{
    return m_TriangleIndices;
}

const std::vector<int>& TriangleGroup::getTriangleIndices() const
{
    return m_TriangleIndices;
}

std::vector<vec3>& TriangleGroup::getNormals()
{
    return m_Normals;
}

const std::vector<vec3>& TriangleGroup::getNormals() const
{
    return m_Normals;
}

std::vector<int>& TriangleGroup::getNormalIndices() 
{
    return m_NormalIndices;
}

const std::vector<int>& TriangleGroup::getNormalIndices() const
{
    return m_NormalIndices;
}

std::string TriangleGroup::getMaterialSymbol() const
{
    return m_MaterialSymbol;
}

void TriangleGroup::setMaterialSymbol(const std::string& MaterialSymbol)
{
    m_MaterialSymbol = MaterialSymbol;
}
