#ifndef xo_h
#define xo_h

#include <iostream>
#include <vector>

class Game {
public:
    Game(); //
    void start_game(); //
private:
    void display_board(); //
    void make_move(); //
    char check();
private:
    std::vector<std::vector<char>> board;
    char player;
};

#endif