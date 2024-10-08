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
            DrawRectangle(column * celSize + 11, row * celSize + 11, celSize - 1, celSize - 1, colors[cellValue]);
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
        return true;
    }
    return false;
}

bool Grid::IsRowFull(int row) {
    for (int column = 0; column < numCols; ++column) {
        if (grid[row][column] == 0) {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row) {
    for (int column = 0; column < numCols; ++column) {
        grid[row][column] = 0;
    }
}

void Grid::MoveRowDown(int row, int numRows) {
    for (int column =0; column < numCols; ++column) {
        grid[row + numRows][column] = grid[row][column];
        grid[row][column] = 0;
    }
}

int Grid::ClearFullRows() {
    int completed = 0;
    for (int row = numRows-1; row >= 0; --row) {
        if (IsRowFull(row)) {
            ClearRow(row);
            completed++;
        } else if (completed > 0) {
            MoveRowDown(row, completed);
        }
    }
    return completed;
}
