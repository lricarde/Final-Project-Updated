//this is my final project for cgt 215 as i attempt to implement conways game of life
//updates made since checkpoint: second instance of for loop was removed
//grid size has been changed to a manageable size that shows all of the running code properly

#include <iostream>
#include <cstdlib>

const int GRIDSIZE = 30;

void Display(bool grid[GRIDSIZE + 1][GRIDSIZE + 1]) {
    for (int a = 1; a < GRIDSIZE; a++) {
        for (int b = 1; b < GRIDSIZE; b++) {
            if (grid[a][b]) {
                std::cout << " *";
            }
            else {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
}

void CopyGrid(bool grid[GRIDSIZE + 1][GRIDSIZE + 1], bool grid2[GRIDSIZE + 1][GRIDSIZE + 1]) {
    for (int a = 0; a < GRIDSIZE; a++) {
        for (int b = 0; b < GRIDSIZE; b++) { grid2[a][b] = grid[a][b]; }
    }
}

void liveOrDie(bool grid[GRIDSIZE + 1][GRIDSIZE + 1]) {
    bool grid2[GRIDSIZE + 1][GRIDSIZE + 1] = {};
    CopyGrid(grid, grid2);
    for (int a = 1; a < GRIDSIZE; a++) {
        for (int b = 1; b < GRIDSIZE; b++) {
            int life = 0;
            for (int c = -1; c < 2; c++) {
                for (int d = -1; d < 2; d++) {
                    if (!(c == 0 && d == 0)) {
                        if (grid2[a + c][b + d]) {
                            ++life;
                        }
                    }
                }
            }
            if (life < 2) { grid[a][b] = false; }
            else if (life == 3) { grid[a][b] = true; }
            else if (life > 3) { grid[a][b] = false; }
        }
    }
}

int main() {

    bool grid[GRIDSIZE + 1][GRIDSIZE + 1] = {};

    grid[GRIDSIZE / 2][GRIDSIZE / 2] = true;
    grid[GRIDSIZE / 2 - 1][GRIDSIZE / 2] = true;
    grid[GRIDSIZE / 2][GRIDSIZE / 2 + 1] = true;
    grid[GRIDSIZE / 2][GRIDSIZE / 2 - 1] = true;
    grid[GRIDSIZE / 2 + 1][GRIDSIZE / 2 + 1] = true;

    while (true) {

        Display(grid);
        liveOrDie(grid);
        system("CLS");
    }
}

//final code now shows a properly rode imitation of the game of life with various stages being played out