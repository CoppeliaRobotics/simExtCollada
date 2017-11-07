#pragma once

#include <vector>

class PPolygon
{
private:
    std::vector<int> m_VertexIndices;   
    std::vector<int> m_NormalIndices;
    
public:

    std::vector<int>& getVertexIndices();
    const std::vector<int>& getVertexIndices() const;
    std::vector<int>& getNormalIndices();
    const std::vector<int>& getNormalIndices() const;
};
