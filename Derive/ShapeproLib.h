#pragma once
#include "ShapeItem.h"
#include "TriangleItem.h"
#include "RectangleItem.h"
#include "CircleItem.h"
#include<string>
#include<vector>
using namespace std;
class ShapeproLib
{
private:
	ShapeItem* randomShop();//随机生成题目
	vector<ShapeItem*> m_items;
	string m_libname;
	int m_tatalscore;
	double m_averagescore;
public:
	explicit ShapeproLib(int num = 20);
	~ShapeproLib();
	void showallpro()const;
	void showanswers()const;
	void testallpro();
	void showscore()const;
	int GetTatalscore() {
		return m_tatalscore;
	}
	double GetAveragescore() {
		return m_averagescore;
	}
};

