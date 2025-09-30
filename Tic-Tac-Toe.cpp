#include<iostream>
#include<limits>
#include<string>

using namespace std;

char x[3][3] = { 0 };
const int SIZE = 3;
char board[SIZE][SIZE];

void initializeBoard() {
	for (int i = 0; i < SIZE; ++i)
		for (int j = 0; j < SIZE; ++j)
			board[i][j] = ' ';
}

void printBoard() {
	system("cls");
	cout << "\n";
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			cout << "  " << board[i][j] << "  ";
			if (j < 2) cout << "|";
		}
		cout << "\n";
		if (i < SIZE - 1) cout << "-----+-----+-----\n";
	}
	cout << "\n";
}

char checkWinner() {
	for (int i = 0; i < SIZE; ++i) {
		if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
			return board[i][0];
		if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
			return board[0][i];
	}
	
	if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return board[0][0];
	if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return board[0][2];

	return ' ';
}

bool isBoardFull() {
	for (int i = 0; i < SIZE; ++i)
		for (int j = 0; j < SIZE; ++j)
			if (board[i][j] == ' ') return false;
	return true;
}

int minimax(bool isMaximizing) {
	char winner = checkWinner();
	if (winner == 'O') return 1;
	if (winner == 'X') return -1;
	if (isBoardFull()) return 0;

	if (isMaximizing) {
		int bestScore = numeric_limits<int>::min();
		for (int i = 0; i < SIZE; ++i)
			for (int j = 0; j < SIZE; ++j)
				if (board[i][j] == ' ') {
					board[i][j] = 'O';
					int score = minimax(false);
					board[i][j] = ' ';
					bestScore = max(score, bestScore);
				}
		return bestScore;
	}
	else {
		int bestScore = numeric_limits<int>::max();
		for (int i = 0; i < SIZE; ++i)
			for (int j = 0; j < SIZE; ++j)
				if (board[i][j] == ' ') {
					board[i][j] = 'X';
					int score = minimax(true);
					board[i][j] = ' ';
					bestScore = min(score, bestScore);
				}
		return bestScore;
	}
}

void computerMove() {
	int bestScore = numeric_limits<int>::min();
	int moveRow = -1, moveCol = -1;
	for (int i = 0; i < SIZE; ++i)
		for (int j = 0; j < SIZE; ++j)
			if (board[i][j] == ' ') {
				board[i][j] = 'O';
				int score = minimax(false);
				board[i][j] = ' ';
				if (score > bestScore) {
					bestScore = score;
					moveRow = i;
					moveCol = j;
				}
			}
	board[moveRow][moveCol] = 'O';
}

void placeSymbol(char board[3][3], int pos, char symbol) {
	switch (pos) {
	case 1: board[0][0] = symbol; break;
	case 2: board[0][1] = symbol; break;
	case 3: board[0][2] = symbol; break;
	case 4: board[1][0] = symbol; break;
	case 5: board[1][1] = symbol; break;
	case 6: board[1][2] = symbol; break;
	case 7: board[2][0] = symbol; break;
	case 8: board[2][1] = symbol; break;
	case 9: board[2][2] = symbol; break;
	}
}

void print(char x[3][3]) {
	system("cls");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "  " << x[i][j] << "  ";
			if (j < 2) cout << "|";
		}
		cout << endl;
		if (i < 2)
			cout << "-----+-----+-----" << endl;
	}
	cout << endl;
}

int check(char x[3][3], int& ch) {
	if ((x[0][0] == 'X' && x[0][1] == 'X' && x[0][2] == 'X') || (x[1][0] == 'X' && x[1][1] == 'X' && x[1][2] == 'X') || (x[2][0] == 'X' && x[2][1] == 'X' && x[2][2] == 'X') || (x[0][0] == 'X' && x[1][0] == 'X' && x[2][0] == 'X') || (x[0][1] == 'X' && x[1][1] == 'X' && x[2][1] == 'X') || (x[0][2] == 'X' && x[1][2] == 'X' && x[2][2] == 'X') || (x[0][0] == 'X' && x[1][1] == 'X' && x[2][2] == 'X') || (x[0][2] == 'X' && x[1][1] == 'X' && x[2][0] == 'X')) {
		cout << "Player_1 Wins !!\n\n";
		ch = 1;
		return 1;
	}
	else if ((x[0][0] == 'O' && x[0][1] == 'O' && x[0][2] == 'O') || (x[1][0] == 'O' && x[1][1] == 'O' && x[1][2] == 'O') || (x[2][0] == 'O' && x[2][1] == 'O' && x[2][2] == 'O') || (x[0][0] == 'O' && x[1][0] == 'O' && x[2][0] == 'O') || (x[0][1] == 'O' && x[1][1] == 'O' && x[2][1] == 'O') || (x[0][2] == 'O' && x[1][2] == 'O' && x[2][2] == 'O') || (x[0][0] == 'O' && x[1][1] == 'O' && x[2][2] == 'O') || (x[0][2] == 'O' && x[1][1] == 'O' && x[2][0] == 'O')) {
		cout << "Player_2 Wins !!\n\n";
		ch = 1;
		return 1;
	}
	return 1;
}

long long getValidInput(const string& prompt, int i) {
	long long input;
	while (true) {
		cin >> input;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
		}
		else {
			return input;
		}
		if (i == 1) {
			printBoard();
		}
		else if (i == 2) {
			print(x);
		}
		cout << prompt;
	}
}

void playerMove() {

	long long kkk;
	cout << "X : ";
	kkk = getValidInput("Check the pos again if itis wrong or the same\n\nX : ", 1);

	while (!(kkk == 1) && !(kkk == 2) && !(kkk == 3) && !(kkk == 4) && !(kkk == 5) && !(kkk == 6) && !(kkk == 7) && !(kkk == 8) && !(kkk == 9) || (!(kkk == 1 && board[0][0] == ' ') && !(kkk == 2 && board[0][1] == ' ') && !(kkk == 3 && board[0][2] == ' ') && !(kkk == 4 && board[1][0] == ' ') && !(kkk == 5 && board[1][1] == ' ') && !(kkk == 6 && board[1][2] == ' ') && !(kkk == 7 && board[2][0] == ' ') && !(kkk == 8 && board[2][1] == ' ') && !(kkk == 9 && board[2][2] == ' '))) {
		system("cls");
		printBoard();
		cout << "Check the pos again if itis wrong or the same\n\n";
		cout << "X : ";
		kkk = getValidInput("Check the pos again if itis wrong or the same\n\nX : ", 1);
	}
	placeSymbol(board, kkk, 'X');
}

int main() {

	string res;

	do {

		long long chosse, start, y[9], counter = 0;
		cout << "1. Player VS AI\n2. Player VS Player\nChoose number for the game mode : ";

		chosse = getValidInput("Errorr\n====================================\n1. Player VS AI\n2. Player VS Player\nChoose number for the game mode : ", 0);


		while (!(chosse == 1) && !(chosse == 2)) {
			system("cls");	
			cout << "Errorr\n====================================\n1. Player VS AI\n2. Player VS Player\nChoose number for the game mode : ";
			chosse = getValidInput("Errorr\n====================================\n1. Player VS AI\n2. Player VS Player\nChoose number for the game mode : ", 0);
		}

		if (chosse == 1) {
			system("cls");
			cout << "1. You\n2. AI\nchoose number for who would start : ";
			start = getValidInput("Errorr\n======================================\n1. You\n2. AI\nchoose number for who would start : ", 0);

			while (!(start == 1) && !(start == 2)) {
				system("cls");
				cout << "Errorr\n======================================\n1. You\n2. AI\nchoose number for who would start : ";
				start = getValidInput("Errorr\n======================================\n1. You\n2. AI\nchoose number for who would start : ", 0);
			}

			if (start == 1) {

				initializeBoard();
				printBoard();
				cout << endl << "enter num for pos" << endl << "ex : { 1 , 2 , 3 | \n     | 4 , 5 , 6 |\n     | 7 , 8 , 9 }\n\n";

				while (true) {
					playerMove();
					printBoard();
					if (checkWinner() == 'X') {
						cout << "X_wins !!\n\n";
						break;
					}
					if (isBoardFull()) {
						cout << "Draw !!\n\n";
						break;
					}

					cout << "computer turn...\n";
					computerMove();
					printBoard();
					if (checkWinner() == 'O') {
						cout << "AI_wins !!\n\n";
						break;
					}
					if (isBoardFull()) {
						cout << "Draw !!\n\n";
						break;
					}
				}
			}

			if (start == 2) {
				initializeBoard();
				printBoard();

				while (true) {
					cout << "computer turn...\n";
					computerMove();
					printBoard();
					if (checkWinner() == 'O') {
						cout << "AI_wins !!\n\n";
						break;
					}
					if (isBoardFull()) {
						cout << "Draw !!\n\n";
						break;
					}

					if (counter == 0)
					{
						cout << endl << "enter num for pos" << endl << "ex : { 1 , 2 , 3 | \n     | 4 , 5 , 6 |\n     | 7 , 8 , 9 }\n\n";
						counter++;
					}

					playerMove();
					printBoard();
					if (checkWinner() == 'X') {
						cout << "X_wins !!\n\n";
						break;
					}
					if (isBoardFull()) {
						cout << "Draw !!\n\n";
						break;
					}
				}
			}
		}

		if (chosse == 2)
		{
			for (int i = 0; i < 3; i++) {
				for (int c = 0; c < 3; c++)
					x[i][c] = '_';
			}
			print(x);
			cout << endl << "enter num for pos" << endl << "ex : { 1 , 2 , 3 | \n     | 4 , 5 , 6 |\n     | 7 , 8 , 9 }\n\n";

			int con = 2, ch = 0;

			for (int i = 0; i < 9; i++) {
				if (ch == 1) {
					break;
				}
				else {
					cout << "Player " << (con % 2) + 1 << " : ";

					con++;

					if (!(con % 2 == 0)) {
						y[i] = getValidInput("Check the pos again if itis wrong or the same\n\nPlayer 1 : ", 2);

						while (!(y[i] == 1 || y[i] == 2 || y[i] == 3 || y[i] == 4 || y[i] == 5 || y[i] == 6 || y[i] == 7 || y[i] == 8 || y[i] == 9) || (y[i] == y[i - 1] || y[i] == y[i - 2] || y[i] == y[i - 3] || y[i] == y[i - 4] || y[i] == y[i - 5] || y[i] == y[i - 6] || y[i] == y[i - 7] || y[i] == y[i - 8])) {
							system("cls");
							print(x);
							cout << "Check the pos again if itis wrong or the same\n\nPlayer 1 : ";
							y[i] = getValidInput("Check the pos again if itis wrong or the same\n\nPlayer 1 : ", 2);
						}
						placeSymbol(x, y[i], 'X');
						print(x);
						check(x, ch);
					}
					else {
						y[i] = getValidInput("Check the pos again if itis wrong or the same\n\nPlayer 2 : ", 2);
						while (!(y[i] == 1 || y[i] == 2 || y[i] == 3 || y[i] == 4 || y[i] == 5 || y[i] == 6 || y[i] == 7 || y[i] == 8 || y[i] == 9) || (y[i] == y[i - 1] || y[i] == y[i - 2] || y[i] == y[i - 3] || y[i] == y[i - 4] || y[i] == y[i - 5] || y[i] == y[i - 6] || y[i] == y[i - 7] || y[i] == y[i - 8]))
						{
							system("cls");
							print(x);
							cout << "Check the pos again if itis wrong or the same\n\nPlayer 2 : ";
							y[i] = getValidInput("Check the pos again if itis wrong or the same\n\nPlayer 2 : ", 2);
						}
						placeSymbol(x, y[i], 'O');
						print(x);
						check(x, ch);
					}
				}
			}
			if (!(ch == 1)) {
				cout << "Draw !!\n\n";
			}
		}

		cout << "Want to play again (type yes or no) : ";
		cin >> res;

		while (!(res == "yes" || res == "Yes" || res == "YEs" || res == "YeS" || res == "YES" || res == "yEs" || res == "yES" || res == "yeS" || res == "no" || res == "NO" || res == "No" || res == "nO")) {
			system("cls");
			cout << "Errorr\n";
			cout << "=========================================\n";
			cout << "Want to play again (type yes or no) : ";
			cin >> res;
		}

		system("cls");

	} while (res == "yes" || res == "Yes" || res == "YEs" || res == "YeS" || res == "YES" || res == "yEs" || res == "yES" || res == "yeS");

	cout << "GAME OVER..\n\n";

	return 0;
}