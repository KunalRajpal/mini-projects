#include <iostream>
#include <conio.h> // conio.h imports console input and output

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;

enum eDirection{STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height /2;
    fruitX = rand() % width;
    fruitY = rand() & height;
    score = 0;
}

void Draw()
{
    system("cls"); //clears the system in terminal of windows

    //inital border: the first line ######################
    for(int i=0; i< width; i++)
    {
        cout << "#";
    }
    cout << endl;

    
    for(int i=0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            //side borders
            if(j == 0)
            {
                cout << "#";
            }
            //snake head
            if(i == y && j== x)
            {
                cout<< "<<";
            }
            //Fruit
            else if( i == fruitY && j == fruitX)
            {
                cout << "X";
            }
            //black space
            else
            {
                cout << " ";
            }
            //ending border
            if(j == width - 1)
            {
                cout << "#";
            }// for J end
        }
        cout << endl;
    }//for I end

    for(int i=0; i <width+2; i++)
    {
        cout << "#";
    }
    cout << endl;
    cout << "Score: " << score << endl;
}

void Input()
{
    if(_kbhit()) //returns a positive number if the keyboard key is pressed -- comes from conio.h
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'A':
            dir = LEFT;
            break;
        case 'D':
            dir = RIGHT;
            break;
        case 'W':
            dir = UP;
            break;
        case 'S':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;         
        default:
            break;
        }

        if(x > width || x <0 || y > height || y < 0)
        {
            gameOver = true;
        }
        if(x == fruitX && y == fruitY)
        {
            score+=10;
            fruitX = rand() % width;
            fruitY = rand() & height;
        }
    }
}

void Logic()
{
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;            
    default:
        break;
    }
}

int main()
{
    Setup();

    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
    }
    
    return 0;
}