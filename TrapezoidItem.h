#pragma once
#include "ShapeItem.h"
class TrapezoidItem : public ShapeItem
{
protected:
    int m_top;    // 上底
    int m_bottom; // 下底
    int m_h;      // 高
public:
    TrapezoidItem();                // 随机生成等腰梯形
    TrapezoidItem(int top, int bottom, int h);
    void printTri() const override;
    bool isValid() const override;
    double calArea() const override;
    double calPerimeter() const override;
    int GetTop() const { return m_top; }
    int GetBottom() const { return m_bottom; }
    int GetHigh() const { return m_h; }
};

