#include "Vector2.h"

Vector2::Vector2(int anX, int aY)
	:x(anX), y(aY)
{

}

Vector2::Vector2(std::vector<int> someCoords)
	:x(someCoords.at(0)), y(someCoords.at(1))
{
}

Vector2::Vector2(Vector2* aVector2)
	:x(aVector2->GetX()), y(aVector2->GetY())
{

}

Vector2::~Vector2()
{
}

int Vector2::GetX()
{
	return x;
}

int Vector2::GetY()
{
	return y;
}

float Vector2::GetMagnitude()
{
	return sqrtf(x^2 + y^2);
}

bool Vector2::operator==(Vector2 v1)
{
	return (x == v1.GetX()) && (y == v1.GetY());
}

Vector2 Vector2::operator-(Vector2 v1)
{
	return Vector2(x - v1.GetX(), y - v1.GetY());
}


