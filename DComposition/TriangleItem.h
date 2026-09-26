#pragma once
class TriangleItem
{
private:
	int m_a;
	int m_b;
	int m_c;
	int m_uarea;
	int m_uperimeter; 
	int m_score;
public:
	TriangleItem();
	void printTri() const;
	bool isTriangle() const;
	double calArea() const;
	int calPerimeter() const;
	int flow();
	int GetA() const { return m_a; }
	int GetB() const { return m_b; }
	int GetC() const { return m_c; }
	int GetScore() const { return m_score; }
};

