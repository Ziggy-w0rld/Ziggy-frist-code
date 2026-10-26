#include "CircleItem.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
const double PI = 3.14;
using namespace std;
CircleItem::CircleItem()
{
	m_r = rand() % 20 + 1;
}

void CircleItem::printTri() const
{
	cout << "Radius: m_r=" << m_r << endl;
}

bool CircleItem::isValid() const
{
	if (m_r > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

double CircleItem::calArea() const
{
	return PI * m_r * m_r;
}

double CircleItem::calPerimeter() const
{
	return 2.0 * PI * m_r;
}

