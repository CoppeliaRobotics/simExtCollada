#include "Translate.h"

Translate::Translate() : Transformation(Transformation::Translate)
{

}

Translate::Translate(const vec3& v) : Transformation(Transformation::Translate)
{
    m_Translation = v;
}

Translate::Translate(double X, double Y, double Z) : Transformation(Transformation::Translate)
{
    m_Translation.set(X,Y,Z);
}

const vec3& Translate::getTranslation() const
{
    return m_Translation;
}

void Translate::setTranslation(const vec3& v)
{
    m_Translation = v;
}

void Translate::setTranslation(double X, double Y, double Z)
{
    m_Translation.set(X,Y,Z);
}


Transformation* Translate::clone() const
{
    return new Translate(*this);
}
