#include "PolygonGroup.h"

std::string PolygonGroup::getMaterialSymbol() const
{
    return m_MaterialSymbol;
}

void PolygonGroup::setMaterialSymbol(const std::string& MaterialSymbol)
{
    m_MaterialSymbol = MaterialSymbol;
}

std::vector<vec3>& PolygonGroup::getNormals()
{
    return m_Normals;
}

const std::vector<vec3>& PolygonGroup::getNormals() const
{
    return m_Normals;
}
 
std::vector<PPolygon>& PolygonGroup::getPolygons()
{
    return m_Polygons;
}

const std::vector<PPolygon>& PolygonGroup::getPolygons() const
{
    return m_Polygons;
}
