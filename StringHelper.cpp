#include "StringHelper.h"
#include <sstream>

bool StringHelper::contains_char(const std::vector<char>& v,char c)
{
    for(std::vector<char>::const_iterator it = v.begin(); it != v.end(); it++) {
        if((*it) == c)
            return true;
    }
    return false;
}

std::vector<std::string> StringHelper::split(const std::string &str, const std::vector<char>& delim)
{
    std::vector<std::string> elems;
    int len = str.length();
    std::string s = ""; 
    for(int i=0;i<len;i++) {
        if(contains_char(delim,str[i])) {
            elems.push_back(s);
            s = "";
        }
        else {
            s.push_back(str[i]);
        }
    }
    if(s!="")
        elems.push_back(s);
    return elems;
}
/*
std::vector<float> StringHelper::ConvertStringToFloatArray(const std::string& string)
{   
    std::vector<char> delims;
    delims.push_back(' ');
    delims.push_back('\n');
    std::vector<std::string> sfloats = split(string,delims);
    std::vector<float> floats;
    for(std::vector<std::string>::iterator it = sfloats.begin();it != sfloats.end(); it++) {
        float f;
        if(from_string<float>(f,*it)) {
            floats.push_back(f);
        }
        else
            throw 1;
    }
    return floats;
}*/

std::string StringHelper::ConvertVec3ArrayToString(const std::vector<vec3>& values)
{
    std::string str;    
    for(std::vector<vec3>::const_iterator it = values.begin(); it!=values.end(); it++) {
        str += to_string((*it).X) + " " + to_string((*it).Y) + " " + to_string((*it).Z) + " ";      
    }
    return str;
}

std::string StringHelper::ConvertVec3ToString(const vec3& vec)
{
    return to_string(vec.X) + " " + to_string(vec.Y) + " " + to_string(vec.Z);
}

std::string StringHelper::ConvertMat4ToString(const mat4& mat)
{
    std::string str;
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            str += to_string(mat(i,j));
            if(j!=3) str += " ";
        }
        if(i != 3)
            str += " ";
    }
    return str;
}
