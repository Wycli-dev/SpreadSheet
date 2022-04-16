//
//  Cell.hpp
//  Spreadsheet
//
//  Created by Alex Denisov on 16.04.2022.
//

#ifndef Cell_hpp
#define Cell_hpp

#include <stdio.h>
#include <string>

class Cell {
private:
    std::string content;
    Cell* mainCell;
    int connectionWidth;
    int connectionHeight;
    
public:
    Cell();
    ~Cell();
    void setContent(std::string content);
    std::string getContent();
    void bind_to(Cell* main_cell);
    void setConnectionWidth(int width);
    void setConnectionHeight(int height);
    int getConnectionWidth();
    int getConnectionHeight();
};

#endif /* Cell_hpp */
