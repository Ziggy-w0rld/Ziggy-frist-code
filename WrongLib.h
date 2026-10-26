#pragma once
#include<vector>
#include "ShapeItem.h"
#include<string>
using namespace std;
class WrongLib
{
private:
	vector<ShapeItem*> m_wrong;
public:
	WrongLib();
	~WrongLib();
	void addWrong(ShapeItem* item);
	void showWrong() const;
	void testWrong() const;
	//新增持久化接口
	void saveToFile(const string& fileName) const;
	void loadFromFile(const string& fileName);
};

