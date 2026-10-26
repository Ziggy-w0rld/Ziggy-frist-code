#include "EllipseItem.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
const double PI = 3.14;
using namespace std;

EllipseItem::EllipseItem()
{
    m_a = rand() % 15 + 5;  // 长半轴 5~19
    m_b = rand() % 10 + 1;  // 短半轴 1~10
}

EllipseItem::EllipseItem(int a, int b)
{
    m_a = a; 
    m_b = b;
}

void EllipseItem::printTri() const
{
    cout << "Ellipse: a=" << m_a << ", b=" << m_b << endl;
}

bool EllipseItem::isValid() const
{
    return m_a > 0 && m_b > 0 && m_a >= m_b;   // 长半轴 ≥ 短半轴
}

double EllipseItem::calArea() const
{
    return PI * m_a * m_b;                     // 面积 = πab
}

double EllipseItem::calPerimeter() const
{
    // 周长用拉马努金近似公式，无初等精确公式
    return PI * (3.0 * (m_a + m_b) - sqrt((3.0 * m_a + m_b) * (m_a + 3.0 * m_b)));
}
