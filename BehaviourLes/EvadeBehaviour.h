#pragma once
#include "Behaviour.h"

class EvadeBehaviour :
	public Behaviour
{
public:
	EvadeBehaviour();
	~EvadeBehaviour();
	Vector2 Update(Vector2 ownPosition, Vector2 targetPosition, float gap = 1.0f, Vector2 minPosition = { 0, 0 }, Vector2 maxPosition = { 25, 25 });
};

