#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "utility_functions.h"
#include "combat.h"
#include "sections.h"
using namespace std;

int execute_section(int section_number, int* player_health, vector<Section>& sections);

int main() {

	// Initializing the game
	int section_number = 0;
	int player_health = 99;
	vector<Section> sections = { {4, 0, 0, { false, false, false, false}, "00", false, false },
		{6, 0, 0, { false, false, false, false, false, false }, "0000", false, false },
		{4, 0, 0, { false, false, false, false }, "No door lock", false, false }
	};

	//starting_scene(&player_health);

	while (section_number != -1 || section_number != 100) {
		section_number = execute_section(section_number, &player_health, sections);
	}

	return 0;
}

int execute_section(int section_number, int* player_health, vector<Section>& sections) {
	switch (section_number) {
	case 0:
		return starting_cell(player_health, sections[0]);
	case 1:
		return hallway(player_health);
	case 2:
		return guard_room(player_health, sections[1]);
	case 3:
		return river(player_health, sections);
	case 4:
		return forest(player_health, sections[2]);
	case 5:
		return castle(player_health);
	case 6:
		return graveyard(player_health);
	case -1:
		clear();
		output("You have run out of health. You watch the light fade as you dissolve into shadow.");
		cout << endl;
		output("(close the window and restart to play again)");
		pause();
		return -1;
	case 100:
		return 100;
	default:
		output("Work in progress...");
	}
}