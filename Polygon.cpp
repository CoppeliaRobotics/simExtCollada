#include "Polygon.h"

std::vector<int>& PPolygon::getNormalIndices()
{
    return m_NormalIndices;
}

const std::vector<int>& PPolygon::getNormalIndices() const
{
    return m_NormalIndices;
}

std::vector<int>& PPolygon::getVertexIndices()
{
    return m_VertexIndices;
}

const std::vector<int>& PPolygon::getVertexIndices() const
{
    return m_VertexIndices;
}
