// BehaviourLes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <time.h>
#include <vector>
#include <vector>
#include <string>
#include "Character.h"
#include "Behaviour.h"
#include "ChaseBehaviour.h"
#include "EvadeBehaviour.h"

double delay = 0.1;
double previousFrameTime = 0.0;
int maxWidth = 25;
int maxHeight = 25;

bool running = true;
int main()
{
	//Characters aanmaken
	Character player(Character::AvailableBehaviours::IDLE, { 2, 2 }, "E");
	Character enemy(Character::AvailableBehaviours::CHASE, { 23, 23 }, "C", &player);

	//Game mechanics activeren
	player.SetTarget(&enemy);
	player.Setbehaviour(Character::AvailableBehaviours::EVADE);

	//alle spelers in een lijst
	std::vector<Character*> characters{ &player, &enemy };

	previousFrameTime = clock();
	//de game zelf
	while (running) {
		//een eigen timer
		if ((clock() - previousFrameTime) / CLOCKS_PER_SEC >= delay) {
#pragma region CommentedCode
			//deze scene vullen met _ (de array)
						//std::fill(scene.begin(), scene.end(), "_");
						//console clearen (Clear Screen)
						/*
						for (int i = 0; i < maxHeight; i++) {
							std::vector<std::string> vec;
							vec.resize(maxWidth);
							std::fill(vec.begin(), vec.end(), "[_]");
							newScene.push_back(vec);
						}
						*/
#pragma endregion
			system("cls");
			//std::cout << "[" << clock() << "] updating" << std::endl;
			for (Character* aCharacter : characters) {
				//update all characters en zet ze op de juiste locatie
				//Vector2 pos = aCharacter->Update();
				//newScene.at(pos.GetX()).at(pos.GetY()) = "[" + aCharacter->GetIcon() + "]";
				aCharacter->Update();
				COORD position = { aCharacter->GetPosition().GetX(), aCharacter->GetPosition().GetY() };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
				std::cout << aCharacter->GetIcon();
			}	
#pragma region CommentedLoops
			/*
						for (std::string s : scene) {
							//output de scene
							std::cout << s;
						}

						for (int x = 0; x < newScene.size(); x++) {
							for (int y = 0; y < newScene.at(x).size(); y++) {
								std::cout << newScene.at(x).at(y);
							}
							std::cout << std::endl;
						}
						*/
#pragma endregion
			previousFrameTime = clock();
		}
		if (characters.at(0)->GetPosition() == characters.at(1)->GetPosition()) {
			std::cout << "\nGAME OVER\nPress ENTER to quit" << std::endl;
			running = false;
		}
	}
	std::cin.get();
}


