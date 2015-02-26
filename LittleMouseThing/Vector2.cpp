#include "Vector2.h"

namespace LM
{
	Vector2::Vector2()
	{
		lengthX = 0;
		lengthY = 0;
	}

	Vector2::Vector2(LM::Point2 p1, LM::Point2 p2)
	{
		lengthX = p2.GetX() - p1.GetX();
		lengthY = p2.GetY() - p1.GetY();
	}

	Vector2::~Vector2()
	{
	}

	float Vector2::GetMagnitude()
	{
		return sqrt(float((lengthX * lengthX) + (lengthY * lengthY)));
	}

	Vector2 Vector2::Normalise()
	{
		return Vector2(-lengthY, lengthX);
	}

	int Vector2::GetDotProduct(Vector2 &operandVector)
	{
		return lengthX * operandVector.GetX() + lengthY * operandVector.GetY();
	}

	/*LMVector2 &LMVector2::operator = (const LMVector2 &rhs) const
	{
		return LMVector2(rhs.GetX(), rhs.GetY());
	}*/

	/*LMVector2 &LMVector2::operator + (const LMVector2 &rhs) const
	{
		return LMVector2()
	}*/

	/*LMVector2 &LMVector2::operator - (const LMVector2 &rhs) const
	{
	
	}*/

	/*LMVector2 &LMVector2::operator * (const int &rhs) const
	{

	}*/

	/*LMVector2 &LMVector2::operator / (const int &rhs) const
	{

	}*/
}

