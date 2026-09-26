#include "TriangleItem.h"
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
TriangleItem::TriangleItem()
{
	srand((unsigned)time(NULL));
	m_a = rand() % 20 + 1;
	m_b = rand() % 20 + 1;
	m_c = rand() % 20 + 1;
}
void TriangleItem::printTri()const
{
	cout << "Triangle sides: m_a=" << m_a << ", m_b=" << m_b << ", m_c=" << m_c << endl;
}

bool TriangleItem::isTriangle()const
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

int TriangleItem::calPerimeter()const
{
	return m_a + m_b + m_c;
}

int TriangleItem::flow()
{
	if (!isTriangle()) {
		cout << "The sides do not form a triangle." << endl;
		m_score = 0;
		return m_score;
	} 
	cout << "请你计算三角形的面积和周长" << endl;
	cin >> m_uarea >> m_uperimeter;
	if(m_uarea == calArea() && m_uperimeter == calPerimeter())
	{
		m_score = 1;
	}
	else
	{
		m_score = 0;
	}
	return m_score;
}


