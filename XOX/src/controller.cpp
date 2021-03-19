#include "controller.h"

controller mainCont;

controller::controller() 
{

}

bool controller::anyEmpty()
{
    for (int row = 0; row < num; row++)
        for (int col = 0; col < num; col++)
            if (board[row][col] == ' ')
                return true;
    return false;
}

char controller::daWinner()
{
    char winner = 0;
    for (int i = 0; i < num; i++)
    {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) && !checkEmpty(i, 0)) { winner = board[i][0]; }
        else if ((board[0][i] == board[1][i] && board[1][i] == board[2][i]) && !checkEmpty(0, i)) { winner = board[0][i]; }
    }
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) && !checkEmpty(1, 1)) { winner = board[0][0]; }
    else if ((board[0][2] == board[1][1] && board[1][1] == board[2][0]) && !checkEmpty(1, 1)) { winner = board[0][2]; }

    if (winner != 0)
        return winner;
    else if (!mainCont.anyEmpty() && winner == 0) { return 't'; }
    else { return ' '; }
}

bool controller::checkEmpty(int row, int col)
{
    return board[row][col] == *(char*)" ";
}

void controller::HumanMove(int index)
{
    int row;
    int col;
    if (index <= 2) { row = 0; col = index; }
    else if (index <= 5) { row = 1; col = index - 3; }
    else if (index <= 8) { row = 2; col = index - 6; }

    board[row][col] = 'O';
}

int controller::FindBestMove(bool isMaximizing)
{
    char winner = daWinner();
    if (winner != ' ') {
        if (winner == 'X') { return 1; }
        else if (winner == 'O') { return -1; }
        else if (winner == 't') { return 0; }
    }
    if (isMaximizing)
    {
        int val = -100;
        for (int row = 0; row < num; row++)
            for (int col = 0; col < num; col++)
            {
                if (checkEmpty(row, col))
                {
                    board[row][col] = 'X';
                    val = std::max(val, FindBestMove(false));
                    board[row][col] = ' ';
                }

            }
        return val;
    }
    else {
        int val = +100;
        for (int row = 0; row < num; row++)
            for (int col = 0; col < num; col++)
            {
                if (checkEmpty(row, col))
                {
                    board[row][col] = 'O';
                    val = std::min(val, FindBestMove(true));
                    board[row][col] = ' ';
                }

            }
        return val;
    }
}

int controller::AIMove()
{
    int bestMove = -INT_MAX;
    int bestRow, bestCol;
    for (int row = 0; row < num; row++)
        for (int col = 0; col < num; col++) {
            if (checkEmpty(row, col)) {
                board[row][col] = 'X';
                int thing = std::max(bestMove, FindBestMove(false));
                board[row][col] = ' ';
                if (thing != bestMove) {
                    bestMove = thing;
                    bestRow = row;
                    bestCol = col;
                }

            }

        }
    board[bestRow][bestCol] = 'X';
    return (bestRow * 3) + bestCol;
}