#include "grid.h"
#include <raylib.h>
#include <iostream>
#include "color.h"

Grid::Grid() {
    numRows = 20;
    numCols = 10;
    celSize = 30;
    initialize();
    colors = GetCellColors();
}

Grid::~Grid() {
  // destructor
  std::cout << "Grid object destroyed" << std::endl;
};

void Grid::initialize() {
    for (int row = 0; row < numRows; ++row) {
        for (int column = 0; column < numCols; ++column) {
        grid[row][column] = 0;  // initalize grid to all 0
        }
    }
}

void Grid::Print() {
    for (int row = 0; row < numRows; ++row) {
        for (int column = 0; column < numCols; ++column) {
            std::cout << grid[row][column] << " ";
        }
    std::cout << std::endl;
    }
}

void Grid::Draw() {
    for (int row = 0; row < numRows; ++row) {
        for (int column = 0; column < numCols; ++column) {
            int cellValue = grid[row][column];
            DrawRectangle(column * celSize + 1, row * celSize + 1, celSize - 1, celSize - 1, colors[cellValue]);
        }
    }
}

bool Grid::IsCellOutside(int row, int column) {
    if (row >= 0 && row < numRows && column >= 0 && column < numCols) {
        return false;
    }
    else {
        return true;
    }
}

bool Grid::IsCellEmpty(int row, int column) {
    if (grid[row][column] == 0) {
        return false;
    }
    return true;
}
