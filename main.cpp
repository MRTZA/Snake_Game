/*
    File: main.C

    Author: M. Hakimi
            Department of Computer Science
            Texas A&M University
    Date  : 2018/01/12
*/

/*--------------------------------------------------------------------------*/
/* DEFINES */
/*--------------------------------------------------------------------------*/

    /* -- none -- */

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

// OpenGL Includes (They're Different for Mac)
#ifdef __APPLE__
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
    #include <GLUT/glut.h>
#else 
    #include <GL/glut.h>
    #include <GL/gl.h>
    #include <GL/glu.h>
#endif

#include <unistd.h>

// Include our Classes
#include "window.h"
#include "game.h"
#include <ctime>
#include <string.h>

// Global Variables
Snake s = Snake();
deque<deque<float>> map_cords;

// Keyboard variables
const int UP = 1;
const int DOWN = 2;
const int LEFT = 3;
const int RIGHT = 4;

/**
 * Update snake's position w/o user input
 */
void moveSnakeAuto(int value) {
    if(!s.getMoved()){

        if(s.getDirection() == UP){
            s.moveSnake(UP);
        } else if(s.getDirection() == DOWN){
            s.moveSnake(DOWN);
        } else if(s.getDirection() == LEFT){
            s.moveSnake(LEFT);
        } else if(s.getDirection() == RIGHT){
            s.moveSnake(RIGHT);
        }
    } else {
        s.setMoved(false);
    }

    glutTimerFunc(s.getSpeed(), moveSnakeAuto, 0);
}

/**
 * Handle keyboard input
 */
void keyboard(int key, int x, int y) {
    switch(key){
        case GLUT_KEY_UP:{
            if(s.getDirection() == LEFT || s.getDirection() == RIGHT){
                s.setMoved(true);

                s.moveSnake(UP);
            }

            break;
        }

        case GLUT_KEY_DOWN:{
            if(s.getDirection() == LEFT || s.getDirection() == RIGHT){
                s.setMoved(true);

                s.moveSnake(DOWN);
            }

            break;
        }

        case GLUT_KEY_LEFT:{
            if(s.getDirection() == UP || s.getDirection() == DOWN){
                s.setMoved(true);

                s.moveSnake(LEFT);
            }

            break;
        }

        case GLUT_KEY_RIGHT:{
            if(s.getDirection() == UP || s.getDirection() == DOWN){
                s.setMoved(true);

                s.moveSnake(RIGHT);
            }

            break;
        }
    }

    glutPostRedisplay();
}

/**
 * Function to draw text to the screen
 */
void output()
{
  char *string = "2000";
  glColor3f(0.0f, 1.0f, 0.0f);
  glRasterPos2f(10, 10);
  int len, i;
  len = (int)strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
  }

}

/**
 * Display the game board
 */
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    // output();
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
 * Sets board unchangeble to avoid render issues
 */
void reshape(GLsizei width, GLsizei height) {
    glutReshapeWindow(600, 600);
}

/**
 * Initializes the game board
 */
void initGL() {
    glMatrixMode(GL_PROJECTION);
    gluPerspective(75.0f, 1, 0.0f, 35.0f);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

int main(int argc, char** argv) {
    char title[] = "Snake Game"; // Title for Window
    glutInit(&argc, argv);

    glutInitWindowSize(600, 600);
    glutCreateWindow(title);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(keyboard);
    glutTimerFunc(s.getSpeed(), moveSnakeAuto, 0);

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

    // Run OpenGL
    glutMainLoop();
    
    return 0;
}