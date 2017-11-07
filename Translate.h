#pragma once

#include "Transformation.h"
#include "vec3.h"
class Translate : public Transformation
{
private:

    vec3 m_Translation;

public:

    Translate();
    Translate(const vec3& v);
    Translate(double X,double Y, double Z);

    const vec3& getTranslation() const;

    void setTranslation(const vec3& v);
    void setTranslation(double X,double Y,double Z);

    virtual Transformation* clone() const;
};
