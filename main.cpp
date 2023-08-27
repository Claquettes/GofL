#include <iostream>
#include <string>
#include <ncurses.h>
#include <vector>

unsigned short width = 0;
unsigned short height = 0;

// Function prototypes
void getSizeOfTerminal();
std::vector<std::vector<bool>> createGrid(unsigned short width, unsigned short height);
int showGrid(const std::vector<std::vector<bool>> &grid);

int main()
{
    std::cout << "Welcome to GofL" << std::endl;
    std::cout << "The Game of Life" << std::endl;
    getSizeOfTerminal();

    return 0;
}

void getSizeOfTerminal()
{
    // Initialize ncurses
    initscr();

    // Get the size of the terminal
    int rows, cols;
    getmaxyx(stdscr, rows, cols);

    width = cols;
    height = rows;

    // Clean up ncurses
    endwin();

    // Print the terminal size
    std::cout << "Terminal size: " << rows << " rows x " << cols << " columns" << std::endl;

    std::vector<std::vector<bool>> grid = createGrid(width, height);
    showGrid(grid);
}

std::vector<std::vector<bool>> createGrid(unsigned short width, unsigned short height)
{
    // Create a 2D vector of bools and initialize with 'false'
    std::vector<std::vector<bool>> grid(width, std::vector<bool>(height, false));
    // Put 10 cells in the grid
    grid[5][5] = true;
    grid[5][6] = true;
    grid[5][7] = true;
    grid[5][8] = true;
    return grid;
}

int showGrid(const std::vector<std::vector<bool>> &grid)
{
    // Initialize ncurses
    initscr();

    // Print the grid
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j])
            {
                printw("X");
            }
            else
            {
                printw(" ");
            }
        }
        printw("\n");
    }

    refresh(); // Refresh the screen
    getch();   // Wait for a key press before exiting

    // Clean up ncurses
    endwin();

    return 0;
}
