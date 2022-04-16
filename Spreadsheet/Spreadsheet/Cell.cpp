//
//  Cell.cpp
//  Spreadsheet
//
//  Created by Alex Denisov on 16.04.2022.
//

#include "Cell.hpp"

Cell::Cell() {
    this->connectionWidth = 1;
    this->connectionHeight = 1;
    this->content = "";
    this->mainCell = NULL;
}

Cell::~Cell() {
    mainCell = NULL;
}

void Cell::setContent(std::string content) {
    if(!mainCell) this->content = content;
    else mainCell->setContent(content);
}

std::string Cell::getContent() {
    if(!mainCell) return content;
    return mainCell->getContent();
}

void Cell::bind_to(Cell *mainCell) {
    this->mainCell = mainCell;
    content = "";
}

void Cell::setConnectionWidth(int width) {
    this->connectionWidth = width;
}

void Cell::setConnectionHeight(int height) {
    this->connectionHeight = height;
}

int Cell::getConnectionWidth() {
    return connectionWidth;
}

int Cell::getConnectionHeight() {
    return connectionHeight;
}
