#include <iostream>
#include <vector>
#include <string>

using namespace std;

const char EMPTY = ' ';
const char X = 'x', O = 'o';
const char NO_ONE = 'N';
const char TIE = 'T';
const int NUM_SQUARES = 9;

void instrution();
char PlayerSymbol();
char Opponent(char b);
char AskYesNo(string question);
char winner(vector<char>& board);
int playerMove(char Player, char Computer, vector<char>& board);
bool IsLegal(int numb, char player, char computer, vector<char>& board);

int main()
{
	setlocale(LC_ALL, "spanish");
	vector<char> board(NUM_SQUARES,	EMPTY);

	cout << "Bienvenido a Gato >w<, eligue una da las posiciones vacias entre 0 y 8 OwO" << endl;
	instrution();
	cout << "\nBuena Suerte chaval@ \n";
	char player = PlayerSymbol();
	char computer = Opponent(player);
	char turn = X;
	playerMove(player, computer, board);
}

int askNumber(string question, int high, int low)
{
	string input;
	bool isValid = false;
	bool isRangeValid = false;
	int number = 0;

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	do {
		cout << question << "entre " << low << " y " << high << endl;

		getline(cin, input);

		for (char c : input)
		{
			if (!isdigit(c))
			{
				isValid = false;
				break;
			}
			else
			{
				isValid = true;
				break;
			}
		}

		if (!isValid)
		{
			cout << "\nEntrada inválida, por favor elige solo números.\n";
		}
		else
		{
			number = stoi(input);
			isRangeValid = number <= high && number >= low;
		}

		if (!isRangeValid && isValid)
		{
			cout << "\nEntrada inválida, elige un número dentro del rango establecido.\n";
		}

	} while (!isValid || input.empty() || !isRangeValid);

	return number;
}

void DisplayBoard(vector<char>& board)
{
	for (int i = 0; i < board.size(); i++)
	{
		if (i == 2 || i == 5 || i == 8)
		{
			if (board[i] == ' ')
			{
				cout << " " << i << "\n";
			}
			else
			{
				cout << " " << board[i] << "\n";

			}
		}
		else
		{
			if (board[i] == ' ')
			{
				cout << " " << i << " |";

			}
			else
			{
				cout << " " << board[i] << " |";
			}
		}
	}
}


int playerMove(char Player, char Computer, vector<char>& board)
{
	int numb = askNumber("Eligue el lugar del tablero", 9, 0);
	bool TurnA = false;

	while (TurnA == false)
	{
		TurnA = IsLegal(numb, Player, Computer, board);
	}

}

bool IsLegal(int numb, char player, char computer, vector<char>& board)
{
	if (board[numb] != computer)
	{
		if (player == X)
		{
			if (board[numb] != X)
			{
				board[numb] = X;
				return true;
			}
		}
		else if (player == O)
		{
			if (board[numb] != O)
			{
				board[numb] = O;
				return true;
			}
		}
	}
}

char winner(vector<char>& board)
{
	//Son todas las posibilidades para ganar
	const int WINNING_POS[8][3] = { {0, 1, 2},
									{3, 4, 5},
									{6, 7, 8},
									{0, 3, 6},
									{1, 4, 7},
									{2, 5, 8},
									{2, 4, 6},
									{0, 4, 8}, };

	const int TOTAL_ROWS = 8;

	for (int row = 0; row < TOTAL_ROWS; row++)
	{

		if ((board[WINNING_POS[row][0]] != EMPTY) && 
			(board[WINNING_POS[row][0]] == board[WINNING_POS[row][1]]) && 
			(board[WINNING_POS[row][1]] == board[WINNING_POS[row][2]]))
		{
			return board[WINNING_POS[row][0]];

		}
	}


	if (count(board.begin(), board.end(), EMPTY) == 0) 
	{
		return TIE;
	}

	return NO_ONE;
}

void instrution()
{
	cout << "|1|2|3|\n";
	cout << "|4|5|6|\n";
	cout << "|7|8|9|\n";
}

char PlayerSymbol()
{
	char gofirst = AskYesNo("¿Quieres comenzar primero");
	char b;
	if (gofirst == 'y')
	{
		b = X;
		return b;
	}
	else
	{
		b = O;
		return b;
	}
	return b;
}

char Opponent(char b)
{
	if (b == X)
	{
		return O;
	}
	else
	{
		return X;
	}
}

char AskYesNo(string question)
{
	char answer;
	do {
		cout << "\n" << question << "(y/n)";
		cin >> answer;
	} while (answer != 'y' && answer != 'n');
	return answer;
}