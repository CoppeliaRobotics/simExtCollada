#pragma once

#include "Transformation.h"
#include "mat4.h"

class Matrix : public Transformation
{
private:
    mat4 m_Matrix;

public:

    Matrix();
    Matrix(const mat4& mat);

    const mat4& getMatrix() const;
    mat4& getMatrix();

    void setMatrix(const mat4& mat);

    virtual Transformation* clone() const;
};
