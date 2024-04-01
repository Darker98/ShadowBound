using namespace std;

struct Section {
	int total_puzzles;
	int puzzles_completed = 0;
	int puzzles_failed = 0;
	vector<bool> puzzle_states;
	string door_lock;
	bool visited;
	bool door_unlocked;
};

void starting_scene(int* player_health) {
	string prompt;

	cout << endl;
	cout << R"(
			 _________.__                .___            __________                         .___
			 /   _____/|  |__ _____     __| _/______  _  _\______   \ ____  __ __  ____    __| _/
			 \_____  \ |  |  \\__  \   / __ |/  _ \ \/ \/ /|    |  _//  _ \|  |  \/    \  / __ | 
			 /        \|   Y  \/ __ \_/ /_/ (  <_> )     / |    |   (  <_> )  |  /   |  \/ /_/ | 
			/_______  /|___|  (____  /\____ |\____/ \/\_/  |______  /\____/|____/|___|  /\____ | 
			        \/      \/     \/      \/                     \/                  \/      \/ 
)";

	cout << endl << endl;
	output("Welcome to ShadowBound, a text-based storyline game taking place in the world of Shadowvale. "
		"The kingdom is ruled by King Tenebris, an intelligent and cunning king with secrets to hide. Travel through "
		"the world and discover foes and enemies. Combat through unexpected beings and solve challenging puzzles to"
		" traverse through this unforgiving land. Unlock new areas and explore the map to its entirety. "
		"Challenge your brain to find both endings. Good luck fellow shadowbound!");

	cout << endl << endl;
	output("WARNING: Some scenes may be distressing. Proceed with caution.");

	pause();

	clear();

	output("March 25, 76 BC: \n\n");

	output("You awake to the sound of rustling leaves. "
		"You have no memory of how you got here or anything "
		"that happened prior. All you know is that you're b"
		"eing dragged across the a rocky terrain by 2... creatures? "
		"That can't be right but they don't look fully human. Before you "
		"can continue your thoughts, you hear one of them say \"He's awake\". "
		"There is a painful blow on your head and you return back to unconsciousness.\n\n");

	output("When you wake again, you are in an old cell. Water is dripping from the corner. You scan the room. "
		"It's empty except for a corroded iron door and a skeleton in the corner.");

	cout << endl << endl << endl << "\t\t\t";
	system("PAUSE");

	clear();

	output("There is only one way out of the cell, the iron door, but its locked. You scan the area for anything that "
		"might be of use. You see a skeleton in the corner.");
	separator();

	output("Enter 'skeleton' to move to the skeleton.");
	cout << endl;
	output("prompt: ");

	string choices[1];

	choices[0] = { "skeleton" };
	getline(cin, prompt);
	prompt = string_lower(prompt);
	while (!check_input(prompt, choices, 1)) {
		cout << "\x1b[F" << "\x1b[2K";
		cout << "\x1b[F" << "\x1b[2K";

		output("Enter the word 'skeleton' to move to the skeleton.");
		cout << endl;
		output("prompt: ");

		getline(cin, prompt);
		prompt = string_lower(prompt);
	}

	clear();
	output("The skeleton looks fresh. A rusty sword is embedded into its skull. And something shiny lies next to it. A KEY?!");
	separator();

	output("Enter 'sword' to obtain the sword.");
	cout << endl;
	output("prompt: ");

	choices[0] = { "sword" };
	getline(cin, prompt);
	prompt = string_lower(prompt);
	while (!check_input(prompt, choices, 1)) {
		cout << "\x1b[F" << "\x1b[2K";
		cout << "\x1b[F" << "\x1b[2K";

		output("Enter 'sword' to obtain the sword.");
		cout << endl;
		output("prompt: ");

		getline(cin, prompt);
		prompt = string_lower(prompt);
	}

	cout << endl;
	output("Sword obtained!");

	pause();
	clear();

	output("The skeleton looks fresh. A rusty sword is embedded into its skull. And something shiny lies next to it. A KEY?!");
	separator();

	output("Enter 'key' to obtain the key.");
	cout << endl;
	output("prompt: ");

	choices[0] = { "key" };
	getline(cin, prompt);
	prompt = string_lower(prompt);
	while (!check_input(prompt, choices, 1)) {
		cout << "\x1b[F" << "\x1b[2K";
		cout << "\x1b[F" << "\x1b[2K";

		output("Enter 'key' to obtain the key.");
		cout << endl;
		output("prompt: ");

		getline(cin, prompt);
		prompt = string_lower(prompt);
	}

	cout << endl;
	output("Key obtained!");

	pause();
	clear();

	output("There is only one way out of the cell, the iron door, but its locked. You scan the area for anything that "
		"might be of use. You see a skeleton in the corner.");
	separator();

	output("You have now obtained the key. Enter 'door' to unlock the door.");
	cout << endl;
	output("prompt: ");

	choices[0] = { "door" };
	getline(cin, prompt);
	prompt = string_lower(prompt);
	while (!check_input(prompt, choices, 1)) {
		cout << "\x1b[F" << "\x1b[2K";
		cout << "\x1b[F" << "\x1b[2K";

		output("You have now obtained the key. Enter 'door' to unlock the door.");
		cout << endl;
		output("prompt: ");

		getline(cin, prompt);
		prompt = string_lower(prompt);
	}

	clear();

	output("The door creaks open. You hear a grunt and a shadowy being comes into view. The creature is not human."
		" It seems to be made of shadows, its body swirling and misting. It has leather armor and a sharp sword hangs by its side."
		" You pick up the rusted sword you had and step into combat.");

	pause();
	clear();

	output("There are three options in combat: ");
	cout << endl;
	output("1) Attack");
	cout << endl;
	output("2) Defend");
	cout << endl;
	output("3) Rest");
	cout << endl << endl;
	output("If you choose to attack, you enter a number between 1-5. If your number is greater than your opponent you attack. "
		"Otherwise, opponent attacks. Be careful with entering high numbers as this number will be deducted from your mana if an attack is successful.");
	cout << endl << endl;
	output("If you defend, you will block the attack. If your number is the same as the opponent's number, no mana is deducted. "
		"Otherwise, half your number entered is deducted.");
	cout << endl << endl;
	output("Run too low on mana and you will have to rest. Resting leaves you vulnerable to an attack but regains 6-8 mana.");

	pause();
	clear();

	combat(player_health, 15);

	output("This marks the end of the tutorial. Good luck! Oh, and one more thing. Try typing in 'switch' to swap worlds. ;)");
	pause();
}

int starting_cell(int* player_health, Section& data) {

	string prompt, riddle;
	bool puzzle_solved;

	bool shadow = false;
	bool repetition = false;
	int output_speed;

	// Initialize puzzle values
	int puzzles_solved = data.puzzles_completed;
	int puzzles_failed = data.puzzles_failed;

	string door_lock = data.door_lock; // initialize door code


	clear();
	while (true) {
		clear();

		if (repetition)
			output_speed = 0;
		else
			output_speed = 50;

		// End game if player ran out of health
		if (*player_health < 0)
			return -1;

		if (puzzles_failed == 3) {
			clear();
			output("You failed 3 puzzles. The door code is now unknown to you. You are stuck in the cell forever...");
			pause();
			return -1;
		}

		if (!shadow) {
			output("The air is damp and foggy. You can barely see the walls. "
				"They are bare except for a singular painting. It appears to be glowing. "
				"On the wall opposite you sits a desk, it's purpose unknown. To your right, "
				"an iron door reflects what little light there is. It seems to glow in the dark. ", output_speed);
			separator();

			repetition = true;

			// Input prompt and ensure it is valid
			string choices[] = { "painting", "desk", "door", "switch" };
			output("prompt: ");
			getline(cin, prompt);
			prompt = string_lower(prompt);
			while (!check_input(prompt, choices, 4)) {
				cout << endl << endl;
				output("\tInvalid prompt. Try again.");
				pause;
				cout << "\x1b[2K" << "\x1b[F";
				cout << "\x1b[2K" << "\x1b[F";
				cout << "\x1b[2K" << "\x1b[F";
				cout << "\x1b[2K";

				output("prompt: ");
				getline(cin, prompt);
				prompt = string_lower(prompt);
			}

			// If prompt is painting
			if (prompt == "painting") {
				cout << endl;
				output("There is a hidden message in the painting.");
				// Allow to access puzzle if not previously attempted
				if (!data.puzzle_states[0]) { //updated
					cout << endl;
					output("This will activate a puzzle. Are you sure you want to continue? ");;
					getline(cin, prompt);
					prompt = string_lower(prompt);
					if (prompt == "yes" || prompt == "y") {
						data.puzzle_states[0] = true; //updated
						riddle = "The one before me provides company, but I become a crowd. What number am I?";
						puzzle_solved = puzzle(riddle, "3");
						if (puzzle_solved) {
							cout << endl;
							if (puzzles_solved < 2) {
								output("This is one of the digits to the door lock.");
								door_lock[puzzles_solved] = '3';
							}
							else {
								output("Congrats! You solved the puzzle.");
							}
							puzzles_solved++; //updated
							pause();
						}
						else {
							cout << endl;
							output("You failed the puzzle. You lose 10 health.");
							puzzles_failed++; //updated
							pause();
							player_health -= 10;
						}
					}
				}
				// Reject if puzzle is already attempted
				else { //updated
					cout << endl;
					output("You have already attempted this puzzle.");
					pause();
				}
			}
			// If prompt is desk
			else if (prompt == "desk") {
				cout << endl;
				output("A letter is placed on the desk.");
				if (!data.puzzle_states[1]) {
					output("This will activate a puzzle. Are you sure you want to continue? ");;
					getline(cin, prompt);
					prompt = string_lower(prompt);
					if (prompt == "yes" || prompt == "y") {
						data.puzzle_states[1] = true;
						riddle = "What goes around, comes around. The angels are limited by my count. What number am I?";
						puzzle_solved = puzzle(riddle, "360");
						if (puzzle_solved) {
							cout << endl;
							if (puzzles_solved < 2) {
								output("The second digit is one of the digits to the door lock.");
								door_lock[puzzles_solved] = '6';
							}
							else {
								output("Congrats! You solved the puzzle.");
							}
							puzzles_solved++;
							pause();
						}
					}
					else {
						cout << endl;
						output("You failed the puzzle. You lose 10 health.");
						puzzles_failed++; //updated 2
						pause();
						player_health -= 10;
					}
				}
				// Reject if puzzle is already attempted
				else { //updated 2
					cout << endl;
					output("You have already attempted this puzzle.");
					pause();
				}
			}
			// If prompt is door
			else if (prompt == "door") {
				if (!data.visited) {
					cout << endl;
					// Allow to enter code if puzzle solved is at least 2
					if (puzzles_solved >= 2) {
						output("Enter door code: ");
						getline(cin, prompt);
						if (prompt == door_lock) {
							data.puzzles_completed = puzzles_solved;
							data.puzzles_failed = puzzles_failed;
							data.visited = true;
							return 1;
						}
						else {
							cout << endl;
							output("Incorrect combination.");
							pause();
						}
					}
					else {
						output("Complete at least 2 puzzles to be able to unlock door.");
						pause();
					}
				}
				else {
					cout << endl;
					output("The bodies of the guards lie scattered in the hallway. You head towards the door on the other side.");
					pause;
					data.puzzles_completed = puzzles_solved;
					data.puzzles_failed = puzzles_failed;
					return 2;
				}
			}
			// If prompt is switch
			else {
				shadow = !shadow;
				repetition = false;
			}
		}
		// If in shadow world
		else {
			output("Purple wisps permeate the air, floating like bees. "
				"You see images on the wall, like some sort of black ink. "
				"One image appears to be a portal of some sort, exiting into "
				"the unknown. The second image is shaped like a painting. "
				"You can barely make out a trapdoor shaped shadow in the corner of the cell", output_speed);
			separator();

			repetition = true;

			// Input prompt and ensure it is valid
			string choices[] = { "painting", "portal", "trapdoor", "switch" };
			output("prompt: ");
			getline(cin, prompt);
			prompt = string_lower(prompt);
			while (!check_input(prompt, choices, 4)) {
				cout << endl << endl;
				output("\tInvalid prompt. Try again.");
				pause;
				cout << "\x1b[2K" << "\x1b[F";
				cout << "\x1b[2K" << "\x1b[F";
				cout << "\x1b[2K" << "\x1b[F";
				cout << "\x1b[2K";

				output("prompt: ");
				getline(cin, prompt);
				prompt = string_lower(prompt);
			}

			// If prompt is painting
			if (prompt == "painting") {
				cout << endl;
				output("A strange writing can be seen in the corner of the frame.");
				if (!data.puzzle_states[2]) { // updated 3
					cout << endl;
					output("This will activate a puzzle. Are you sure you want to continue? ");;
					getline(cin, prompt);
					prompt = string_lower(prompt);
					if (prompt == "yes" || prompt == "y") {
						data.puzzle_states[2] = true; // updated 3
						riddle = "The devil shudders under my name. What number am I?";
						puzzle_solved = puzzle(riddle, "666");
						if (puzzle_solved) {
							cout << endl;
							if (puzzles_solved < 2) {
								output("This is one of the digits to the door lock.");
								door_lock[puzzles_solved] = '6';
							}
							else {
								output("Congrats! You solved the puzzle.");
							}
							puzzles_solved++;
							pause();
						}
						else {
							cout << endl;
							output("You failed the puzzle. You lose 10 health.");
							puzzles_failed++; //updated 3
							pause();
							player_health -= 10;
						}
					}
				}
				// Reject if puzzle is already attempted
				else { //updated 3
					cout << endl;
					output("You have already attempted this puzzle.");
					pause();
				}
			}
			// If prompt is portal
			else if (prompt == "portal") {
				cout << endl;
				output("You into the portal. Words float in the abyss.");
				if (!data.puzzle_states[3]) { // updated 4
					cout << endl;
					output("This will activate a puzzle. Are you sure you want to continue? ");;
					getline(cin, prompt);
					prompt = string_lower(prompt);
					if (prompt == "yes" || prompt == "y") {
						data.puzzle_states[3] = true; // updated 4
						riddle = "I stand tall like a tower, the full moon gleaming next to me. What number am I?";
						puzzle_solved = puzzle(riddle, "10");
						if (puzzle_solved) {
							cout << endl;
							if (puzzles_solved < 2) {
								output("The second digit is one of the digits to the door lock.");
								door_lock[puzzles_solved] = '0';
							}
							else {
								output("Congrats! You solved the puzzle.");
							}
							puzzles_solved++;
							pause();
						}
						else {
							cout << endl;
							output("You failed the puzzle. You lose 10 health.");
							puzzles_failed++; //updated 4
							pause();
							player_health -= 10;
						}
					}
				}
				// Reject if puzzle is already attempted
				else { //updated 4
					cout << endl;
					output("You have already attempted this puzzle.");
					pause();
				}
			}
			// If prompt is trapdoor
			else if (prompt == "trapdoor") {
				cout << endl;
				output("A dark energy surrounds the trapdoor.");
				pause();
			}
			// If prompt is switch
			else {
				shadow = !shadow;
				repetition = false;
			}
		}
	}
}

int hallway(int* player_health) {
	clear();

	output("You have entered the correct combination. The lock clicks and drops to the floor. "
		"The door swings open into a dark hallway, a single light bulb flickering on and off. "
		"Doors line the walls. Suddenly, a door at the end of the hall starts swinging open. "
		"Three figures come into view.");

	pause();
	clear();

	output("The first figure steps towards you, its sword raised. It looks ready for combat.");
	pause();

	//combat(player_health, 30);

	if (*player_health < 0)
		return -1;

	output("The second figure steps towards you. Its eyes glow menacingly under its helmet.");
	pause();

	//combat(player_health, 30);

	if (*player_health < 0)
		return -1;

	output("The final figure steps towards you. A low growl emanates from it.");
	pause();

	//combat(player_health, 30);

	if (*player_health < 0)
		return -1;

	return 2;
}

int guard_room(int* player_health, Section& data) {

	string prompt, riddle;
	bool puzzle_solved;

	bool shadow = false;
	bool repetition = false;
	int output_speed;

	// Initialize puzzle values
	int puzzles_solved = data.puzzles_completed;
	int puzzles_failed = data.puzzles_failed;

	string door_lock = data.door_lock; // initialize door code

	clear();

	while (true) {
		clear();

		// End game if player ran out of health
		if (*player_health < 0)
			return -1;

		if (repetition)
			output_speed = 0;
		else
			output_speed = 50;

		if (puzzles_failed == 3) {
			clear();
			output("You failed 3 puzzles. The door code is now unknown to you. You are stuck in the cell forever...");
			pause();
			return -1;
		}

		if (!shadow) {
			output("The room is full of equipment. Strange weapons you don't recognize, "
				"odd-looking tools and heavy armor line the walls. You might have found "
				"the guard's room. A compass is painted onto the floor, marking the centre "
				"of the room. You walk over to it. A heavy steel door seems to be the only other "
				"exit. There is a long wooden table along one of the walls. One wall is covered in graffiti."
				" The path behind you leads back to the cell.", output_speed);
			separator();

			repetition = true;

			// Input prompt and ensure it is valid
			string choices[] = { "compass", "table", "graffiti", "switch", "door", "path"};
			output("prompt: ");
			getline(cin, prompt);
			prompt = string_lower(prompt);
			while (!check_input(prompt, choices, 6)) {
				cout << endl << endl;
				output("\tInvalid prompt. Try again.");
				pause;
				cout << "\x1b[2K" << "\x1b[F";
				cout << "\x1b[2K" << "\x1b[F";
				cout << "\x1b[2K" << "\x1b[F";
				cout << "\x1b[2K";

				output("prompt: ");
				getline(cin, prompt);
				prompt = string_lower(prompt);
			}

			// If prompt is compass
			if (prompt == "compass") {
				cout << endl;
				output("A strange language is embedded around the circumference.");
				// Allow to access puzzle if not previously attempted
				if (!data.puzzle_states[0]) { 
					cout << endl;
					output("This will activate a puzzle. Are you sure you want to continue? ");;
					getline(cin, prompt);
					prompt = string_lower(prompt);
					if (prompt == "yes" || prompt == "y") {
						data.puzzle_states[0] = true; 
						riddle = "Put me straight and I am a stack. Tilt me sideways and I exted beyond the known universe. "
							"What number am I?";
						puzzle_solved = puzzle(riddle, "8");
						if (puzzle_solved) {
							cout << endl;
							if (puzzles_solved < 4) {
								output("This is one of the digits to the door lock.");
								door_lock[puzzles_solved] = '8';
							}
							else {
								output("Congrats! You solved the puzzle.");
							}
							puzzles_solved++; 
							pause();
						}
						else {
							cout << endl;
							output("You failed the puzzle. You lose 20 health.");
							puzzles_failed++; 
							pause();
							player_health -= 20;
						}
					}
				}
				// Reject if puzzle is already attempted
				else { 
					cout << endl;
					output("You have already attempted this puzzle.");
					pause();
				}
			}
			// If prompt is graffiti
			else if (prompt == "graffiti") {
				cout << endl;
				output("Legible sentences are painted on the wall.");
				// Allow to access puzzle if not previously attempted
				if (!data.puzzle_states[1]) {
					cout << endl;
					output("This will activate a puzzle. Are you sure you want to continue? ");;
					getline(cin, prompt);
					prompt = string_lower(prompt);
					if (prompt == "yes" || prompt == "y") {
						data.puzzle_states[1] = true;
						riddle = "Tree tarzan for tee one. What number am I?";
						puzzle_solved = puzzle(riddle, "3041");
						if (puzzle_solved) {
							cout << endl;
							if (puzzles_solved < 4) {
								output("The third digit is one of the digits to the door lock.");
								door_lock[puzzles_solved] = '4';
							}
							else {
								output("Congrats! You solved the puzzle.");
							}
							puzzles_solved++;
							pause();
						}
						else {
							cout << endl;
							output("You failed the puzzle. You lose 20 health.");
							puzzles_failed++;
							pause();
							player_health -= 20;
						}
					}
				}
				// Reject if puzzle is already attempted
				else {
					cout << endl;
					output("You have already attempted this puzzle.");
					pause();
				}
			}
			// If prompt is compass
			else if (prompt == "table") {
				cout << endl;
				output("Crooked words are carved onto the table.");
				// Allow to access puzzle if not previously attempted
				if (!data.puzzle_states[2]) { 
					cout << endl;
					output("This will activate a puzzle. Are you sure you want to continue? ");;
					getline(cin, prompt);
					prompt = string_lower(prompt);
					if (prompt == "yes" || prompt == "y") {
						data.puzzle_states[2] = true; 
						riddle = "Drive on a straight road and you are in my domain. What number am I?";
						puzzle_solved = puzzle(riddle, "180");
						if (puzzle_solved) {
							cout << endl;
							if (puzzles_solved < 4) {
								output("The second digit is one of the digits to the door lock.");
								door_lock[puzzles_solved] = '8';
							}
							else {
								output("Congrats! You solved the puzzle.");
							}
							puzzles_solved++; 
							pause();
						}
						else {
							cout << endl;
							output("You failed the puzzle. You lose 20 health.");
							puzzles_failed++; 
							pause();
							player_health -= 20;
						}
					}
				}
				// Reject if puzzle is already attempted
				else { 
					cout << endl;
					output("You have already attempted this puzzle.");
					pause();
				}
			}
			// If prompt is door
			else if (prompt == "door") {
				cout << endl;
				if (!data.visited) {
					// Allow to enter code if puzzle solved is at least 4
					if (puzzles_solved >= 4) {
						output("Enter door code: ");
						getline(cin, prompt);
						if (prompt == door_lock) {
							// Update values in struct before returning
							data.puzzles_completed = puzzles_solved;
							data.puzzles_failed = puzzles_failed;
							data.visited = true;
							return 3;
						}
						else {
							cout << endl;
							output("Incorrect combination.");
							pause();
						}
					}
					else {
						output("Complete at least 4 puzzles to be able to unlock door.");
						pause();
					}
				}
				else {
					data.puzzles_completed = puzzles_solved;
					data.puzzles_failed = puzzles_failed;
					return 3;
				}
			}
			else if (prompt == "path") {
				cout << endl;
				output("The guards' bodies lie scattered in the hallway. You proceed to the door on the other side.");
				pause();
				// Update values in struct before returning
				data.puzzles_completed = puzzles_solved;
				data.puzzles_failed = puzzles_failed;
				data.door_lock = door_lock;
				return 0;
			}
			// If prompt is switch
			else {
				shadow = !shadow;
				repetition = false;
			}
		}
		// If in shadow world
		else {
			output("The world dissolves into shadow. When it comes into focus "
				"again, the room has drastically changed. A tombstone now "
				"replaces the compass. A long coffin lines one of the walls. "
				"One wall is covered in eerie drawings.", output_speed);
			separator();

			repetition = true;

			// Input prompt and ensure it is valid
			string choices[] = { "tombstone", "coffin", "drawings", "switch" };
			output("prompt: ");
			getline(cin, prompt);
			prompt = string_lower(prompt);
			while (!check_input(prompt, choices, 4)) {
				cout << endl << endl;
				output("\tInvalid prompt. Try again.");
				pause;
				cout << "\x1b[2K" << "\x1b[F";
				cout << "\x1b[2K" << "\x1b[F";
				cout << "\x1b[2K" << "\x1b[F";
				cout << "\x1b[2K";

				output("prompt: ");
				getline(cin, prompt);
				prompt = string_lower(prompt);
			}

			// If prompt is tombstone
			if (prompt == "tombstone") {
				cout << endl;
				output("You can hear faint whispers coming from the grave.");
				// Allow to access puzzle if not previously attempted
				if (!data.puzzle_states[3]) {
					cout << endl;
					output("This will activate a puzzle. Are you sure you want to continue? ");;
					getline(cin, prompt);
					prompt = string_lower(prompt);
					if (prompt == "yes" || prompt == "y") {
						data.puzzle_states[3] = true;
						riddle = "I present myself every 4 years. In the shadows, I leap in despair. What number am I?";
						puzzle_solved = puzzle(riddle, "29");
						if (puzzle_solved) {
							cout << endl;
							if (puzzles_solved < 4) {
								output("The second digit is one of the digits to the door lock.");
								door_lock[puzzles_solved] = '9';
							}
							else {
								output("Congrats! You solved the puzzle.");
							}
							puzzles_solved++;
							pause();
						}
						else {
							cout << endl;
							output("You failed the puzzle. You lose 20 health.");
							puzzles_failed++;
							pause();
							player_health -= 20;
						}
					}
				}
				// Reject if puzzle is already attempted
				else {
					cout << endl;
					output("You have already attempted this puzzle.");
					pause();
				}
			}
			// If prompt is drawings
			else if (prompt == "drawings") {
				cout << endl;
				output("The drawings seem to be from someone called Tenebris. They contain his signature and a quote.");
				// Allow to access puzzle if not previously attempted
				if (!data.puzzle_states[4]) {
					cout << endl;
					output("This will activate a puzzle. Are you sure you want to continue? ");;
					getline(cin, prompt);
					prompt = string_lower(prompt);
					if (prompt == "yes" || prompt == "y") {
						data.puzzle_states[4] = true;
						riddle = "I may be upside down, nobody knows. But I'm always told to be benign. "
							"What number am I?";
						puzzle_solved = puzzle(riddle, "9");
						if (puzzle_solved) {
							cout << endl;
							if (puzzles_solved < 4) {
								output("This is one of the digits to the door lock.");
								door_lock[puzzles_solved] = '9';
							}
							else {
								output("Congrats! You solved the puzzle.");
							}
							puzzles_solved++;
							pause();
						}
						else {
							cout << endl;
							output("You failed the puzzle. You lose 20 health.");
							puzzles_failed++;
							pause();
							player_health -= 20;
						}
					}
				}
				// Reject if puzzle is already attempted
				else {
					cout << endl;
					output("You have already attempted this puzzle.");
					pause();
				}
			}
			// If prompt is coffin
			else if (prompt == "coffin") {
				cout << endl;
				output("An incantation is imposed on the smooth marble of the coffin.");
				// Allow to access puzzle if not previously attempted
				if (!data.puzzle_states[5]) {
					cout << endl;
					output("This will activate a puzzle. Are you sure you want to continue? ");;
					getline(cin, prompt);
					prompt = string_lower(prompt);
					if (prompt == "yes" || prompt == "y") {
						data.puzzle_states[5] = true;
						riddle = "Say the first 3 alphabets and you will find me. What number am I?";
						puzzle_solved = puzzle(riddle, "123");
						if (puzzle_solved) {
							cout << endl;
							if (puzzles_solved < 4) {
								output("The third digit is one of the digits to the door lock.");
								door_lock[puzzles_solved] = '3';
							}
							else {
								output("Congrats! You solved the puzzle.");
							}
							puzzles_solved++;
							pause();
						}
						else {
							cout << endl;
							output("You failed the puzzle. You lose 20 health.");
							puzzles_failed++;
							pause();
							player_health -= 20;
						}
					}
				}
				// Reject if puzzle is already attempted
				else {
					cout << endl;
					output("You have already attempted this puzzle.");
					pause();
				}
			}
			// If prompt is switch
			else {
				shadow = !shadow;
				repetition = false;
			}
		}
	}
}

int river(int* player_health, vector<Section> sections) {

	string prompt;
	bool shadow = false;
	bool repetition = false;
	int output_speed;
	int total_puzzles_completed;

	while (true) {
		clear();

		if (repetition)
			output_speed = 0;
		else
			output_speed = 50;

		if (!shadow) {
			output("The sound of rushing water fills your ears. "
				"A wide river roars in front of you, it's angry waves crashing into "
				"the riverside. And another sound: something strange. It sounds "
				"like harsh whispers in the air. To your left, a haunting road leads to a graveyard. "
				"To your right, a road thick with foliage leads to a dense forest. In front of you looms"
				" a massive castle. A door leads back the guard room. Pick your road.", output_speed);
			separator();

			repetition = true;

			// Input prompt and ensure it is valid
			string choices[] = { "graveyard", "forest", "castle", "switch", "door" };
			output("prompt: ");
			getline(cin, prompt);
			prompt = string_lower(prompt);
			while (!check_input(prompt, choices, 5)) {
				cout << endl << endl;
				output("\tInvalid prompt. Try again.");
				pause;
				cout << "\x1b[2K" << "\x1b[F";
				cout << "\x1b[2K" << "\x1b[F";
				cout << "\x1b[2K" << "\x1b[F";
				cout << "\x1b[2K";

				output("prompt: ");
				getline(cin, prompt);
				prompt = string_lower(prompt);
			}

			// If prompt is forest
			if (prompt == "forest") {
				return 4;
			}

			// If prompt is castle
			else if (prompt == "castle") {
				cout << endl;
				output("Once you go past this point, you can not head back. Are you sure you want to continue? ");
				getline(cin, prompt);
				prompt = string_lower(prompt);
				if (prompt == "yes" || prompt == "y") {
					return 5;
				}
			}

			// If prompt is graveyard
			else if (prompt == "graveyard") {
				cout << endl;
				total_puzzles_completed = sections[0].puzzles_completed + sections[1].puzzles_completed + sections[2].puzzles_completed;
				if (total_puzzles_completed == 13) {
					return 6;
				}
				else {
					output("Your aura is not strong enough to go down this path.");
					pause();
				}
			}

			// If prompt is door
			else if (prompt == "door") {
				return 2;
			}

			// If prompt is switch
			else {
				shadow = !shadow;
				repetition = false;
			}
		}

		// If in shadow world
		else {
			output("The world is dark except for loud whispers in the air. "
				"A purple light seems to be emanating from the left path, "
				"the gate glowing brightly. A slight green light illuminates the "
				"right path, long poles visible in the distance.", output_speed);
			separator();

			repetition = true;

			// Input prompt and ensure it is valid
			string choices[] = { "switch" };
			output("prompt: ");
			getline(cin, prompt);
			prompt = string_lower(prompt);
			while (!check_input(prompt, choices, 1)) {
				cout << endl << endl;
				output("\tSwitch back to real world to choose a path.");
				pause;
				cout << "\x1b[2K" << "\x1b[F";
				cout << "\x1b[2K" << "\x1b[F";
				cout << "\x1b[2K" << "\x1b[F";
				cout << "\x1b[2K";

				output("prompt: ");
				getline(cin, prompt);
				prompt = string_lower(prompt);
			}

			// If prompt is switch
			shadow = !shadow;
			repetition = false;
		}
	}
}

int castle(int* player_health) {

	clear();
	output("You cross the river with sheer determination. The walls of the tower loom over you. "
		"You take a deep breath and enter the castle. ");
	pause();

	clear();
	output("The inside of the castle is heavily decorated with antiques and dark items. A skull hangs above the fire place. "
		"A bear rug decorates the living quarters. An altar stands in the corner. Steep stairs lead up to a wide door. ");
	pause();

	clear();
	output("Ascending the stairs, the throne room reveals itself, a battleground between light and shadow. King Tenebris"
		" awaits, his shadowy form contrasting with the gleam of the throne.");
	pause();

	clear();
	output("King Tenebris: \"So, you have come to challenge the shadows that bind this realm. Prepare for a confrontation "
		"that transcends the dance of light and darkness. And don't you forget. It is I who forged your existence, from the "
		"mixture of human and shadow. Prepare for your final fight young shadowbound.\"");
	pause();
	clear();

	combat(player_health, 50);

	if (*player_health < 0) {
		return -1;
	}

	clear();
	output("And so, the corrupt king was defeated and prosperity returned to the kingdom of Shadowvale. This was the story "
		"of a shadowbound who escaped his fate and broke the eternal loop of darkness.");
	pause();
	clear();

	cout << R"(
___________           .___.__                 _________                       .__          __          
\_   _____/ ____    __| _/|__| ____    ____   \_   ___ \  ____   _____ ______ |  |   _____/  |_  ____  
 |    __)_ /    \  / __ | |  |/    \  / ___\  /    \  \/ /  _ \ /     \\____ \|  | _/ __ \   __\/ __ \ 
 |        \   |  \/ /_/ | |  |   |  \/ /_/  > \     \___(  <_> )  Y Y  \  |_> >  |_\  ___/|  | \  ___/ 
/_______  /___|  /\____ | |__|___|  /\___  /   \______  /\____/|__|_|  /   __/|____/\___  >__|  \___  >
        \/     \/      \/         \//_____/           \/             \/|__|             \/          \/ 
)";
	cout << endl << endl;

	return 100;
}

int graveyard(int* player_health) {

	clear();
	output("You wander into the graveyard. Mounds of dirt line both sides. Weird shaped tombstones rise from the mounds. "
		"The energy here is so powerful its making your head hurt. Two stone pillars stand on the opposite end. "
		"You approach the pillars. A loud bang is heard and a dark black shadow spawns in front of you.");
	pause();
	clear();

	output("Shadow Boss: *growls menacingly* \"I have been awaiting you shadowbound, for it is I who brought you into existence"
		". The submissive King was quick to follow my orders and you were concieved. How fitting it is, that you should die at the "
		"place you were born.\"");
	pause();
	clear();

	output("Shadow Boss: \"Now now. Don't be scared for I shall be the last foe you fight.\"");
	pause();
	clear();

	combat(player_health, 50);

	if (*player_health < 0) {
		return -1;
	}

	clear();
	output("The Shadow Boss was defeated and along with him, the realm of Nox Aeterna collapsed. Residents of "
	"Shadowvale sensed a positive change in the aura of the kingdom and the once mad King Tenebris suddenly regained sanity."
	" Thank you brave shadowbound for liberating this kingdom from dark influence. We shall forever be grateful.");
	pause();
	clear();

	cout << R"(
___________           .___.__                 _________                       .__          __          
\_   _____/ ____    __| _/|__| ____    ____   \_   ___ \  ____   _____ ______ |  |   _____/  |_  ____  
 |    __)_ /    \  / __ | |  |/    \  / ___\  /    \  \/ /  _ \ /     \\____ \|  | _/ __ \   __\/ __ \ 
 |        \   |  \/ /_/ | |  |   |  \/ /_/  > \     \___(  <_> )  Y Y  \  |_> >  |_\  ___/|  | \  ___/ 
/_______  /___|  /\____ | |__|___|  /\___  /   \______  /\____/|__|_|  /   __/|____/\___  >__|  \___  >
        \/     \/      \/         \//_____/           \/             \/|__|             \/          \/ 
)";
	cout << endl << endl;

	return 100;
}

int forest(int* player_health, Section& data) {

	string prompt, riddle;
	bool puzzle_solved;

	bool shadow = false;
	bool mist = false; // Initialize mist status
	bool repetition = false;
	int output_speed;

	// Initialize puzzle values
	int puzzles_solved = data.puzzles_completed;
	int puzzles_failed = data.puzzles_failed;
	int attempts;

	clear();
	while (true) {
		clear();

		// End game if player ran out of health
		if (*player_health < 0)
			return -1;

		if (repetition)
			output_speed = 0;
		else
			output_speed = 50;

		if (!shadow) {
			output("You hear "
				"whispers when venturing through a maze of shadows "
				"along with strange glyphs on a tree which seem to be "
				"emanating a dark aura. Amidst the midst, you see a faint "
				"beaming source of light, almost as if the moonlight is "
				"being reflected from some surface. Every step echoes "
				"through the shadows, leading you deeper into the unknown. "
				"A trail leads back to the river.", output_speed);
			separator();

			repetition = true;

			// Input prompt and ensure it is valid
			string choices[] = { "glyphs", "moonlight", "whispers", "switch", "river"};
			output("prompt: ");
			getline(cin, prompt);
			prompt = string_lower(prompt);
			while (!check_input(prompt, choices, 5)) {
				cout << endl << endl;
				output("\tInvalid prompt. Try again.");
				pause;
				cout << "\x1b[2K" << "\x1b[F";
				cout << "\x1b[2K" << "\x1b[F";
				cout << "\x1b[2K" << "\x1b[F";
				cout << "\x1b[2K";

				output("prompt: ");
				getline(cin, prompt);
				prompt = string_lower(prompt);
			}

			// If prompt is glyphs
			if (prompt == "glyphs") {
				cout << endl;
				// Allow to access puzzle if not previously attempted
				if (!data.puzzle_states[0]) {
					data.puzzle_states[0] = true;
					output("In the ancient grove where shadows wend, "
						"Glyphs on bark, a celestial blend. "
						"No words to speak, nor tale to tell, "
						"Decipher the dance, the moonlight's spell. "

						"Twilight whispers, a subtle cue, "
						"Order them right, the path you'll strew. "
						"A lunar code in shadows spun, "
						"Read the glyphs beneath the moon, as one. ");
					cout << endl;
					output("Decipher the glyphs to uncover the correct path: ");
					getline(cin, prompt);
					transform(prompt.begin(), prompt.end(), prompt.begin(), ::toupper); // Convert to uppercase for case-insensitive comparison
					if (prompt == "LUNAR") {
						cout << endl;
						output("The shadows respond. You feel your aura strengthening.");
						puzzles_solved++;
						pause();
					}
					else {
						cout << endl;
						output("The glyphs pulsate briefly, but the path remains obscured.");
						cout << endl;
						output("10 health has been deducted.");
						puzzles_failed++;
						pause();
						*player_health -= 10;
					}
				}
				// Reject if puzzle is already attempted
				else {
					cout << endl;
					output("You have already attempted this puzzle.");
					pause();
				}
			}
			// If prompt is mirrors
			else if (prompt == "moonlight") {
				cout << endl;
				if (!data.puzzle_states[1]) {
					data.puzzle_states[1] = true;
					output("In the mystic grove, beneath the moon's soft gaze, "
						"Reflective mirrors in an ancient dance, ablaze. "
						"Arrange them true, in harmony they'll glow, "
						"Unveiling secrets that only shadows know. "

						"First mirror, the second of the lunar light, "
						"In its silvered grasp, cradle the gentle night. "
						"Atop the sequence, it shall claim its place, "
						"In the moon's reflection, seek its embrace. "

						"Next mirror, the fourth in the celestial array, "
						"Beside its kin, the night's brilliance portray. "
						"Counting from one, in the dance of night, "
						"Hold its gleam, bathed in soft moonlight. "

						"The third, the final, take its place with grace, "
						"Where the first reflects the moon's embrace. "
						"Count but once, then twice, in the moonlit play, "
						"Beside the second, it shall find its way. "

						"Let the mirrors align in lunar accord, "
						"In this sequence, secrets shall be stored. "
						"By the moon's guidance, in the night's sweet trance, "
						"Arrange them, and unlock the moonlit dance");
					cout << endl << endl;
					// Initialize mirror positions
					int mirrorPositions[3];

					for (int i = 0; i < 3; ++i) {
						cout << "\t\t\t\tEnter position for mirror " << i + 1 << " (1 to 5): ";
						cin >> mirrorPositions[i];
					}

					// Check if mirrors are in the correct sequence
					if (mirrorPositions[0] == 2 && mirrorPositions[1] == 4 && mirrorPositions[2] == 1) {
						cout << endl;
						output("The path glows with moonlight. You feel your aura strengthening.");
						puzzles_solved++;
						pause();
					}
					else {
						cout << endl;
						output("The moonlight flickers, and the path remains dim.");
						cout << endl;
						output("10 health has been deducted.");
						puzzles_failed++;
						pause();
						*player_health -= 10;
					}
				}
				// Reject if puzzle is already attempted
				else {
					cout << endl;
					output("You have already attempted this puzzle.");
					pause();
				}
			}
			// If prompt is whispers
			if (prompt == "whispers") {
				cout << endl;
				output("The voices are trying to tell you something.");
				// Allow to access puzzle if not previously attempted
				if (!data.puzzle_states[2]) {
					cout << endl;
					output("This will activate a puzzle. Are you sure you want to continue? ");;
					getline(cin, prompt);
					prompt = string_lower(prompt);
					if (prompt == "yes" || prompt == "y") {
						data.puzzle_states[2] = true;
						riddle = "Eternal and unyielding, I move without haste. Hands circle me in timeless embrace. What am I?";
						puzzle_solved = puzzle(riddle, "clock");
						if (puzzle_solved) {
							cout << endl;
							output("You solved it. You feel your aura strengthening.");
							puzzles_solved++;
							pause();
						}
						else {
							cout << endl;
							output("You failed the puzzle. You lose 10 health.");
							puzzles_failed++;
							pause();
							player_health -= 10;
						}
					}
				}
				// Reject if puzzle is already attempted
				else {
					cout << endl;
					output("You have already attempted this puzzle.");
					pause();
				}
			}
			else if (prompt == "river") {
				data.puzzles_completed = puzzles_solved;
				data.puzzles_failed = puzzles_failed;
				return 3;
			}
			// If prompt is switch
			else {
				if (puzzles_solved == 3 && !mist) {
					output("As you solve the last puzzle, "
						"the forest is engulfed in mist. The mist clears away, "
						"revealing a path ahead.");
					mist = true; // Set mist status to true
					pause();
				}
			}
		}
	}
}