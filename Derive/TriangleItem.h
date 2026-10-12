#pragma once
#include "ShapeItem.h"
class TriangleItem : public ShapeItem
{
protected:
	int m_a;
	int m_b;
	int m_c;
public:
	TriangleItem();//随机生成三条边
	TriangleItem(int a, int b, int c);//固定数据/测试
	void printTri() const override;
	bool isValid() const override;
	double calArea() const override;
	double calPerimeter() const override;
	int GetA() const { return m_a; }
	int GetB() const { return m_b; }
	int GetC() const { return m_c; }
};


