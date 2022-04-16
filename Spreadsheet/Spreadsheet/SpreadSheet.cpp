//
//  SpreadSheet.cpp
//  Spreadsheet
//
//  Created by Alex Denisov on 16.04.2022.
//

#include "SpreadSheet.hpp"
#include <iostream>

const int max_size = 30;

SpreadSheet::SpreadSheet(int width, int height) {
    this->width = width;
    this->height = height;
    this->cells = new Cell*[max_size];
    for(int i = 0; i < width; i++) {
        cells[i] = new Cell[max_size];
    }
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            cells[i][j] = Cell();
        }
    }
}

SpreadSheet::~SpreadSheet() {
    for(int i = 0; i < width; i++) delete[] cells[i];
    delete cells;
}

void SpreadSheet::resize(int width, int height) {
    this->width = std::min(width, max_size);
    this->height = std::min(height, max_size);
}

void SpreadSheet::setContent(std::string content, int x, int y) {
    if(x < 0 || x > max_size || y < 0 || y > max_size) return;
    cells[y][x].setContent(content);
}

std::string SpreadSheet::getContent(int x, int y) {
    if(x < 0 || x > max_size || y < 0 || y > max_size) return "";
    return cells[y][x].getContent();
}

void SpreadSheet::move(int x1,int y1, int delta_x, int delta_y) {
    int connectionWidth = cells[y1][x1].getConnectionWidth();
    int connectionHeight = cells[y1][x1].getConnectionHeight();
    
    if(x1 < 0 || x1 > max_size || y1 < 0 || y1 > max_size) return;
    if(x1 + delta_x < 0 || x1 + delta_x + connectionWidth > max_size || y1 + delta_y < 0 || y1 + delta_y + connectionHeight > max_size) return;
    
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            int a = y1 + i;
            int b = x1 + j;
            int c = a + delta_y;
            int d = b + delta_x;
            std::cout << a << " " << b << " " << c << " " << d << std::endl;
            std::swap(cells[c][d], cells[a][b]);
        }
    }

}

void SpreadSheet::clear(int x, int y) {
    if(x < 0 || x > max_size || y < 0 || y > max_size) return;
    cells[y][x].setContent("");
}

void SpreadSheet::merge(int x, int y, int width, int height) {
    cells[y][x].setConnectionWidth(width);
    cells[y][x].setConnectionHeight(height);
    
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            if(i == 0 && j == 0) continue;
            cells[i][j].bind_to(&cells[y][x]);
        }
    }
}


