#include <GL/freeglut.h>  // em vez de áspas
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "tads.h"


void desenhaPlayer(Player p, int txplayer){
    glColor3f(1,1,1);

    glEnable (GL_BLEND); glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, txplayer);

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        glBegin(GL_TRIANGLE_FAN);

        glTexCoord2f(0,0);glVertex3f(p.posx-(p.dimx/2), p.posy-(p.dimy/2), 0.0);
        glTexCoord2f(0,1);glVertex3f(p.posx-(p.dimx/2), p.posy+(p.dimy/2), 0.0);
        glTexCoord2f(1,1);glVertex3f(p.posx+(p.dimx/2), p.posy+(p.dimy/2), 0.0);
        glTexCoord2f(1,0);glVertex3f(p.posx+(p.dimx/2), p.posy-(p.dimy/2), 0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

// Define as características do player Stormtrooper
Player criaStorm(Bounds b, Player player1){
    // Define as dimensões do personagem Storm
    player1.dimx=0.3;
    player1.dimy=0.3;
    player1.posx=-1.0;//corrige saporra
    player1.posy=-0.8;
    // Identificação do personagem Storm
    player1.id=0;
    // Define as características do personagem Storm
    player1.hp=30; // Número de vidas
    player1.atk=1; // Danos de ataque
    player1.def=1; // Defesa
    player1.spd=1; // Velocidade
    // Retorna o personagem Storm com todas suas características definidas
    return player1;
}

// Define as características do player Ewok
Player criaEwok(Bounds b, Player player2){
    // Define as dimensões do personagem Ewok
    player2.dimx=0.3;
    player2.dimy=0.3;
    player2.posx=1.0; //corrige saporra
    player2.posy=-0.8;
    // Identificação do personagem Ewok
    player2.id=1;
    // Define as características do personagem Storm
    player2.hp=30; // Número de vidas
    player2.atk=1; // Danos de ataque
    player2.def=1; // Defesa
    player2.spd=1; // Velocidade
    // Retorna o personagem Ewok com todas suas características definidas
    return player2;
}
