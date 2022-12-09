#include <iostream>

#include "../include/player.hpp"
#include "../include/tictactoe.hpp"

Player::Player(char player){
    setPlayer(player);
}

char Player::setPlayer(char player){
    this->player = player;
}