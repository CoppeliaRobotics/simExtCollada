#include "Matrix.h"

Matrix::Matrix() : Transformation(Transformation::Matrix)
{

}

Matrix::Matrix(const mat4& mat) : Transformation(Transformation::Matrix)
{
    m_Matrix = mat;
}


const mat4& Matrix::getMatrix() const
{
    return m_Matrix;
}

mat4& Matrix::getMatrix()
{
    return m_Matrix;
}

void Matrix::setMatrix(const mat4& mat)
{
    m_Matrix = mat;
}

Transformation * Matrix::clone() const
{
    return new Matrix(*this);
}
