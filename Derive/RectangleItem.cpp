#include "RectangleItem.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
RectangleItem::RectangleItem()
{
	m_a = rand() % 20 + 1;
	m_b = rand() % 20 + 1;
}
RectangleItem::RectangleItem(int a, int b)
{
	m_a = a;
	m_b = b;
}
void RectangleItem::printTri()const
{
	cout << "Rectangle sides: m_a=" << m_a << ", m_b=" << m_b << endl;
}

bool RectangleItem::isValid()const
{
	if (m_a > 0 || m_b > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

double RectangleItem::calArea()const
{
	return m_a * m_b;
}

double RectangleItem::calPerimeter()const
{
	return (m_a + m_b) * 2.0;
}