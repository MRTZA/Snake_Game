/*
    File: window.C

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
#include "window.h"

/*--------------------------------------------------------------------------*/
/* CONSTRUCTOR */
/*--------------------------------------------------------------------------*/
Window::Window(int argc, char** argv, char title[]) {
    // Set private members
    this->title = *title;

    // Start OpenGL
    glutInit(&argc, argv);

    // Creates the Window (Set Size)
    glutInitWindowSize(600, 600);
    glutCreateWindow(title);

}