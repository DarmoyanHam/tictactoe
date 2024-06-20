#include <iostream>
#include <vector>
#include "xikoik.h"

Game::Game()
: player('X')
, board(3, std::vector<char>(3, '-'))
{}

void Game::start_game()
{
    while(true)
    {
        display_board();
        make_move();
        char state = check();
        switch (state)
        {
        case 'X':
            display_board();
            std::cout << "X player wins!!!" << std::endl;
            return;
        case 'O':
            display_board();
            std::cout << "O player wins!!!" << std::endl;
            return;
        case '0':
            display_board();
            std::cout << "draw" << std::endl;
            return;
        }
    }
}

void Game::display_board()
{
    for(int i = 0; i < board.size(); ++i)
    {
        for(int j = 0; j < board[i].size(); ++j)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Game::make_move()
{
    int x = 0;
    int y = 0;
    do {
        std::cout << "Player "<< player << " " << "input coordinates" << std::endl;
        std::cin >> x >> y;
    }while(x < 0 || x >= board.size() || y < 0 || y >= board.size() || board[x][y] != '-');

    board[x][y] = player;

    if(player == 'X')
    {
        player = 'O';
    }
    else
    {
        player = 'X';
    }

}

char Game::check()
{
    bool line = true;
    for(int i = 0; i < board.size(); ++i)
    {
        line = true;
        for(int j = 0; j < board.size() - 1; ++j)
        {
            if(board[i][j] == '-' || board[i][j] != board[i][j + 1])
            {
                line = false;
                break;
            }
        }
        if(line)
        {
            return board[i][0];
        }
        line = true;

        for(int j = 0; j < board.size() - 1; ++j)
        {
            if(board[j][i] == '-' || board[j][i] != board[j+1][i])
            {
                line = false;
                break;
            }
        }
        if(line)
        {
            return board[0][i];
        }
        line = true;
    }

    for(int i = 0; i < board.size() - 1; ++i)
    {
        if(board[i][i] == '-' || board[i][i] != board[i + 1][i + 1])
        {
            line = false;
            break;
        }
    }
    if(line)
    {
        return board[0][0];
    }
    line = true;
        
    for(int i = 0; i < board.size() - 1; ++i)
    {
        if(board[i][board.size() - i - 1] == '-' || board[i][board.size() - i - 1] != board[i + 1][board.size() - i - 2])
        {
            line = false;
            break;
        }
    }
    if(line)
    {
        return board[board.size() - 1][0];
    }
    line = true;

    for(int i = 0; i < board.size(); ++i)
    {
        for(int j = 0; j < board.size(); ++j)
        {
            if(board[i][j] == '-')
            {
                return '-';
            }
        }
    }

    return '0';
}