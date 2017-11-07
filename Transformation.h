#pragma once

class Transformation
{
public:
    enum TransformationType
    {
        Matrix,
        Translate,
        Rotate,
        Scale
    };

private:

    TransformationType m_TransformationType;

public:

    virtual ~Transformation() { };
    TransformationType getTransformationType() const { return m_TransformationType; }
    virtual Transformation* clone() const = 0;          // use delete for desctruction

protected:

    Transformation(TransformationType Type)
    {
        m_TransformationType = Type;
    }

private:
    // Disable default assignment operator.
    const Transformation& operator=(const Transformation& trans) { return *this; };

};
