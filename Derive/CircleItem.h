#pragma once
#include"ShapeItem.h"
class CircleItem : public ShapeItem
{
protected:
	int m_r;
public:
	CircleItem();
	explicit CircleItem(int r) : m_r(r) {}
	void printTri() const override;
	bool isValid() const override;
	double calArea() const override;
	double calPerimeter() const override;
	int GetR() const { return m_r; }
};

