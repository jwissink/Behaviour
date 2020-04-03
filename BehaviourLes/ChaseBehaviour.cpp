#include "ChaseBehaviour.h"


ChaseBehaviour::ChaseBehaviour()
{
}

ChaseBehaviour::~ChaseBehaviour()
{
}

Vector2 ChaseBehaviour::Update(Vector2 ownPosition, Vector2 targetPosition, Vector2 minPosition, Vector2 maxPosition)
{
	if (ownPosition.GetX() < targetPosition.GetX() && (ownPosition.GetX() > minPosition.GetX())) {
		ownPosition = Vector2(ownPosition.GetX() + 1, ownPosition.GetY());
	}
	else if (ownPosition.GetX() > targetPosition.GetX() && (ownPosition.GetX() < maxPosition.GetX())) {
		ownPosition = Vector2(ownPosition.GetX() - 1, ownPosition.GetY());
	}
	else if (ownPosition.GetY() < targetPosition.GetY() && (ownPosition.GetY() > minPosition.GetY())) {
		ownPosition = Vector2(ownPosition.GetX(), ownPosition.GetY() +1 );
	}
	else if (ownPosition.GetY() > targetPosition.GetY() && (ownPosition.GetY() < maxPosition.GetY())) {
		ownPosition = Vector2(ownPosition.GetX(), ownPosition.GetY() - 1);
	}
	return ownPosition;

}
