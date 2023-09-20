#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

using namespace std;

//define the size of the map
const int width = 20;
const int height = 20;

//define the snake and food and game class
class Snake
{
private:
    int x, y;
public:
    Snake(int width, int height);
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void reset(int width, int height);
};

class Food
{
private:
    int x, y;
public:
    Food(int width, int height);
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
    void reset(int width, int height);
};

class Game
{
private:
    bool gameOver;
    int score;
    Snake* snake;
    Food* food;
public:

    Game(int width, int height);
    void setGameOver(bool gameOver);
    bool getGameOver();
    void setScore(int score);
    int getScore();
    void setSnake(Snake* snake);
    Snake* getSnake();
    void setFood(Food* food);
    Food* getFood();
    void draw();
    void input();
    void logic();
    void run();
};

//define the snake class
Snake::Snake(int width, int height)
{
    x = width / 2;
    y = height / 2;
}

void Snake::setX(int x)
{
    this->x = x;
}

void Snake::setY(int y)
{
    this->y = y;
}

int Snake::getX()
{
    return x;
}

int Snake::getY()
{
    return y;
}

void Snake::moveUp()
{
    y--;
}

void Snake::moveDown()
{
    y++;
}

void Snake::moveLeft()
{
    x--;
}

void Snake::moveRight()
{
    x++;
}

void Snake::reset(int width, int height)
{
    x = width / 2;
    y = height / 2;
}

//define the food class
Food::Food(int width, int height)
{
    x = rand() % width;
    y = rand() % height;
}

void Food::setX(int x)
{
    this->x = x;
}

void Food::setY(int y)
{
    this->y = y;
}

int Food::getX()
{
    return x;
}

int Food::getY()
{
    return y;
}

void Food::reset(int width, int height)
{
    x = rand() % width;
    y = rand() % height;
}

//define the game class
Game::Game(int width, int height)
{
    gameOver = false;
    score = 0;
    snake = new Snake(width, height);
    food = new Food(width, height);
}

void Game::setGameOver(bool gameOver)
{
    this->gameOver = gameOver;
}

bool Game::getGameOver()
{
    return gameOver;
}

void Game::setScore(int score)
{
    this->score = score;
}

int Game::getScore()
{
    return score;
}

void Game::setSnake(Snake* snake)
{
    this->snake = snake;
}

Snake* Game::getSnake()
{
    return snake;
}

void Game::setFood(Food* food)
{
    this->food = food;
}

Food* Game::getFood()
{
    return food;
}

void Game::draw()
{
    system("cls");
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width + 2; j++)
        {
            if (j == 0)
                cout << "#";
            else if (j == width + 1)
                cout << "#";
            else if (i == snake->getY() && j == snake->getX())
                cout << "O";
            else if (i == food->getY() && j == food->getX())
                cout << "F";
            else
                cout << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
    cout << "Score: " << score << endl;
}

void Game::input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'w':
            snake->moveUp();
            break;
        case 's':
            snake->moveDown();
            break;
        case 'a':
            snake->moveLeft();
            break;
        case 'd':
            snake->moveRight();
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void Game::logic()
{
    if (snake->getX() == food->getX() && snake->getY() == food->getY())
    {
        score++;
        food->reset(width, height);
    }
    if (snake->getX() >= width || snake->getX() < 0 || snake->getY() >= height || snake->getY() < 0)
    {
        gameOver = true;
    }
}

void Game::run()
{
    while (!gameOver)
    {
        draw();
        input();
        logic();
        Sleep(100);
    }
}

//define the main function
int main()
{
    srand(time(NULL));
    Game* game = new Game(width, height);
    game->run();
    return 0;
}