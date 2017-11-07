#pragma once
#include <math.h>

struct vec3
{
    double X,Y,Z;

    vec3() 
    {
        X = Y = Z = 0;
    }

    vec3(double X,double Y,double Z)
    {
        this->X = X; this->Y = Y; this->Z = Z;
    }


    void set(double X,double Y,double Z)
    {
        this->X = X; this->Y = Y; this->Z = Z;
    }

    void normalize()
    {
        double len = sqrt(X*X+Y*Y+Z*Z);
        if(len > 0) {
            X /= len;
            Y /= len;
            Z /= len;
        }
    }
};
