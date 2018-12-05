/*
    File: game.H

    Author: M. Hakimi
            Department of Computer Science
            Texas A&M University
    Date  : 2018/01/12
*/

/*--------------------------------------------------------------------------*/
/* DEFINES */
/*--------------------------------------------------------------------------*/

#ifndef _GAME_
#define _GAME_

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/
#include "window.h"
#include "snake.h"

class Game {
    public:
        Game(int argc, char** argv, char title[]); // Constructor

        /* Member Functions */
        void display();
        void initGL();
        void reshape(GLsizei width, GLsizei height);

    private:
        Window w;
        /* Snake Object */
        Snake s;

        float map_half_length = 30.0f;

};

#endif