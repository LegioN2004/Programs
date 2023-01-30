#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159265358979323846;

// Angle of rotation
float angle = 0.0;

void display()
{
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Translate and rotate the model
    glTranslatef(0.0, 0.0, -5.0);
    glRotatef(angle, 0.0, 1.0, 0.0);

    // Draw the ball
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 0.0, 0.0);
    for (int i = 0; i <= 360; i++)
    {
        float theta = 2.0f * PI * float(i) / float(360);
        float x = 0.5 * cosf(theta);
        float y = 0.5 * sinf(theta);
        glVertex3f(x, y, 0.0);
    }
    glEnd();

    // Swap the buffers
    glutSwapBuffers();
}

void timer(int value)
{
    // Increment the angle of rotation
    angle += 1.0;

    // Redisplay the scene
    glutPostRedisplay();

    // Call the timer function again after a delay
    glutTimerFunc(16, timer, 0);
}

int main(int argc, char** argv)
{
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Rotating Ball");

    // Set the display function
    glutDisplayFunc(display);

    // Set the timer function
    glutTimerFunc(16, timer, 0);

    // Enter the main loop
    glutMainLoop();

    return 0;
}
