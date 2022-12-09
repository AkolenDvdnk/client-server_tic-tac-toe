#ifndef cell_hpp
#define cell_hpp

#include <iostream>

class Cell{
public:
    Cell();

    void setSellStatus(int);
    void setMark(char);
    
    int getSellStatus()const;
    char getMark()const;
    
private:
    char mark;
    int cellStatus;
};

#endif