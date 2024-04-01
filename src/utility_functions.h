using namespace std;

void output(string output_text, int speed = 50, bool line_break = true) {
	const int WIDTH = 65; // maxiumum row size

	cout << "\t\t\t ";

	// Output text with a pause of 50 ms
	int length = output_text.size();


	for (int i = 0; i < length; i++) {
		if (line_break) {
			if (i % WIDTH == 0 && i != 0) {
				if (output_text[i] == ' ') {
					cout << endl;
					cout << "\t\t\t";
				}

				// Handling edge case where character before newline is not a whitespace
				else {
					int counter = 0;
					for (int j = 0; output_text[i + j] != ' '; j++) {
						counter++;
					}

					for (int j = 0; j <= counter; j++) {
						cout << output_text[i + j];
						this_thread::sleep_for(chrono::milliseconds(speed));
					}
					cout << endl;
					cout << "\t\t\t";

					i += counter;
				}
			}
		}

		cout << output_text[i];
		this_thread::sleep_for(chrono::milliseconds(speed));
	}
}


void clear() {
	cout << "\x1B[2J\x1B[H"; // clear screen
	cout << endl;
}

void pause() {
	cout << endl << endl << endl << "\t\t\t";
	system("PAUSE");
}

void separator() {
	cout << "\n\n\t\t\t--------------------------------------------------------------------------";
	cout << endl << endl;
}

bool puzzle(string question, string answer) {
	int incorrect_answers = 0;
	clear();
	output(question);
	cout << endl << endl;
	output("answer: ");
	string response;
	getline(cin, response);
	while (response != answer) {
		incorrect_answers++;
		output("Incorrect! You have " + to_string(3 - incorrect_answers) + " attempts remaining.");
		pause();

		cout << "\x1b[2K" << "\x1b[F";
		cout << "\x1b[2K" << "\x1b[F";
		cout << "\x1b[2K" << "\x1b[F";
		cout << "\x1b[2K" << "\x1b[F";
		cout << "\x1b[2K" << "\x1b[F";
		cout << "\x1b[2K";

		output("answer: ");
		getline(cin, response);

		if (incorrect_answers == 2) {
			return false;
		}
	}
	cout << endl;
	return true;
}

bool check_integer(string input, int lower, int upper) {
	// Loop through each index of the string and check if its a digit
	for (int i = 0; i < input.length(); i++) {
		// if non-numeric character found
		if (isdigit(input[i]) == false) {
			output("\t\tInput is not a number");
			return false;
		}
	}

	int int_input = stoi(input);

	// Reject out of bounds input
	if (int_input < lower || int_input > upper) {
		output("\t\tOut of bounds. Pick number between " + to_string(lower) + '-' + to_string(upper));
		return false;
	}

	return true;
}

bool check_mana(int input, float* mana) {
	if (input > *mana) {
		output("\t\tNumber is greater than mana. You are too tired.");
		return false;
	}

	return true;
}

int generate_int(int lower, int upper) {
	return rand() % (upper - lower + 1) + lower;
}

string generate_opponent_choice(int opponent_mana) {
	// Opponent only rests if mana < 10
	int number;
	if (opponent_mana < 10)
		number = generate_int(1, 3);
	// Opponent can only rest if mana = 0
	else if (opponent_mana < 1)
		number = 3;
	// Attack or defend if mana > 10
	else
		number = generate_int(1, 2);

	switch (number) {
	case 1:
		return "attack";
	case 2:
		return "defend";
	case 3:
		return "rest";
	}
}

bool check_input(string input, string* choices, int total_choices) {
	// Iterate through choices and compare
	for (int i = 0; i < total_choices; i++) {
		if (input == choices[i])
			return true;
	}

	return false;
}

string string_lower(string str) {
	// Iterate through each character and convert it to lowercase
	for (int i = 0; i < str.size(); i++) {
		str[i] = tolower(str[i]);
	}

	return str;
}

