#include "WrongLib.h"
#include<iostream>
#include<fstream>
#include "TriangleItem.h"
#include "RectangleItem.h"
#include "CircleItem.h"
#include "TrapezoidItem.h"
#include "EllipseItem.h"
using namespace std;
WrongLib::WrongLib()
{
}

WrongLib::~WrongLib()
{
	//释放错题对象,防止内存泄漏
	for(auto p : m_wrong)
	{
		delete p;
	}
	m_wrong.clear();
}

void WrongLib::addWrong(ShapeItem* item)
{
	if (item == nullptr)
		return;

	// 不直接保存原指针！新建副本，错题库拥有独立对象
	ShapeItem* newItem = nullptr;
	if (TriangleItem* p = dynamic_cast<TriangleItem*>(item))
	{
		newItem = new TriangleItem(*p); // 拷贝构造
	}
	else if (RectangleItem* p = dynamic_cast<RectangleItem*>(item))
	{
		newItem = new RectangleItem(*p);
	}
	else if (CircleItem* p = dynamic_cast<CircleItem*>(item))
	{
		newItem = new CircleItem(*p);
	}
	else if (TrapezoidItem* p = dynamic_cast<TrapezoidItem*>(item))
	{
		newItem = new TrapezoidItem(*p);
	}
	else if (EllipseItem* p = dynamic_cast<EllipseItem*>(item))
	{
		newItem = new EllipseItem(*p);
	}

	if (newItem != nullptr)
	{
		m_wrong.push_back(newItem);
		cout << "已加入错题库共" << m_wrong.size() << "道" << endl;
	}
}

void WrongLib::showWrong() const
{
	if (m_wrong.empty()) {
		cout << "错题库为空。\n";
		return;
	}
	for (size_t i = 0; i < m_wrong.size(); ++i) {
		cout << "第 " << i + 1 << " 道错题：";
		m_wrong[i]->printTri();
		cout << "，面积 = " << m_wrong[i]->calArea()
			<< "，周长 = " << m_wrong[i]->calPerimeter() << '\n';
	}
}

void WrongLib::testWrong() const
{
	if (m_wrong.empty()) {
		cout << "错题库为空。\n";
		return;
	}
	for (size_t i = 0; i < m_wrong.size(); ++i) {
		cout << "第 " << i + 1 << " 道错题：";
		m_wrong[i]->printTri();
		int score = m_wrong[i]->flow();
		cout << "，得分 = " << score << '\n';
	}
}
//将错题库保存到文件
void WrongLib::saveToFile(const string& fileName) const
{
	ofstream ofs(fileName);
	if (!ofs.is_open()) 
	{
		cout << "无法打开文件 " << fileName << " 进行保存。\n";
		return;
	}
	for (auto item : m_wrong)
	{
		if (TriangleItem* p = dynamic_cast<TriangleItem*>(item))
		{
			ofs << "Triangle " << p->GetA() << " " << p->GetB() << " " << p->GetC() << endl;
		}
		else if (RectangleItem* p = dynamic_cast<RectangleItem*>(item))
		{
			ofs << "Rectangle " << p->GetA() << " " << p->GetB() << endl;
		}
		else if (CircleItem* p = dynamic_cast<CircleItem*>(item))
		{
			ofs << "Circle " << p->GetR() << endl;
		}
		else if (TrapezoidItem* p = dynamic_cast<TrapezoidItem*>(item))
		{
			ofs << "Trapezoid " << p->GetTop() << " " << p->GetBottom() << " " << p->GetHigh() << endl;
		}
		else if (EllipseItem* p = dynamic_cast<EllipseItem*>(item))
		{
			ofs << "Ellipse " << p->GetA() << " " << p->GetB() << endl;
		}
	}
	ofs.close();
	cout << "错题已经保存到 " << fileName << endl;
}

void WrongLib::loadFromFile(const string& fileName)
{
	ifstream ifs(fileName);
	if (!ifs.is_open()) 
	{
		cout << "无法打开文件 " << fileName << " 进行加载。\n";
		return;
	}
	//清空当前错题库
	for (auto p : m_wrong)
	{
		delete p;
	}
	m_wrong.clear();
	string shapeType;
	while (ifs >> shapeType) 
	{
		if (shapeType == "Triangle") 
		{
			int a, b, c;
			ifs >> a >> b >> c;
			m_wrong.push_back(new TriangleItem(a, b, c));
		} 
		else if (shapeType == "Rectangle") 
		{
			int a, b;
			ifs >> a >> b;
			m_wrong.push_back(new RectangleItem(a, b));
		} 
		else if (shapeType == "Circle") 
		{
			int r;
			ifs >> r;
			m_wrong.push_back(new CircleItem(r));
		} 
		else if (shapeType == "Trapezoid") 
		{
			int top, bottom, h;
			ifs >> top >> bottom >> h;
			m_wrong.push_back(new TrapezoidItem(top, bottom, h));
		} 
		else if (shapeType == "Ellipse") 
		{
			int a, b;
			ifs >> a >> b;
			m_wrong.push_back(new EllipseItem(a, b));
		}
	}
	ifs.close();
	cout << "从文件加载错题，共 " << m_wrong.size() << " 道" << endl;
}
