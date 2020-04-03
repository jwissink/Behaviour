#pragma once
#include <vector>
#include <cmath>
class Vector2
{
public:
	Vector2(int anX, int aY);
	Vector2(std::vector<int> someCoords);
	Vector2(Vector2* aVector2);
	~Vector2();
	int GetX();
	int GetY();
	float GetMagnitude();

	bool operator==(Vector2 v1);

	Vector2 operator-(Vector2 v1);
	/*
	bool operator>(Vector2 v1);
	bool operator<(Vector2 v1);
	*/
private:
	int x;
	int y;
};

