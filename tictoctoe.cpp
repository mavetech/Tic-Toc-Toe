#include <iostream>
using namespace std;

char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

void print_board()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

bool check_win(char player)
{
    // check rows
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player)
            return true;
    }
    // check columns
    for(int i=0;i<3;i++)
    {
        if(board[0][i]==player && board[1][i]==player && board[2][i]==player)
            return true;
    }
    // check diagonals
    if(board[0][0]==player && board[1][1]==player && board[2][2]==player)
        return true;
    if(board[0][2]==player && board[1][1]==player && board[2][0]==player)
        return true;
    return false;
}

int main()
{
    char player = 'X';
    while(true)
    {
        print_board();
        int row,col;
        cout << "Player " << player << ", enter your move (row col): ";
        cin >> row >> col;
        if(board[row][col] != ' ')
        {
            cout << "This space is already occupied. Try again." << endl;
            continue;
        }
        board[row][col] = player;
        if(check_win(player))
        {
            print_board();
            cout << "Player " << player << " wins!" << endl;
            break;
        }
        if(player == 'X')
            player = 'O';
        else
            player = 'X';
    }
    return 0;
}
