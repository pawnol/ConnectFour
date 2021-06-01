#include <iostream>
using namespace std;

const string no_piece = "-";
const string red_piece = "R";
const string yellow_piece = "Y";

class Board
{
private:
    string board[6][7];

public:
    Board()
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                board[i][j] = no_piece;
            }
        }
    }

    bool dropPiece(int column, string color)
    {
        if (board[0][column] == red_piece
            || board[0][column] == yellow_piece)
        {
            return false;
        }
        for (int i = 1; i < 6; i++)
        {
            if (board[i][column] == red_piece
                || board[i][column] == yellow_piece)
            {
                board[i - 1][column] = color;
                return true;
            }
        }
        board[5][column] = color;
        return true;
    }

    bool checkIfWinner(string color)
    {
        for (int column = 0; column < 7; column++)
        {
            for (int row = 0; row < 3; row++)
            {
                if (board[row][column] == color 
                    && board[row + 1][column] == color 
                    && board[row + 2][column] == color 
                    && board[row + 3][column] == color)
                {
                    return true;
                }
            }
        }

        for (int row = 0; row < 6; row++)
        {
            for (int column = 0; column < 4; column++)
            {
                if (board[row][column] == color
                    && board[row][column + 1] == color
                    && board[row][column + 2] == color
                    && board[row][column + 3] == color)
                {
                    return true;
                }
            }
        }

        for (int row = 3; row < 6; row++)
        {
            for (int col = 0; col < 4; col++)
            {
                if (board[row][col] == color
                    && board[row - 1][col + 1] == color
                    && board[row - 2][col + 2] == color
                    && board[row - 3][col + 3] == color)
                {
                    return true;
                }
            }
        }

        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 4; col++)
            {
                if (board[row][col] == color
                    && board[row + 1][col + 1] == color
                    && board[row + 2][col + 2] == color
                    && board[row + 3][col + 3] == color)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool checkIfBoardFilled()
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                if (board[i][j] == no_piece)
                {
                    return false;
                }
            }
        }
        return true;
    }

    void print()
    {
        for (int i = 1; i <= 7; i++)
        {
            cout << i << " ";
        }
        cout << "\n";

        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    Board board;
    while (true)
    {
        int column;
        board.print();
        cout << "Red player's turn.\n";
        cout << "Enter the column number you want to place a piece >> ";
        cin >> column;
        while (column < 1 || 7 < column || !board.dropPiece(column - 1, red_piece))
        {
            cout << "Invalid input!\n";
            cout << "Re-enter the column number you want to place a piece >> ";
            cin >> column;
        }
        if (board.checkIfWinner(red_piece))
        {
            cout << "The red player has won!\n\n";
            break;
        }
        cout << "\n";
        
        board.print();
        cout << "Yellow player's turn.\n";
        cout << "Enter the column number you want to place a piece >> ";
        cin >> column;
        while (column < 1 || 7 < column || !board.dropPiece(column - 1, yellow_piece))
        {
            cout << "Invalid input!\n";
            cout << "Re-enter the column number you want to place a piece >> ";
            cin >> column;
        }
        if (board.checkIfWinner(yellow_piece))
        {
            cout << "The yellow player has won!\n\n";
            break;
        }
        cout << "\n";

        if (board.checkIfBoardFilled())
        {
            cout << "It was a tie!\n\n";
            break;
        }
    }
    board.print();
    return 0;
}
