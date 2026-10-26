#include "TrapezoidItem.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

TrapezoidItem::TrapezoidItem()
{
    m_top = rand() % 10 + 1;            // 上底 1~10
    m_bottom = m_top + rand() % 10 + 1; // 下底比上底大，保证构成梯形
    m_h = rand() % 20 + 1;              // 高 1~20
}

TrapezoidItem::TrapezoidItem(int top, int bottom, int h)
{
    m_top = top; 
    m_bottom = bottom; 
    m_h = h;
}

void TrapezoidItem::printTri() const
{
    cout << "Trapezoid: top=" << m_top << ", bottom=" << m_bottom << ", h=" << m_h << endl;
}

bool TrapezoidItem::isValid() const
{
    return m_top > 0 && m_bottom > 0 && m_h > 0 && m_top != m_bottom;
}

double TrapezoidItem::calArea() const
{
    return (m_top + m_bottom) * m_h / 2.0;   // (上底+下底)×高÷2
}

double TrapezoidItem::calPerimeter() const
{
    double diff = (m_bottom - m_top) / 2.0;          // 等腰梯形单侧水平差
    double leg = sqrt(m_h * m_h + diff * diff);      // 腰长 = √(h²+diff²)
    return m_top + m_bottom + 2.0 * leg;             // 周长 = 上底+下底+两腰
}
