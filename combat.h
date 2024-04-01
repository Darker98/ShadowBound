using namespace std;

void combat_stats(int* player_health, float player_mana, int opponent_health, float opponent_mana) {
	cout << endl << endl;
	cout << "\t\t\t-----------------------------------------------";
	cout << endl << endl;

	// Output stats
	cout << "\t\t\tYour health: " + to_string(*player_health);
	cout << "\t\tOpponent health: " + to_string(opponent_health);
	cout << endl;
	cout << "\t\t\tYour mana:   " + to_string(int(player_mana));
	cout << "\t\tOpponent mana:   " + to_string(int(opponent_mana));
	cout << endl;
	cout << endl;
	cout << "\t\t\t\tAttack\t\t\tDefend\n\t\t\t\t\t    Rest";
	cout << endl << endl;

	cout << "\t\t\t-----------------------------------------------" << endl << endl;
}

bool attack(int* player_health, float* player_mana, int* opponent_health, float* opponent_mana) {

	// Input number choice
	string output_text, player_number_input;
	output("Number: ");
	getline(cin, player_number_input);

	// Reject invalid input
	bool integer_check = check_integer(player_number_input, 1, 5);
	bool mana_check;
	if (integer_check == false)
		mana_check = false;
	else
		mana_check = check_mana(stoi(player_number_input), player_mana);

	if (!integer_check || !mana_check) {
		return false;
	}

	int player_number = stoi(player_number_input); // convert string to int

	// Generate opponent choice and number
	int opponent_number;
	string opponent_choice = generate_opponent_choice(*opponent_mana);
	if (opponent_choice == "rest")
		opponent_number = 0;
	else if (opponent_choice == "attack")
		opponent_number = generate_int(1, (*opponent_mana > 5) ? 5 : *opponent_mana);
	else
		opponent_number = generate_int(1, (*opponent_mana > 2.5) ? 5 : *opponent_mana * 2);

	cout << endl;
	output("Opponent chose to " + opponent_choice);
	cout << endl;
	output_text = "Opponent entered " + to_string(opponent_number);
	output(output_text);
	cout << endl << endl;

	// Opponent defends
	if (opponent_choice == "defend") {
		output("Your attack was blocked.");
		*player_mana -= player_number;

		// Special case where opponent number is same as player number
		if (opponent_number == player_number) {
			cout << endl;
			output("No mana deducted from opponent.");
		}
		// Deduct mana from opponent
		else
			*opponent_mana -= opponent_number / 2.0;
	}
	// Player attacks
	else if (player_number > opponent_number) {
		*opponent_health -= player_number;
		*player_mana -= player_number;
		output("Your attack was successful!");
	}
	// Opponent attacks
	else if (player_number < opponent_number) {
		*player_health -= opponent_number;
		*opponent_mana -= opponent_number;
		output("Your attack failed!");
		cout << endl;
		output("Opponent attacks.");
	}
	// Draw
	else {
		*player_mana -= player_number;
		*opponent_mana -= opponent_number;
		output("Draw. You both get tired. Mana deducted.", 50, false);
	}

	// If opponent rested
	if (opponent_choice == "rest") {
		int regain_mana = generate_int(6, 8);
		cout << endl;
		output("Opponent rested. Opponent gained " + to_string(regain_mana) + " mana.", 50, false);
		*opponent_mana += regain_mana;
	}

	return true;
}


bool defend(int* player_health, float* player_mana, int* opponent_health, float* opponent_mana) {

	// Input number choice
	string output_text, player_number_input;
	output("Number: ");
	getline(cin, player_number_input);

	// Reject invalid input
	bool integer_check = check_integer(player_number_input, 1, 5);
	bool mana_check;
	float mana_to_be_checked;
	if (integer_check == false)
		mana_check = false;
	else {
		mana_to_be_checked = *player_mana * 2;
		mana_check = check_mana(stoi(player_number_input), &mana_to_be_checked);
	}

	if (!integer_check || !mana_check) {
		return false;
	}

	int player_number = stoi(player_number_input); // convert string to int

	// Generate opponent choice and number
	int opponent_number;
	string opponent_choice = generate_opponent_choice(*opponent_mana);
	if (opponent_choice == "rest")
		opponent_number = 0;
	else if (opponent_choice == "attack")
		opponent_number = generate_int(1, (*opponent_mana > 5) ? 5 : *opponent_mana);
	else
		opponent_number = generate_int(1, (*opponent_mana > 2.5) ? 5 : *opponent_mana);

	cout << endl;
	output("Opponent chose to " + opponent_choice);
	cout << endl;
	output_text = "Opponent entered " + to_string(opponent_number);
	output(output_text);
	cout << endl << endl;

	// If opponent attacks
	if (opponent_choice == "attack") {
		output("Opponent's attack was blocked.");
		*opponent_mana -= opponent_number;

		// Special case where opponent number is same as player number
		if (opponent_number == player_number) {
			cout << endl;
			output("No mana deducted from you.");
		}
		else
			*player_mana -= player_number / 2.0;
	}
	// If opponent rests
	else if (opponent_choice == "rest") {
		int regain_mana = generate_int(6, 8);
		cout << endl;
		output("Opponent rested. Opponent gained " + to_string(regain_mana) + " mana.", 50, false);
		*opponent_mana += regain_mana;
	}
	// If opponent defends as well
	else {
		output("Nothing happens. You stare at the opponent.", 50, false);
		*player_mana -= player_number / 2.0;
		*opponent_mana -= opponent_number / 2.0;
	}

	return true;
}


void rest(int* player_health, float* player_mana, int* opponent_health, float* opponent_mana) {
	// Generate opponent choice and number
	int opponent_number;
	string opponent_choice = generate_opponent_choice(*opponent_mana);
	if (opponent_choice == "rest")
		opponent_number = 0;
	else if (opponent_choice == "attack")
		opponent_number = generate_int(1, (*opponent_mana > 5) ? 5 : *opponent_mana);
	else
		opponent_number = generate_int(1, (*opponent_mana > 2.5) ? 5 : *opponent_mana);

	cout << endl;
	output("Opponent chose to " + opponent_choice);
	cout << endl;
	output("Opponent entered " + to_string(opponent_number));
	cout << endl << endl;

	// If opponent attacks
	if (opponent_choice == "attack") {
		*player_health -= opponent_number;
		*opponent_mana -= opponent_number;
		output("Opponent attacks.");
	}
	// If opponent defends
	else if (opponent_choice == "defend") {
		*opponent_mana -= opponent_number / 2.0;
		output("Nothing happens. You stare at the opponent.", 50, false);
	}
	// If opponent rests as well
	else {
		int regain_mana = generate_int(6, 8);
		cout << endl;
		output("Opponent rested. Opponent gained " + to_string(regain_mana) + " mana.", 50, false);
		*opponent_mana += regain_mana;
	}

	// Player rests
	int regain_mana = generate_int(6, 8);
	cout << endl;
	output("You rested. You gained " + to_string(regain_mana) + " mana.", 50, false);
	*player_mana += regain_mana;
}

bool combat(int *player_health, int opponent_health) {
	srand(time(0));

	// Set up combat
	float player_mana = 20;
	float opponent_mana = 20;
	bool battle_end = false;

	// Non-combat related variables
	string output_text;
	bool valid_choice;
	string choices[3] = { "attack", "defend", "rest" };

	while (!battle_end) {
		clear();

		combat_stats(player_health, player_mana, opponent_health, opponent_mana);

		// Input choice
		string choice;
		output("Choice: ");
		getline(cin, choice);
		choice = string_lower(choice);

		// Check if choice is valid
		valid_choice = check_input(choice, choices, 3);
		if (!valid_choice) {
			output("\tUnrecognised input");
			cout << endl;
		}
		// Call appropriate function
		else if (choice == "attack") {
			attack(player_health, &player_mana, &opponent_health, &opponent_mana);
		}
		else if (choice == "defend") {
			defend(player_health, &player_mana, &opponent_health, &opponent_mana);
		}
		else {
			rest(player_health, &player_mana, &opponent_health, &opponent_mana);
		}

		// Stop battle if health is less than 0
		if (opponent_health <= 0 || *player_health <= 0) {
			battle_end = true;
		}

		pause();
	}

	if (opponent_health <= 0) {
		clear();
		output("You defeated your opponent. You stand over the body, glamouring in victory.");
		pause();
		clear();
		return true;
	}
	else {
		clear();
		output("You ran out of health. You glimpse one last time at the world before you dissolve into shadow.");
		pause();
		clear();
		return false;
	}
}