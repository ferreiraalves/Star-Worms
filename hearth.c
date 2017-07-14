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
#include "hearth.h"

void desenhaHearth(Hearth h, int txhearth) {
    glColor3f(1,1,1);
    glEnable (GL_BLEND); glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, txhearth);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0,0);glVertex3f(h.posx-(h.dim/2), h.posy-(h.dim/2), 0.0);
        glTexCoord2f(0,1);glVertex3f(h.posx-(h.dim/2), h.posy+(h.dim/2), 0.0);
        glTexCoord2f(1,1);glVertex3f(h.posx+(h.dim/2), h.posy+(h.dim/2), 0.0);
        glTexCoord2f(1,0);glVertex3f(h.posx+(h.dim/2), h.posy-(h.dim/2), 0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    //glutSwapBuffers();
}


Hearth criaHearth(Hearth h, double x, double y) {
    h.posx=x;
    h.posy=y;
    h.dim=0.1;
    return h;
}

void verificaHearth(Hearth * h, Player player1, Player player2, int txhearth){
  if(player1.hp==30){
    desenhaHearth(h[0],txhearth);
    desenhaHearth(h[1],txhearth);
    desenhaHearth(h[2],txhearth);
  }
  if(player1.hp==20){
    desenhaHearth(h[0],txhearth);
    desenhaHearth(h[1],txhearth);
  }
  if(player1.hp==10){
    desenhaHearth(h[0],txhearth);

  }
  if(player2.hp==30){
    desenhaHearth(h[3],txhearth);
    desenhaHearth(h[4],txhearth);
    desenhaHearth(h[5],txhearth);
  }
  if(player2.hp==20){
    desenhaHearth(h[3],txhearth);
    desenhaHearth(h[4],txhearth);
  }
  if(player2.hp==31){
    desenhaHearth(h[3],txhearth);

  }




}
