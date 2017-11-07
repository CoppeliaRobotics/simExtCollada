#pragma once

#include "Transformation.h"
#include "vec3.h"

class Rotate : public Transformation
{
private:

    vec3 m_RotAxis;
    double m_RotAngle;              // Angle in degrees

public:

    Rotate();
    Rotate(const vec3& rotAxis,double angle);           // angle in degrees
    Rotate(double X,double Y, double Z, double angle);

    const vec3& getRotationAxis() const;
    double getRotationAngle() const;                // angle in degrees

    void setRoationAxis(const vec3& axis);
    void setRotationAngle(double rotAngle);         // angle in degrees

    virtual Transformation* clone() const;
};
