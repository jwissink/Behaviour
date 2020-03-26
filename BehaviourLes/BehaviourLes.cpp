// BehaviourLes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <list>
#include <vector>
#include <string>
#include "Character.h"
#include "Behaviour.h"
#include "ChaseBehaviour.h"
#include "EvadeBehaviour.h"

double delay = 1.5;
double previousFrameTime = 0.0;
int maxWidth = 100;
std::vector<std::string> scene;

int main()
{
	//Characters aanmaken
	Character player(Character::AvailableBehaviours::IDLE, 0, "E");
	Character enemy(Character::AvailableBehaviours::CHASE, 10, "C", &player);

	//Game mechanics activeren
	player.SetTarget(&enemy);
	player.Setbehaviour(Character::AvailableBehaviours::EVADE);

	//alle spelers in een lijst
	std::list<Character*> characters{ &player, &enemy };

	//een scene van 100 breed aanmaken
	scene.resize(50);

	//deze scene vullen met _
	
	previousFrameTime = clock();
	//de game zelf
	while (true) {
		//een eigen timer
		if ((clock() - previousFrameTime) / CLOCKS_PER_SEC >= delay) {
			std::fill(scene.begin(), scene.end(), "_");
			system("cls");
			//std::cout << "[" << clock() << "] updating" << std::endl;
			for (Character* aCharacter : characters) {
				scene.at(aCharacter->Update()) = aCharacter->GetIcon();
			}
			for (std::string s : scene) {
				std::cout << s;
			}


			previousFrameTime = clock();
		}
	}
}


