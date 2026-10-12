#include "ShapeItem.h"
#include<iostream>
#include<cmath>
#include<limits>
using namespace std;
ShapeItem::ShapeItem()
	: m_uarea(0.0), m_uperimeter(0.0), m_score(0)
{

}

int ShapeItem::flow()
{
	if (!isValid())
	{
		cout << "Invalid data!" << endl;
		m_score = 0;
		return m_score;
	}
	cout << "请输入面积与周长：";
	cin >> m_uarea >> m_uperimeter;
	const double areaTol = 1e-2;//面积误差容忍度0.01
	const double periTol = 1e-2;//周长误差容忍度0.01
	const bool areaOK = abs(m_uarea - calArea()) <= areaTol;//判断面积是否在误差范围内
	const bool periOK = abs(m_uperimeter - calPerimeter()) <= periTol;//判断周长是否在误差范围内

	m_score = (areaOK && periOK) ? 1 : 0;//如果面积和周长都正确，则得分为1，否则为0
	if (m_score == 0) {
		std::cout << "答案有误。正确答案：面积 = " << calArea()
			<< "，周长 = " << calPerimeter() << '\n';
	}
	return m_score;
}