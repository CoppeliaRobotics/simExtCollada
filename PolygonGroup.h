#pragma once

#include <vector>
#include <string>
#include "vec3.h"
#include "Polygon.h"
class PolygonGroup
{
private:

    std::vector<PPolygon> m_Polygons;
    std::vector<vec3> m_Normals;
    std::string m_MaterialSymbol;

public:
    std::vector<vec3>& getNormals();
    const std::vector<vec3>& getNormals() const;
    std::string getMaterialSymbol() const;
    void setMaterialSymbol(const std::string& MaterialSymbol);

    std::vector<PPolygon>& getPolygons();
    const std::vector<PPolygon>& getPolygons() const;
};
