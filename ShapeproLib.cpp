#include "ShapeproLib.h"
#include<iostream>
#include<random>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
ShapeproLib::ShapeproLib(int num) : m_libname("简单几何题库"), m_tatalscore(0), m_averagescore(0.0)
{
	for (int i = 0; i < num; ++i) {
		m_items.push_back(randomShop());    // 每道题随机一种图形
	}
}

ShapeproLib::~ShapeproLib()
{
	for (size_t i = 0; i < m_items.size(); ++i) {
		delete m_items[i];
	}
}



ShapeItem* ShapeproLib::randomShop()
{
	int shapeType = rand() % 5;
	switch (shapeType) {
	case 0:
		return new TriangleItem();
	case 1:
		return new RectangleItem();
	case 2:
		return new CircleItem();
	case 3:
		return new TrapezoidItem();
	case 4:
		return new EllipseItem();
	default:
		return nullptr; // Should never reach here
	}

}

void ShapeproLib::showallpro() const
{
	for (size_t i = 0; i < m_items.size(); ++i) {
		cout << "第 " << i + 1 << " 题：";
		m_items[i]->printTri();     // 虚函数：自动输出实际图形的信息
		cout << '\n';
	}
}

void ShapeproLib::showanswers() const
{
	for (size_t i = 0; i < m_items.size(); ++i) {
		cout << "第 " << i + 1 << " 题：";
		m_items[i]->printTri();
		cout << "，面积 = " << m_items[i]->calArea()
			<< "，周长 = " << m_items[i]->calPerimeter() << '\n';
	}
}

void ShapeproLib::testallpro()
{
	m_tatalscore = 0;
	for (size_t i = 0; i < m_items.size(); ++i) {
		cout << "\n第 " << i + 1 << " 题：";
		m_items[i]->printTri();
		cout << '\n';
		int score = m_items[i]->flow();  // flow 在基类实现，内部虚函数分派
		m_tatalscore += score;
		if(score == 0) {
			m_wronglib.addWrong(m_items[i]); // 将错题加入错题库
		}
	}
	m_averagescore = m_tatalscore / m_items.size();
}

void ShapeproLib::showscore() const
{
	cout << "\n总分为：" << m_tatalscore << '\n';
	cout << "平均分为：" << m_averagescore << '\n';
}

WrongLib& ShapeproLib::GetWrongLib()
{
	return m_wronglib;
}
