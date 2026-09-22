#pragma once
class TriangleItem
{
private:
	float m_area;
	float m_uarea;
	int m_a;
	int m_b;
	int m_c;
	int m_perimeter;
	int m_uperimeter;
	int m_score;
public:
	TriangleItem();
	TriangleItem(int a,int b,int c);
	void set(int a, int b, int c);
	void printTri();
	bool isTriangle();
	float calarea();
	void flow();
	int calperimeter();
	inline float Getarea() {
		return m_area;
	}
	inline float GetUarea() {
		return m_uarea;
	}
};

