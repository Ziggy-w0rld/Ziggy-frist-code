#pragma once
#include "ShapeItem.h"
class EllipseItem : public ShapeItem
{
protected:
    int m_a; // ≥§∞Î÷·
    int m_b; // ∂Ã∞Î÷·
public:
    EllipseItem();
    EllipseItem(int a, int b);
    void printTri() const override;
    bool isValid() const override;
    double calArea() const override;
    double calPerimeter() const override;
    int GetA() const { return m_a; }
    int GetB() const { return m_b; }
};

