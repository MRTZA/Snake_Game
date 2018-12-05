/*
    File: window.H

    Author: M. Hakimi
            Department of Computer Science
            Texas A&M University
    Date  : 2018/01/12
*/

/*--------------------------------------------------------------------------*/
/* DEFINES */
/*--------------------------------------------------------------------------*/

#ifndef _WINDOW_
#define _WINDOW_

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#ifdef __APPLE__
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
    #include <GLUT/glut.h>
#else 
    #include <GL/glut.h>
    #include <GL/gl.h>
    #include <GL/glu.h>
#endif

class Window {
    public:
        Window(int argc, char** argv, char title[]); // Constructor
        Window() {} // default Constructor
    private:
        char title;

};

#endif