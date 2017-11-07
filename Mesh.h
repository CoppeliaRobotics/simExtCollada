#pragma once

#include <vector>
#include "vec3.h"
#include "TriangleGroup.h"
#include "PolygonGroup.h"

class Mesh
{
private:
    std::string m_Name;
    std::string m_ID;
    std::vector<vec3> m_Vertices;
    std::vector<TriangleGroup> m_TriangleGroups;
    std::vector<PolygonGroup> m_PolygonGroups;  
public: 
    const std::string& getName() const;
    const std::string& getID() const;
    void  setID(const std::string& ID);
    void  setName(const std::string &Name);
    bool  hasName() const;
    std::vector<TriangleGroup>& getTriangleGroups();
    const std::vector<TriangleGroup>& getTriangleGroups() const;

    std::vector<PolygonGroup>& getPolygonGroups();
    const std::vector<PolygonGroup>& getPolygonGroups() const;

    std::vector<vec3>& getVertices();
    const std::vector<vec3>& getVertices() const;
};
