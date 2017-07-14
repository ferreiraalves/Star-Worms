#include <GL/freeglut.h>  // em vez de áspas
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tads.h"
#include "projetil.h"
#include "mira.h"
#include "SOIL/SOIL.h"
#include "loadtexture.h"

void desenhaMira(Mira m, int txmira) {
    glColor3f(1,1,1);
    glEnable (GL_BLEND); glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, txmira);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0,0);glVertex3f(m.posx-(m.dim/2), m.posy-(m.dim/2), 0.0);
        glTexCoord2f(0,1);glVertex3f(m.posx-(m.dim/2), m.posy+(m.dim/2), 0.0);
        glTexCoord2f(1,1);glVertex3f(m.posx+(m.dim/2), m.posy+(m.dim/2), 0.0);
        glTexCoord2f(1,0);glVertex3f(m.posx+(m.dim/2), m.posy-(m.dim/2), 0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    //glutSwapBuffers();
}


Mira criaMira(Projetil projetil, Mira m) {
    m.posx=projetil.posx;
    m.posy=projetil.posy;
    m.dim=0.2;
    return m;
}

Mira atualizaMira (Mira m, double x, double y) {
    m.posx=m.posx+x;
    m.posy=m.posy+y;
    return m;
}
