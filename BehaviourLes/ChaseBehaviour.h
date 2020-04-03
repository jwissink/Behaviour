#pragma once
#include "Behaviour.h"

class ChaseBehaviour :
	public Behaviour
{
public:
	ChaseBehaviour();
	~ChaseBehaviour();
	Vector2 Update(Vector2 ownPosition, Vector2 targetPosition, Vector2 minPosition = { 0, 0 }, Vector2 maxPosition = { 25, 25 });
};

