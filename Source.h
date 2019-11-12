#pragma once

#include <vector>
#include <boost/unordered_map.hpp>
#include "tinyxml2.h"
class Source
{
private:
    std::string m_ID;
    std::vector<float> m_ArrayValues;   
    int m_UnitCount;
public:

    Source();

    const std::string& getID() const;
    void setID(const std::string& ID);

    const std::vector<float>& getArrayValues() const;
    std::vector<float>& getArrayValues();

    int getUnitCount() const;
    void setUnitCount(int Count);

    bool parseXML(simExtCollada::tinyxml2::XMLElement *sourceNode,boost::unordered_map<std::string, std::vector<float> >& floatarrays);
};
