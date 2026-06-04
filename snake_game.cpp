// snake_game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

const int ROWS = 10;
const int COLS = 10;

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};
Direction dir;

void clearBoard(vector<vector<int>>& Board) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            Board[i][j] = 0;
        }
    }
}
void drawBoard(vector<vector<int>>& Board) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << Board[i][j] << "  ";
        }
        cout << endl;
        cout << endl;
    }
}
int main()
{
    

    vector<vector<int>> Board(ROWS, vector<int>(COLS, 0));

    int snakeRow = 5;
    int snakeCol = 5;

    vector<pair<int, int>> snake =
    {
        {5,3},
        {5,4},
        {5,5}
    };

    Board[snakeRow][snakeCol] = 1;

    /*for (int i = 0; i < Board.size(); i++) {
        for (int j = 0; j < Board.size(); j++) {
            cout << Board[i][j] << "  ";
        }
        cout << endl;
        cout << endl;
    }*/
    while (true) {
        clearBoard(Board);
        char move;
        cin >> move;
        if (move == 'w') dir = UP;
        else if (move == 's') dir = DOWN;
        else if (move == 'a') dir = LEFT;
        else if (move == 'd') dir = RIGHT;

        int newRow = snake.back().first;
        int newCol = snake.back().second;

        switch (dir)
        {
        case UP: newRow--;
            break;
        case DOWN: newRow++;
            break;
        case LEFT: newCol--;
            break;
        case RIGHT: newCol++;
            break;
        default:
            break;
        }
        if (newRow < 0 || newCol < 0) {
            cout << "Game Over !" << endl;
            break;
        }
        snake.push_back({ newRow , newCol });
        snake.erase(snake.begin());
        
        for (auto segment : snake) {
            Board[segment.first][segment.second] = 1;
        }
        
        drawBoard(Board);
    }

    /*sf::RenderWindow window(
        sf::VideoMode({ 800, 600 }),
        "Snake"
    );

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.display();
    }*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
