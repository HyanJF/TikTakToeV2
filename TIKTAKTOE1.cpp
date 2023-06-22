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
int Dado();
char ParesyNones(char& D);

int main()
{
	setlocale(LC_ALL, "spanish");
	vector<char> board(NUM_SQUARES, EMPTY);

	cout << "Matriz de Pares" << endl;
	int MatrizN[3][4] = { {2,3,1,4},
		{9,8,7,9},
		{3,2,1,5} };

	cout << "|2|3|1|4|\n";
	cout << "|9|8|7|9|\n";
	cout << "|3|2|1|5|\n";

	int MAux = 0, mAux = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (MatrizN[i][j] % 2 == 0)
			{
				cout << "La posicion " << i << " y " << j << " es par" << endl;
				MAux = MAux + MatrizN[i][j];
				mAux = mAux + ((i * 10)+ j);
			}
		}
	}
	cout << endl << "La suma de todos los pares es " << MAux << " y " << "La suma de sus posiciones es " << mAux << endl;
	cout << "La resta es " << MAux - mAux << endl << endl;

	cout << "Bienvenido a Gato >w<, eligue una da las posiciones vacias entre 0 y 8 OwO" << endl;
	instrution();
	cout << "\nBuena Suerte chaval@ \n" << endl;
	char player = PlayerSymbol();
	cout << player << endl;
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

	return numb;
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

char ParesyNones(char& D)
{
	int Aux = 0;
	char P = 'p', I = 'i';
	Aux = Dado();
	cout << Aux << endl;
		if (Aux % 2 == 0)
		{
			cout << "El valor es par" << endl;
			if (D = P)
			{
				return D;
			}
			else
			{
				D = I;
				return D;
			}
		}
		else if (Aux % 2 == 1)
		{
			cout << "El valor es impar" << endl;
			if (D == I)
			{
				D = P;
				return D;
			}
			else 
			{
				D = I;
				return D;
			}
		}
}

int Dado()
{ 
	int Number;
	srand(static_cast<unsigned int>(time(0)));
	Number = 1 + (rand() % 6);
	return Number;
}

void instrution()
{
	cout << "|1|2|3|\n";
	cout << "|4|5|6|\n";
	cout << "|7|8|9|\n";
}

char PlayerSymbol()
{
	cout << "Lanzaremos un dado, eligue tu valor" << endl;
	char gofirst = AskYesNo("¿Quieres par(p) o impar(i) ");
	char b;
	ParesyNones(gofirst);
	if (gofirst == 'p')
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
		cout << "\n" << question << "(p/i)" << endl;
		cin >> answer;
	} while (answer != 'p' && answer != 'i');
	return answer;
}