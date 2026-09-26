#pragma once
#include "TriangleItem.h"
#include<string>
using namespace std;
class ShapeproLib
{
private:
	TriangleItem m_itemarray[20];
	string m_libname;
	int m_num;
	int m_tatalscore;
	float m_averagescore;
public:
	ShapeproLib();
	void showallpro()const;
	void showanswers()const;
	void testallpro();
	int GetTatalscore() {
		return m_tatalscore;
	}
	float GetAveragescore() {
		return m_averagescore;
	}
	void Showscore()const;
};

