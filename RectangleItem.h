#pragma once
#include "ShapeItem.h"
class RectangleItem : public ShapeItem
{
protected:
	int m_a;
	int m_b;
public:
	RectangleItem();
	RectangleItem(int a, int b);
	void printTri() const override;
	bool isValid() const override;
	double calArea() const override;
	double calPerimeter() const override;
	int GetA() const { return m_a; }
	int GetB() const { return m_b; }
};

