#pragma once

#include "Transformation.h"
#include "vec3.h"

class Scale : public Transformation
{
private:

    vec3 m_Scale;

public:

    Scale();
    Scale(const vec3& v);
    Scale(double X,double Y, double Z);

    const vec3& getScale() const;

    void setScale(const vec3& v);
    void setScale(double X,double Y,double Z);

    virtual Transformation* clone() const;
};
