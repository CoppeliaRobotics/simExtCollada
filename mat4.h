#pragma once
#include "vec3.h"

class mat4
{
private:
    double m_Mat[4][4];
public:
    mat4();
    mat4 operator*(const mat4& other) const;
    mat4& operator*=(const mat4& other);
    double& operator()(int row,int col);
    const double& operator()(int row,int col) const;

    static mat4 IdentityMatrix();
    static mat4 TranslationMatrix(const vec3& t);
    static mat4 RotationMatrix(vec3 axis,double angle);     // angle in degrees
    static mat4 ScaleMatrix(const vec3& s);
};
