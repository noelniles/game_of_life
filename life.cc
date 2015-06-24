#include <iostream>

#include "life.hh"
#include "utility.hh"


void Life::initialize()
/* Pre: None.
 * Post The Life object contains a configuration specified by the user. */
{
    /* Initialize the grid. */
    int row, col;
    for (row = 0; row <= MAXROW; row++)
        for (col = 0; col <= MAXCOL; col++)
            grid[row][col] = 0;
    std::cout << "List the coordinates for living cells." << std::endl;
    std::cout << "Terminate the list with the special pair -1-1" << std::endl;
    std::cin >> row >> col;
    
    while (row != -1 || col != -1) {
        if (row >= 1 && row <= MAXROW)
            if (col >= 1 && col <= MAXCOL)
                grid[row][col] = 1;
            else
                std::cout << "Column " << col << " is out of range." << std::endl;
        else
            std::cout << "Row " << row << " is out of range." << std::endl;
        std::cin >> row >> col;
    }
}

void Life::print()
/* Pre: The Life object contains a configuration,
 * Post: The configuration is written for the user. */
{
    int row, col;
    std::cout << "\nThe current Life configuration is" << std::endl;
    for (row = 1; row <= MAXROW; row++) {
        for (col = 1; col <= MAXCOL; col++)
            if(grid[row][col] == 1) std::cout << "*";
            else std::cout << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int Life::neighbor_count(int row, int col)
/* Pre: The Life object contains a configuration and the coordinates row
 *      and col define a cell inside it's hedge.
 * Post: The number of living neighbors of the specified cell is
 *       returned. */
{
    int r, c;
    int count = 0;
    for (r = row - 1; r <= row + 1; r++)
        for (c = col - 1; c <= col + 1; c++)
            count += grid[r][c]; // Increase the count if neighbor is alive.
    count -= grid[row][col]; // Reduce count. Cell is not it's own neighbor.
    return count;
}

void Life::update()
/* Pre: The Life object contains a configuration.
 * Post: The Life object contains the next generation of configuration. */
{
    int row, col;
    int new_grid[MAXROW+2][MAXCOL+2];
    for (row = 1; row <= MAXROW; row++)
        for (col = 1; col <= MAXCOL; col++)
            switch (neighbor_count(row, col)) {
                case 2:
                    new_grid[row][col] = grid[row][col]; // no change
                    break;
                case 3:
                    new_grid[row][col] = 1; // It's Alive!
                    break;
                default:
                    new_grid[row][col] = 0; // >-(×_×)->
            }
    for (row = 1; row <= MAXROW; row++)
        for (col = 1; col <= MAXCOL; col++)
            grid[row][col] = new_grid[row][col];
}

int main(void)
/* Pre: The user supplies an initial configuration of living cells.
 * Post: The program prints a sequence of pictures showing the changes
 * in the configuration of living cells according to the rules for the
 * game of life.
 * Uses: The class Life and it's methods initialize(), print(), and
 * update(). The functions instructions() and user_says_yes().
 */
{
    Life configuration;
    instructions();
    configuration.initialize();
    configuration.print();
    std::cout << "Continue viewing new generations?" << std::endl;
    while (user_says_yes()) {
        configuration.update();
        configuration.print();
    }
}

