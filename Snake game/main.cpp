#include <iostream>

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
                cout<< "O";
            }
            //Fruit
            else if( i == fruitY && j == fruitX)
            {
                cout << "F";
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

}

void Logic()
{

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