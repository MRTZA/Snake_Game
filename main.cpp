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

    /* -- (none) -- */

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

int main(int argc, char** argv) {
    char title[] = "Snake Game"; // Title for Window

    Game g = Game(argc, argv, title);

    // Run OpenGL
    glutMainLoop();
    
    return 0;
}