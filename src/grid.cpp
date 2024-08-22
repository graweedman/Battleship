#include "grid.h"

Grid::Grid(int w, int h) {
    width = w;
    height = h;
    for (int i = 0; i<GRID_SIZE; i++)
    {
        grid[i] = true;
    }
}

int Grid::get_index(int row, int col) {
    return (row * width) + col;
}

void Grid::set_field(int row, int col) {
    grid[get_index(row, col)] = true;
}

void Grid::reset_field(int row, int col) {
    grid[get_index(row, col)] = false;
}

bool Grid::get_field(int row, int col) {
    return grid[get_index(row, col)];
}