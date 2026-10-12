#include "TriangleItem.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
TriangleItem::TriangleItem()
{
	m_a = rand() % 20 + 1;
	m_b = rand() % 20 + 1;
	m_c = rand() % (m_a + m_b - 1) + 1;;
}
TriangleItem::TriangleItem(int a, int b, int c)
{
	m_a = a;
	m_b = b;
	m_c = c;
}
void TriangleItem::printTri()const
{
	cout << "Triangle sides: m_a=" << m_a << ", m_b=" << m_b << ", m_c=" << m_c << endl;
}

bool TriangleItem::isValid()const
{
	if (m_a + m_b > m_c && m_a + m_c > m_b && m_b + m_c > m_a)
	{
		return true;
	}
	else
	{
		return false;
	}
}

double TriangleItem::calArea()const
{
	double p = (m_a + m_b + m_c) / 2.0;
	return sqrt(p * (p - m_a) * (p - m_b) * (p - m_c));
}

double TriangleItem::calPerimeter()const
{
	return m_a + m_b + m_c;
}
