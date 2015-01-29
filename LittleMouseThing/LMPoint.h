#ifndef LMPOINT_H
#define LMPOINT_H

namespace LM
{
	class Point
	{
	private:
		int x;
		int y;
	public:
		Point();
		Point(int _x, int _y);
		Point(const Point &point);

		void SetX(int _x) { x = _x; }
		void SetY(int _y) { y = _y; }
		int GetX() const { return x; }
		int GetY() const { return y; }

		Point &operator+(const Point rhs);
		Point &operator-(const Point rhs);
		Point &operator*(const int rhs);
		Point &operator/(const int rhs);
		Point &operator=(const Point rhs);
	};

}

#endif