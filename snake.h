/*
    File: sanke.H

    Author: M. Hakimi
            Department of Computer Science
            Texas A&M University
    Date  : 2018/01/12
*/

/*--------------------------------------------------------------------------*/
/* DEFINES */
/*--------------------------------------------------------------------------*/

#ifndef _SNAKE_
#define _SNAKE_

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/
#include "window.h"

#include <deque>

using namespace std;

class Snake {
    public:
        Snake(); // Constructor

        /* Member Functions */
        void spawnFood();
        void moveSnake(int newDirection);
        void keyboard(int key, int x, int y);
        void moveSnakeAuto();
        
        deque<deque<float>> getCords() { return part_cords; }
        int getSpeed() { return moveSpeed; }
        float getLength() { return map_half_length; }

        void pushFront(deque<float> row) { return part_cords.push_front(row); }

    private:
        // Keyboard variables
        const int UP = 1;
        const int DOWN = 2;
        const int LEFT = 3;
        const int RIGHT = 4;

        // Movm't variables
        int direction = DOWN; // move down when starting
        int moveSpeed = 100;
        bool moved = false;
        deque<deque<float>> part_cords;

        // Food variables
        bool foodAvailable = false;
        int food_cords[2];

        // Growth variables
        int growthStage = 0;
        int growth = 2;

        float map_half_length = 30.0f;

};

#endif