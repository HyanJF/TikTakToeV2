#include <iostream>
#include <vector>
#include <string>

using namespace std;

const char EMPTY = ' ';
const char X = 'x', O = 'o';

void instrution();
char PlayerSymbol();
char Opponent(char b);
char AskYesNo(string question);
char winner(const vector<char>& board);

int main()
{
	vector<char> board(NUM_SQUARES, EMPTY)
	const int NUM_SQUARES = 9;
	int move;

	cout << "Bienvenido a Gato >w<, eligue una da las posiciones vacias entre 0 y 8 OwO" << endl;
	void instrution();
	char Player = PlayerSymbol();
	char Computer = Opponent(Player);
	char turn = X;

	while (winner(board))
	{

	}
}

char winner(const vector<char>& board)
{
	
}

void instrution(vector<char> n)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; i++)
		{
			n[i][j] = EMPTY;
			cout << n << endl;
		}
	}
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