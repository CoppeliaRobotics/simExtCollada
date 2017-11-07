#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include "vec3.h"
#include "mat4.h"

class StringHelper
{
private:
    StringHelper() { };

    static std::vector<std::string> split(const std::string &str, const std::vector<char>& delim);
    static bool contains_char(const std::vector<char>& v,char c);
public:
    //static std::vector<float> ConvertStringToFloatArray(const std::string& string);
    template <class T> 
/*  static std::vector<T> ConvertStringToTArray(const std::string& string)
    {
        std::vector<char> delims;
        delims.push_back(' ');
        delims.push_back('\n');
        delims.push_back('\r');
        std::vector<std::string> sarray = split(string,delims);
        std::vector<T> tarray;
        for(std::vector<std::string>::iterator it = sarray.begin();it != sarray.end(); it++) {
            if((*it).length() > 0) {
                T f;
                if(from_string<T>(f,*it)) {
                    tarray.push_back(f);
                }
                else
                    throw 1;
            }
        }
        return tarray;
    }*/

    static std::vector<T> ConvertStringToTArray(const std::string& string)
    {
        std::vector<char> delims;
        delims.push_back(' ');
        delims.push_back('\n');
        delims.push_back('\r');
        delims.push_back('\t');
        std::vector<T> tarray;
        std::string str="";
        int slen = string.length();
        for(int i=0;i<slen;i++)
        {
            char c = string[i];
            if(contains_char(delims,c))
            {
                if(str.length()>0)
                {
                    T f;
                    if(from_string<T>(f,str))
                    {
                        tarray.push_back(f);
                        str = "";
                    }
                    else
                    {
                        std::stringstream ss;
                        ss << "COLLADA import error: the following string cannot be parsed as array element: '";
                        ss << str << "', with ASCII codes ";
                        for (int j=0; j<str.length(); j++)
                            ss << (int)str[j] << " ";
                        throw std::runtime_error(ss.str());
                    }
                }
            }
            else
                str += c;
        }
        if(str.length()>0)
        {
            T f;
            if(from_string<T>(f,str))
            {
                tarray.push_back(f);
                str = "";
            }
            else
            {
                std::stringstream ss;
                ss << "COLLADA import error: the following string cannot be parsed as array element: '";
                ss << str << "', with ASCII codes ";
                for (int j=0; j<str.length(); j++)
                    ss << (int)str[j] << " ";
                throw std::runtime_error(ss.str());
            }
        }

        return tarray;
    }


    template <class T>
    static bool from_string(T& t, 
                        const std::string& s)
    {
        std::istringstream iss(s);
        return !(iss >> std::dec >> t).fail();
    }

    template <class T> 
        static std::string to_string(const T& t) {
        std::ostringstream os; os<<t; return os.str(); 
    }

    static std::string ConvertVec3ArrayToString(const std::vector<vec3>& values);
    static std::string ConvertVec3ToString(const vec3& vec);
    static std::string ConvertMat4ToString(const mat4& mat);
};
