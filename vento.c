#include <GL/freeglut.h>  // em vez de áspas
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tads.h"
#include "obstacle.h"
#include "vento.h"


void desenhaVento(Vento v, int txvento){

      glColor3f(1,1,1);

      glEnable (GL_BLEND); glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      glEnable(GL_TEXTURE_2D);
          glBindTexture(GL_TEXTURE_2D, txvento);

          glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

          glBegin(GL_TRIANGLE_FAN);

          glTexCoord2f(0,0);glVertex3f(0.0, 0.4, 0.0);
          glTexCoord2f(0,1);glVertex3f(0.0, 0.8, 0.0);
          glTexCoord2f(1,1);glVertex3f(v.power, 0.8, 0.0);
          glTexCoord2f(1,0);glVertex3f(v.power, 0.4, 0.0);
      glEnd();
      glDisable(GL_TEXTURE_2D);

}

Vento atualizaVento(Vento v){
  int i=rand()%2;
  if(i==0){
    v.power=(float)rand()/(float)(RAND_MAX);
  }else{
    v.power=-(float)rand()/(float)(RAND_MAX);
  }


  return v;
}
