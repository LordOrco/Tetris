#include "GameManager.h"
#include "Tetris.h"

using namespace std;

//CONSTANTES
float x = 0.0f, z = 26.0f;

const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 600;
const int WINDOW_POSITION_X = 500;
const int WINDOW_POSITION_Y = 50;
const char TITLE[] = "Tetris";

const GLclampf RED =  (GLclampf) 0.2;
const GLclampf GREEN = 0.2;
const GLclampf BLUE = 0.2;
const GLclampf ALPHA = 1.0;

// VARIABLES

bool fullScreenMode = false;

// USANDO TETRIS

GameManager game;

// FUNCIONES AUXILIARES

void writeLine(string cadena) {
    cout << cadena << endl;
}

//FUNCIONES OPENGL
void initGraphics() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glClearColor(RED, GREEN, BLUE, ALPHA);

    game.Init();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(x, 0.0f, z,
        0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f);

    /*
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex3f(-1, 1, 0);
    glVertex3f(1, 1, 0);
    glVertex3f(1, -1, 0);
    glVertex3f(-1, -1, 0);
    glEnd();
    */

    game.Render();

    glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;
    GLfloat aspectRatio = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0f, aspectRatio, 1.0f, 200.0f);
    glMatrixMode(GL_MODELVIEW);
}

void idle() {
    game.Update();
    glutPostRedisplay();
}

void keyPressed(unsigned char key, int px, int py) {
    game.ProcessKeyPressed(key, px, py);
    glutPostRedisplay();
}

void mouseMoved(int x, int y) {
    game.ProcessMouseMovement(x, y);
    glutPostRedisplay();
}

void mouseClicked(int button, int state, int x, int y) {
    game.ProcessMouseClick(button, state, x, y);
    glutPostRedisplay();
}

void specialKey(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_F11:
        fullScreenMode = !fullScreenMode;
        if (fullScreenMode) {
            glutFullScreen();
        }
        else {
            glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
            glutPositionWindow(WINDOW_POSITION_X, WINDOW_POSITION_Y);
        }
        break;

    }
}

int main(int argc, char** argv) {
    //ShowWindow(GetConsoleWindow(), SW_HIDE);
	
    writeLine("Generando ventana");
    glutInit(&argc, argv);                                              //Inicializa GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);          //Doble buffer, modo RGBA, depth buffer
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);                    //Tamaño inicial de la ventana
    glutInitWindowPosition(WINDOW_POSITION_X, WINDOW_POSITION_Y);        //Posición inicial de la ventana
    glutCreateWindow(TITLE);                                            //Crea una ventana con el título deseado

    writeLine("Registrando funciones de tratamiento de eventos...");
    glutReshapeFunc(reshape);                                           //Tratamiento del evento de redimensionado de la ventana
    glutDisplayFunc(display);                                           //Tratamiento del evento de repintado de la ventana
    glutKeyboardFunc(keyPressed);                                       //Tratamiento del evento de tecla pulsada
    glutSpecialFunc(specialKey);                                        //Tratamiendo del evento de tecla especial pulsada
    glutMotionFunc(mouseMoved);                                         //Tratamiento del evento de mover el ratón
    glutMouseFunc(mouseClicked);                                        //Tratamiento del evento de click del ratón
    glutIdleFunc(idle);                                              //Cuando no hay eventos

    writeLine("Iniciando gráficos");
    initGraphics();                                                     //Iniciamos OpenGL

    writeLine("Iniciando bucle infinito");
    writeLine("Pulse la tecla F11 para activar/desactivar el modo de pantalla completa");
    glutMainLoop();
}