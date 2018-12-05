/*
    File: game.C

    Author: M. Hakimi
            Department of Computer Science
            Texas A&M University
    Date  : 2018/01/12
*/

/*--------------------------------------------------------------------------*/
/* DEFINES */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/
#include "game.h"

#include <ctime>

/*--------------------------------------------------------------------------*/
/* CONSTRUCTOR/DESTRUCTOR */
/*--------------------------------------------------------------------------*/
Game::Game(int argc, char** argv, char title[]) {
    // initialize window
    w = Window(argc, argv, title);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(s.keyboard);
    glutTimerFunc(s.getSpeed(), s.moveSnakeAuto, 0);

    int initSize = 3;

    // Specify the coordinates to each part of the snake
    for(int a = 1; a <= initSize; a++){
        std::deque<float> row;

        row.push_back(0.0f);
        row.push_back((s.getLength() + 2.0f + (initSize * 2)) - (a * 2));

        s.pushFront(row);
    }

    srand(time(NULL));

    initGL();

}

/*--------------------------------------------------------------------------*/
/* MEMBER FUNCTIONS */
/*--------------------------------------------------------------------------*/

/**
 * Display the game board
 */
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    // draw the snake
    for(unsigned int a = 0; a < s.getCords().size(); a++){
        glLoadIdentity();
        glTranslatef(s.getCords()[a][0], s.getCords()[a][1], -40.0f);
        glColor3f(0.0f, 1.0f, 0.0f);

        glBegin(GL_POLYGON);
            glVertex2d( 1.0f,  1.0f);
            glVertex2d( 1.0f, -1.0f);
            glVertex2d(-1.0f, -1.0f);
            glVertex2d(-1.0f,  1.0f);
        glEnd();
    }

    s.spawnFood();

    glutSwapBuffers();

}

/**
 * Initializes the game board
 */
void Game::initGL() {
    glMatrixMode(GL_PROJECTION);
    gluPerspective(75.0f, 1, 0.0f, 35.0f);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

/**
 * Sets board unchangeble to avoid render issues
 */
void reshape(GLsizei width, GLsizei height) {
    glutReshapeWindow(600, 600);
}