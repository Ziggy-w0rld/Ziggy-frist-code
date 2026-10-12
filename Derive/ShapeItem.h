#pragma once
class ShapeItem
{
protected:
	double m_uarea;
	double m_uperimeter;
	int m_score;
public:
	ShapeItem();
	virtual void printTri() const = 0;
	virtual bool isValid() const = 0;//判断数据是否合法
	virtual double calArea() const = 0;
	virtual double calPerimeter() const = 0;
	int flow();
	virtual int GetScore() const
	{
		return m_score;
	}
};
