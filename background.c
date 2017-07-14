#include <GL/freeglut.h>
#include "background.h"
#include <stdio.h>
#include <stdlib.h>
#include "tads.h"

int estadomenu = 0; // Inicializa a máquina de estados


//Desenha o cenário do jogo a cada partida
void desenhaMinhaCena(Bounds b, int txbackground, int txgrass){

// Gera a textura do background do cenário
//glColor3f(1,1,1);

glEnable (GL_BLEND); glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, txbackground);

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

  glBegin(GL_TRIANGLE_FAN);
      glTexCoord2f(0,0);glVertex3f(-2.0,b.bottom, -1.0);
      glTexCoord2f(0,1);glVertex3f(-2.0, b.top, -1.0);
      glTexCoord2f(1,1);glVertex3f(2.0, b.top, -1.0);
      glTexCoord2f(1,0); glVertex3f(2.0, b.bottom, -1.0);
  glEnd();
glDisable(GL_TEXTURE_2D);

// Gera a textura do piso do cenérioa
//glColor3f(0.32,0.99,0.32);

glEnable (GL_BLEND); glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, txgrass);

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

  glBegin(GL_TRIANGLE_FAN);
      glTexCoord2f(0,0);glVertex3f(-2.0,-2.0, -1.0);
      glTexCoord2f(0,1);glVertex3f(-2.0, -0.8, -1.0);
      glTexCoord2f(1,1);glVertex3f(2.0, -0.8, -1.0);
      glTexCoord2f(1,0);glVertex3f(2.0, -2.0, -1.0);
  glEnd();
glDisable(GL_TEXTURE_2D);
}

void desenhaSair(Bounds b, int txsair) {
glEnable (GL_BLEND); glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, txsair);

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

  glBegin(GL_TRIANGLE_FAN);
      glTexCoord2f(0,0);glVertex3f(-2.0,b.bottom, 1.0);
      glTexCoord2f(0,1);glVertex3f(-2.0, b.top, 1.0);
      glTexCoord2f(1,1);glVertex3f(2.0, b.top, 1.0);
      glTexCoord2f(1,0); glVertex3f(2.0, b.bottom, 1.0);
  glEnd();
glDisable(GL_TEXTURE_2D);
}

void desenhaPausa(Bounds b, int txpausa) {
glEnable (GL_BLEND); glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, txpausa);

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

  glBegin(GL_TRIANGLE_FAN);
      glTexCoord2f(0,0);glVertex3f(-2.0,b.bottom, 1.0);
      glTexCoord2f(0,1);glVertex3f(-2.0, b.top, 1.0);
      glTexCoord2f(1,1);glVertex3f(2.0, b.top, 1.0);
      glTexCoord2f(1,0); glVertex3f(2.0, b.bottom, 1.0);
  glEnd();
glDisable(GL_TEXTURE_2D);
}

void desenhaReinicia(Bounds b, int txreinicia) {
glEnable (GL_BLEND); glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, txreinicia);

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

  glBegin(GL_TRIANGLE_FAN);
      glTexCoord2f(0,0);glVertex3f(-2.0,b.bottom, 1.0);
      glTexCoord2f(0,1);glVertex3f(-2.0, b.top, 1.0);
      glTexCoord2f(1,1);glVertex3f(2.0, b.top, 1.0);
      glTexCoord2f(1,0); glVertex3f(2.0, b.bottom, 1.0);
  glEnd();
glDisable(GL_TEXTURE_2D);
}

  /*glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(1,1,1);

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

  glBegin(GL_TRIANGLE_FAN);  //background
      glVertex3f(-2.0,b.bottom, -1.0);
      glVertex3f(-2.0, b.top, -1.0);
      glVertex3f(2.0, b.top, -1.0);
      glVertex3f(2.0, b.bottom, -1.0);

  glEnd();

  //glutSwapBuffers();
*/
