#include "ShapeproLib.h"
using namespace std;
ShapeproLib::ShapeproLib()
{
	m_num = 20;
	m_tatalscore = 0;
	m_averagescore = 0;
}

void ShapeproLib::showallpro()const
{
	for(int i=0; i < m_num; i++)
	{
		cout << "第 " << i + 1 << " 题：";
		m_itemarray[i].printTri();
		cout << '\n';
	}
}

void ShapeproLib::showanswers() const
{
	for (int i = 0; i < m_num; i++)
	{
		cout << "第 " << i + 1 << " 题：";
		m_itemarray[i].printTri();
		cout << "，面积 = " << m_itemarray[i].calArea()
			<< "，周长 = " << m_itemarray[i].calPerimeter() << '\n';
	}
}

void ShapeproLib::testallpro()
{
	for(int i=0; i < m_num; i++)
	{
		cout << "\n第 " << i + 1 << " 题：";
		m_itemarray[i].printTri();
		cout << '\n';
		m_tatalscore += m_itemarray[i].flow();
	}
	 m_averagescore = m_tatalscore / m_num;
}

void ShapeproLib::Showscore()const
{
	cout << "总分为：" << m_tatalscore << endl;
	cout << "平均分为：" << m_averagescore << endl;
}
