#pragma once
#include <string>
#include <cmath>
#include <typeinfo>
#include "Vector2.h"
#include "Behaviour.h"
#include "ChaseBehaviour.h"
#include "EvadeBehaviour.h"

class Character
{
public:
	enum class AvailableBehaviours {
		IDLE,
		CHASE,
		EVADE
	};
public:
	Character(AvailableBehaviours aStartBehaviour, 
		Vector2 aStartPosition = { 0, 0 },
		std::string anIcon = "x",
		Character* aTarget = nullptr
	);
	~Character();
	void SetTarget(Character* aTarget);
	void Setbehaviour(AvailableBehaviours aBehaviour);
	Vector2 Update();
	Vector2 GetPosition();
	std::string GetIcon();
private:
	Behaviour* currentBehaviour;
	Character* target;
	Vector2 position;
	std::string icon;
};

