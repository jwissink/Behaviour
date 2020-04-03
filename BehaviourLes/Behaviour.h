#pragma once
#include <cmath>
#include "Vector2.h"

class Character;

class Behaviour
{
public:
	Behaviour();
	~Behaviour();
	virtual Vector2 Update(Vector2 ownPosition, Vector2 targetPosition, Vector2 minPosition = { 0, 0 }, Vector2 maxPosition = { 25, 25 });
};

