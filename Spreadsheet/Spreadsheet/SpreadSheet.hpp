//
//  SpreadSheet.hpp
//  Spreadsheet
//
//  Created by Alex Denisov on 16.04.2022.
//

#ifndef SpreadSheet_hpp
#define SpreadSheet_hpp

#include <stdio.h>
#include "Cell.hpp"

class SpreadSheet {
private:
    Cell** cells;
    int width;
    int height;
    
public:
    SpreadSheet(int width, int height);
    ~SpreadSheet();
    
    void resize(int width, int height);
    
    void setContent(std::string content, int x, int y);
    std::string getContent(int x, int y);
    
    void move(int x1, int y1, int x2,  int y2);
    void clear(int x, int y);
    
    void merge(int x, int y, int width, int height);
    
};

#endif /* SpreadSheet_hpp */
