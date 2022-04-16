//
//  main.cpp
//  Spreadsheet
//
//  Created by Alex Denisov on 16.04.2022.
//

#include <iostream>
#include "SpreadSheet.hpp"

int main(int argc, const char * argv[]) {
    SpreadSheet test = SpreadSheet(10, 10);
    
    test.merge(0,0, 4, 4);
    test.setContent("hello", 0, 0);
    test.move(0, 0, 2, 2);
    
    std::cout << "hello" << std::endl;
    std::cout << test.getContent(2, 2) << std::endl;
    
    
    
    return 0;
}
