#include <stdio.h>
#include <windows.h>
#include<stdlib.h>
#include<unistd.h>

#define WIDTH 30
#define HEIGHT 50
#define DELAY_MS 100

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printBoard(int board[][WIDTH]) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", board[i][j] ? '#' : ' ');
        }
        printf("\n");
    }
}

int countNeighbors(int board[][WIDTH], int x, int y) {
    int count = 0;
    int dx, dy;
    for (dx = -1; dx <= 1; dx++) {
        for (dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT && board[ny][nx]) {
                count++;
            }
        }
    }
    return count;
}

void updateBoard(int board[][WIDTH]) {
    int newBoard[HEIGHT][WIDTH];
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int neighbors = countNeighbors(board, j, i);
            if (board[i][j]) {
                if (neighbors < 2 || neighbors > 3) {
                    newBoard[i][j] = 0;
                } else {
                    newBoard[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    newBoard[i][j] = 1;
                } else {
                    newBoard[i][j] = 0;
                }
            }
        }
    }
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}

int main() {
    int board[HEIGHT][WIDTH] = {0}; // Initialize board to all zeros

 // Glider pattern example
    board[1][2] = 1;
    board[4][5] = 1;
    board[5][6] = 1;
    board[6][7] = 1;
    board[6][6] = 1;
    board[6][5] = 1;
    board[1][2] = 1;
    // board[2][3] = 1;
    // board[3][1] = 1;
    // board[3][2] = 1;
    // board[3][3] = 1;
    // board[4][5] = 1;
    // board[5][6] = 1;
    // board[6][7] = 1;
    // board[3][2] = 1;
    // board[6][6] = 1;
    // board[3][2] = 1;
    // board[5][6] = 1;
    // board[4][5] = 1;
    // board[6][5] = 1;
    // board[2][3] = 1;
    // board[6][7] = 1;
    // board[6][6] = 1;
    // board[1][2] = 1;
    // board[2][3] = 1;
    // board[6][5] = 1;
    // board[3][1] = 1;
    // board[6][7] = 1;
    // board[3][3] = 1;
    // board[4][5] = 1;
    // board[3][1] = 1;
    // board[3][3] = 1;
    // board[5][6] = 1;
    // board[1][2] = 1;
    // board[6][6] = 1;
    // board[6][5] = 1;

    // board[7][2] = 1;
    // board[8][3] = 1;
    // board[6][1] = 1;
    // board[4][2] = 1;
    // board[4][3] = 1;
    // board[3][5] = 1;
    // board[2][6] = 1;
    // board[8][7] = 1;
    // board[2][6] = 1;
    // board[6][5] = 1;
    // board[4][2] = 1;
    // board[6][3] = 1;
    // board[3][1] = 1;
    // board[3][2] = 1;
    // board[3][3] = 1;
    // board[4][5] = 1;
    // board[5][6] = 1;
    // board[6][7] = 1;
    // board[3][2] = 1;
    // board[6][6] = 1;
    // board[3][2] = 1;
    // board[5][6] = 1;
    // board[4][5] = 1;
    // board[6][5] = 1;
    // board[2][3] = 1;
    // board[6][7] = 1;
    // board[6][6] = 1;
    // board[1][2] = 1;
    // board[2][3] = 1;
    // board[6][5] = 1;
    // board[3][1] = 1;
    // board[6][7] = 1;
    // board[3][3] = 1;
    // board[4][5] = 1;
    // board[3][1] = 1;
    // board[3][3] = 1;
    // board[5][6] = 1;
    // board[1][2] = 1;
    // board[6][6] = 1;
    // board[6][5] = 1;


    while (1) {
        system("cls"); // Clear the console
        printBoard(board);
        updateBoard(board);
        Sleep(DELAY_MS); // Sleep for a short delay
    }
    return 0;
}