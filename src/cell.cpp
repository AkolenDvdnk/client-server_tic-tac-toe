#include "../include/cell.hpp"

Cell::Cell(){
    mark = ' ';
    cellStatus = 0;
}

void Cell::setSellStatus(int value){
    this->cellStatus = value;
}

int Cell::getSellStatus()const{
    return cellStatus;  
}

char Cell::getMark()const{
    return mark;
}

void Cell::setMark(char mark){
    this->mark = mark;   
}