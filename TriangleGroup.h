#pragma once

#include <vector>
#include <string>
#include "vec3.h"
class TriangleGroup
{
private:    
    
    std::vector<vec3> m_Normals;
    std::vector<int> m_TriangleIndices; 
    std::vector<int> m_NormalIndices;
    std::string m_MaterialSymbol;
public: 
    std::vector<int>& getTriangleIndices();
    const std::vector<int>& getTriangleIndices() const;
    std::vector<vec3>& getNormals();
    const std::vector<vec3>& getNormals() const;
    std::vector<int>& getNormalIndices();
    const std::vector<int>& getNormalIndices() const;
    std::string getMaterialSymbol() const;
    void setMaterialSymbol(const std::string& MaterialSymbol);
};
