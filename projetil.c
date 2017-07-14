#include <GL/freeglut.h>  // em vez de áspas
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tads.h"
#include "projetil.h"
#include "vento.h"

void desenhaProjetil(Projetil p, int txbullet){
    glColor3f(1,1,1);
    glEnable (GL_BLEND); glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, txbullet);
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            glBegin(GL_TRIANGLE_FAN);  //Player
                glTexCoord2f(0,0); glVertex3f(p.posx-(p.dim/2), p.posy-(p.dim/2), 0.0);
                glTexCoord2f(1,0); glVertex3f(p.posx+(p.dim/2), p.posy-(p.dim/2), 0.0);
                glTexCoord2f(1,1); glVertex3f(p.posx+(p.dim/2), p.posy+(p.dim/2), 0.0);
                glTexCoord2f(0,1); glVertex3f(p.posx-(p.dim/2), p.posy+(p.dim/2), 0.0);
            glEnd();
        glDisable(GL_TEXTURE_2D);
        //glutSwapBuffers();
}

Projetil criaProjetil(Projetil projetil, Player p, double vx, double vy){
    if(p.id==0){
        projetil.posx=p.posx+(p.dimx/2)+0.01;
        projetil.posy=p.posy+(p.dimy/2)+0.01;
    } else {
        projetil.posx=p.posx-(p.dimx/2)-0.01;
        projetil.posy=p.posy+(p.dimy/2)+0.01;
    }
    projetil.dim=0.1;
    projetil.vx=vx;
    projetil.vy=vy;
    return projetil;
}

Projetil atualizaProjetil(Projetil p, Vento v) {
    p.vy=p.vy-0.001;
    p.vx=p.vx+(v.power/2000);
    p.posx=p.posx+p.vx;
    p.posy=p.posy+p.vy;
    return p;
}

int verificaPosicao(Player player, Projetil p) {
    if ((fabs(p.posx-player.posx)<(p.dim+player.dimx)/2) && (fabs(p.posy-player.posy)<(p.dim+player.dimy)/2)){
        return 1;
    } else
        return 0;
}
