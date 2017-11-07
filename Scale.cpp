#include "Scale.h"

Scale::Scale() : Transformation(Transformation::Scale)
{
    m_Scale.set(1,1,1);
}

Scale::Scale(const vec3& v) : Transformation(Transformation::Scale)
{
    m_Scale = v;
}

Scale::Scale(double X, double Y, double Z) : Transformation(Transformation::Scale)
{
    m_Scale.set(X,Y,Z);
}

const vec3& Scale::getScale() const
{
    return m_Scale;
}

void Scale::setScale(const vec3& v)
{
    m_Scale = v;
}

void Scale::setScale(double X, double Y, double Z)
{
    m_Scale.set(X,Y,Z);
}

Transformation* Scale::clone() const
{
    return new Scale(*this);
}

