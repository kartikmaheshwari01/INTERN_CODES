#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

void displayBoard() {
    cout << "Tic-Tac-Toe Board:\n";
    for (int i = 0; i < SIZE; ++i) 
	{
        for (int j = 0; j < SIZE; ++j) 
		{
            cout << board[i][j];
            if (j < SIZE - 1) 
			{
                cout << " | ";
            }
        }
        cout << endl;
        
        if (i < SIZE - 1) 
		{
            cout << "---------\n";
        }
    }
    cout << endl;
}

bool isValidMove(int row, int col) {
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ');
}

bool isBoardFull() 
{
    for (int i = 0; i < SIZE; ++i) 
	{
        for (int j = 0; j < SIZE; ++j) 
		{
            if (board[i][j] == ' ') 
			{
                return false;
            }
        }
    }
    return true;
}
//CODE
bool checkWin(char symbol) 
{
    for (int i = 0; i < SIZE; ++i) 
	{
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)) 
			{
            return true;
        }
    }
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) 
		{
        return true;
    }

    return false;
}

void resetBoard() 
{
    for (int i = 0; i < SIZE; ++i) 
	{
        for (int j = 0; j < SIZE; ++j) 
		{
            board[i][j] = ' ';
        }
    }
}

int main() 
{
    int row, col;
    char currentPlayer = 'X';
    char playAgain;

    do 
	{
        resetBoard();

        do 
		{
            displayBoard();

            cout << "Player " << currentPlayer << ", Enter your row (0-2): ";
            cin >> row;
            cout << "Player " << currentPlayer << ", Enter your column (0-2): ";
            cin >> col;

            if (isValidMove(row, col)) 
			{
                board[row][col] = currentPlayer;

                if (checkWin(currentPlayer)) 
				{
                    displayBoard();
                    cout << "Player " << currentPlayer << " wins!\n";
                    break;
                } else if (isBoardFull()) 
				{
                    displayBoard();
                    cout << "It's a tie!\n";
                    break;
                }

                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            } 
			else 
			{
                cout << "Invalid move. Try again.\n";
            }
        } 
		while (true);

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } 
	while (playAgain == 'y' || playAgain == 'Y');
    return 0;
}

