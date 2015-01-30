#include "LMVector2.h"

namespace LM
{
	LMVector2::LMVector2()
	{
		lengthX = 0;
		lengthY = 0;
	}

	LMVector2::LMVector2(LM::LMPoint p1, LM::LMPoint p2)
	{
		lengthX = p2.GetX() - p1.GetX();
		lengthY = p2.GetY() - p1.GetY();
	}

	LMVector2::~LMVector2()
	{
	}

	float LMVector2::GetMagnitude()
	{
		return sqrt(float((lengthX * lengthX) + (lengthY * lengthY)));
	}

	LMVector2 LMVector2::GetNormal()
	{
		return LMVector2(-lengthY, lengthX);
	}

	float LMVector2::GetDotProduct(LMVector2 &operandVector)
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

