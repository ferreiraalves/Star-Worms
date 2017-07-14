#include <GL/freeglut.h>  // em vez de áspas
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tads.h"
#include "obstacle.h"


void desenhaObstaculo(Obstacle o, int txobstacle){

    if (o.dimy>0.3){

      glColor3f(1,1,1);

      glEnable (GL_BLEND); glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      glEnable(GL_TEXTURE_2D);
          glBindTexture(GL_TEXTURE_2D, txobstacle);

          glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

          glBegin(GL_TRIANGLE_FAN);

          glTexCoord2f(0,0);glVertex3f(o.posx-(o.dimx/2), o.posy-(o.dimy/2), 0.0);
          glTexCoord2f(0,1);glVertex3f(o.posx-(o.dimx/2), o.posy+(o.dimy/2), 0.0);
          glTexCoord2f(1,1);glVertex3f(o.posx+(o.dimx/2), o.posy+(o.dimy/2), 0.0);
          glTexCoord2f(1,0);glVertex3f(o.posx+(o.dimx/2), o.posy-(o.dimy/2), 0.0);
      glEnd();
      glDisable(GL_TEXTURE_2D);
    }

}


Obstacle criaObstaculo( Obstacle o, double x, double y){
    // Define as dimensões do Obstaculo
    o.dimx = 0.3 + 0.3* (float)rand()/(float)(RAND_MAX);
    //printf("%lf\n",o.dimy);
    o.dimy = o.dimx*2;
    printf("%lf\n",o.dimy);
    o.posx = x;

    o.posy = y + o.dimy/4;
    return o;
}


int verificaObstaculo(Obstacle o, Projetil p) {
    if ((fabs(p.posx-o.posx)<(p.dim+o.dimx)/2) && (fabs(p.posy-o.posy)<(p.dim+o.dimy)/2) && o.dimy>0.3){
        return 1;
    } else
        return 0;
}
