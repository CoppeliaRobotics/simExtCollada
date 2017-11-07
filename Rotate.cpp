#include "Rotate.h"

Rotate::Rotate() : Transformation(Transformation::Rotate)
{

}

Rotate::Rotate(const vec3& rotAxis,double angle) : Transformation(Transformation::Rotate)
{
    m_RotAxis = rotAxis;
    m_RotAngle = angle;
}

Rotate::Rotate(double X,double Y, double Z, double angle) : Transformation(Transformation::Rotate)
{
    m_RotAxis.set(X,Y,Z);
    m_RotAngle = angle;
}

const vec3& Rotate::getRotationAxis() const
{
    return m_RotAxis;
}

double Rotate::getRotationAngle() const
{
    return m_RotAngle;
}

void Rotate::setRoationAxis(const vec3& axis)
{
    m_RotAxis = axis;
}
void Rotate::setRotationAngle(double rotAngle)
{
    m_RotAngle = rotAngle;
}

Transformation* Rotate::clone() const
{
    return new Rotate(*this);
}
