/*
    File: snake.C

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
#include "snake.h"

/*--------------------------------------------------------------------------*/
/* CONSTRUCTOR/DESTRUCTOR */
/*--------------------------------------------------------------------------*/
Snake::Snake() {
    /* -- Do nothing all default values are set already -- */
}

/*--------------------------------------------------------------------------*/
/* MEMBER FUNCTIONS */
/*--------------------------------------------------------------------------*/

/**
 * Render the food block on the grid
 */
void Snake::spawnFood() {
    if(!foodAvailable){
        while(true){
            bool collides = false;

            // Produce a temporary random coordinate
            int temp_food_cords[2] = { food_cords[0] = 2 * (rand() % ((int) map_half_length + 1)) - (int) map_half_length,
                                        food_cords[1] = 2 * (rand() % ((int) map_half_length + 1)) - (int) map_half_length };

            // Does it collide with the snake?
            for(unsigned int a = 0; a < part_cords.size(); a++){
                if(temp_food_cords[0] == part_cords[a][0] &&
                   temp_food_cords[1] == part_cords[a][1]){
                    collides = true;
                }
            }

            // If it doesn't collide with the snake, then make it the real food coordinates
            if(collides == false){
                food_cords[0] = temp_food_cords[0];
                food_cords[1] = temp_food_cords[1];

                foodAvailable = true;

                break;
            }
        }
    }

    glLoadIdentity();
    glTranslatef(food_cords[0], food_cords[1], -40.0f);
    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
        glVertex2d( 1.0f,  1.0f);
        glVertex2d( 1.0f, -1.0f);
        glVertex2d(-1.0f, -1.0f);
        glVertex2d(-1.0f,  1.0f);
    glEnd();
}

/**
 * Update snake's position based on user input
 */
void Snake::moveSnake(int newDirection) {
    direction = newDirection;

    int last_part = part_cords.size() - 1;
    std::deque<float> new_head = part_cords[last_part];

    if(direction == UP){
        // Did we slither into ourself?
        for(unsigned int a = 0; a < part_cords.size(); a++){
            if(part_cords[0][0]        == part_cords[a][0] &&
               part_cords[0][1] + 2.0f == part_cords[a][1]){
                exit(0);
            }
        }

        // Did we slither into a wall?
        if(part_cords[0][1] == map_half_length){
            exit(0);
        }

        // Did we get food?
        if(part_cords[0][0]        == food_cords[0] &&
           part_cords[0][1] + 2.0f == food_cords[1]){
            growthStage++;
            foodAvailable = false;
        }

        new_head[1] = part_cords[0][1] + 2.0f;
    } else if(direction == DOWN){
        // Did we slither into ourself?
        for(unsigned int a = 0; a < part_cords.size(); a++){
            if(part_cords[0][0]        == part_cords[a][0] &&
               part_cords[0][1] - 2.0f == part_cords[a][1]){
                exit(0);
            }
        }

        // Did we slither into a wall?
        if(part_cords[0][1] == -map_half_length){
            exit(0);
        }

        // Did we get food?
        if(part_cords[0][0]        == food_cords[0] &&
           part_cords[0][1] - 2.0f == food_cords[1]){
            growthStage++;
            foodAvailable = false;
        }

        new_head[1] = part_cords[0][1] - 2.0f;
    } else {
        new_head[1] = part_cords[0][1];
    }

    if(direction == LEFT){
        // Did we slither into ourself?
        for(unsigned int a = 0; a < part_cords.size(); a++){
            if(part_cords[0][0] - 2.0f == part_cords[a][0] &&
               part_cords[0][1]        == part_cords[a][1]){
                exit(0);
            }
        }

        // Did we slither into a wall?
        if(part_cords[0][0] == -map_half_length){
            exit(0);
        }

        // Did we get food?
        if(part_cords[0][0] - 2.0f == food_cords[0] &&
           part_cords[0][1]        == food_cords[1]){
            growthStage++;
            foodAvailable = false;
        }

        new_head[0] = part_cords[0][0] - 2.0f;
    } else if(direction == RIGHT){
        // Did we slither into ourself?
        for(unsigned int a = 0; a < part_cords.size(); a++){
            if(part_cords[0][0] + 2.0f == part_cords[a][0] &&
               part_cords[0][1]        == part_cords[a][1]){
                exit(0);
            }
        }

        // Did we slither into a wall?
        if(part_cords[0][0] == map_half_length){
            exit(0);
        }

        // Did we get food?
        if(part_cords[0][0] + 2.0f == food_cords[0] &&
           part_cords[0][1]        == food_cords[1]){
            growthStage++;
            foodAvailable = false;
        }

        new_head[0] = part_cords[0][0] + 2.0f;
    } else {
        new_head[0] = part_cords[0][0];
    }

    part_cords.push_front(new_head);

    if(!growthStage){
        part_cords.pop_back();
    } else if(growthStage == growth){
        growthStage = 0;
    } else {
        growthStage++;
    }

    glutPostRedisplay();
}

/**
 * Handle keyboard input
 */
void Snake::keyboard(int key, int x, int y) {
    switch(key){
        case GLUT_KEY_UP:{
            if(direction == LEFT || direction == RIGHT){
                moved = true;

                moveSnake(UP);
            }

            break;
        }

        case GLUT_KEY_DOWN:{
            if(direction == LEFT || direction == RIGHT){
                moved = true;

                moveSnake(DOWN);
            }

            break;
        }

        case GLUT_KEY_LEFT:{
            if(direction == UP || direction == DOWN){
                moved = true;

                moveSnake(LEFT);
            }

            break;
        }

        case GLUT_KEY_RIGHT:{
            if(direction == UP || direction == DOWN){
                moved = true;

                moveSnake(RIGHT);
            }

            break;
        }
    }

    glutPostRedisplay();
}

/**
 * Update snake's position w/o user input
 */
void Snake::moveSnakeAuto() {
    if(!moved){

        if(direction == UP){
            moveSnake(UP);
        } else if(direction == DOWN){
            moveSnake(DOWN);
        } else if(direction == LEFT){
            moveSnake(LEFT);
        } else if(direction == RIGHT){
            moveSnake(RIGHT);
        }
    } else {
        moved = false;
    }

    glutTimerFunc(this->moveSpeed, this->moveSnakeAuto, 0);
}
