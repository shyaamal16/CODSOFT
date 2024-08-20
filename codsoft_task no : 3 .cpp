#include <iostream>

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentMarker;
int currentPlayer;

void drawBoard() {
    std::cout << "Player 1 [X]  Player 2 [O]\n\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    }
    return false;
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false;
}

void switchPlayer() {
    if (currentMarker == 'X') currentMarker = 'O';
    else currentMarker = 'X';

    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

void ticTacToe() {
    currentMarker = 'X';
    currentPlayer = 1;
    int slot;
    bool gameWon = false;

    drawBoard();

    for (int i = 0; i < 9; i++) {
        std::cout << "Player " << currentPlayer << "'s turn. Enter slot: ";
        std::cin >> slot;

        if (!placeMarker(slot)) {
            std::cout << "Slot already taken! Try another slot.\n";
            i--;
            continue;
        }

        drawBoard();

        if (checkWin()) {
            std::cout << "Player " << currentPlayer << " wins!\n";
            gameWon = true;
            break;
        }

        switchPlayer();
    }

    if (!gameWon) {
        std::cout << "It's a draw!\n";
    }
}

int main() {
    ticTacToe();
    return 0;
}
