//#include <GL/glew.h>
#include <GL/freeglut.h> // Facilita a criação de código e portabilidade do código OpenGL
#include <time.h> // Biblioteca padrão que carrega funções de tempo
#include <stdio.h> // Biblioteca padrão de input/output
#include <stdlib.h> // Biblioteca padrão de C
#include "SOIL/SOIL.h" // Biblioteca utilizada para o carregamento de texturas

// EStrutura de ajuste global



// Minhas bibliotecas
#include "background.h"
#include "tads.h"
#include "players.h"
#include "projetil.h"
#include "mira.h"
#include "loadtexture.h"
#include "obstacle.h"
#include "vento.h"
#include "hearth.h"

//glflush e importante pra carai
Bounds bounds = (Bounds){0,0,0,0};
Vento wind;
Player player1, player2; // Inicializa novos tipos player
Projetil projetil; // Inicializa um novo tipo projétil
Mira mira; // Inicializa um novo tipo mira
Obstacle o1,o2, o3,o4,o5,o6,o7;
Hearth hearths [6];
int txmira, txbackground, txgrass, txstorm, txewok, // Inicializa os comandos que definem as texturas
txbullet, txsair, txpausa, txreinicia, txobstacle,txvento, txhearth,
estadojogo = 0, // Inicializa e define o início da máquina de estados que controla o jogo
auxiliarEstado = 0, // Armazena o estado anterior da máquina de estados
pause = 0;

//Variaveis de controle
int setupfeito = 0;

float randomFloat() {
      float r = (float)rand() / (float)RAND_MAX;
      //printf("%f\n",r);
      return r;
}


void desenho() {
    if((estadojogo == 0) || (estadojogo == 2)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1,1,1);
            desenhaMinhaCena(bounds,txbackground, txgrass);
            desenhaPlayer(player1,txstorm);
            desenhaPlayer(player2,txewok);
            desenhaObstaculo(o2, txobstacle);
            desenhaObstaculo(o1, txobstacle);
            desenhaObstaculo(o3, txobstacle);
            desenhaObstaculo(o4, txobstacle);
            desenhaObstaculo(o5, txobstacle);
            desenhaObstaculo(o6, txobstacle);
            desenhaObstaculo(o7, txobstacle);
            desenhaVento(wind, txvento);
            verificaHearth(hearths,player1,player2,txhearth);
            //desenhaProjetil(projetil);
            desenhaMira(mira,txmira);
        glColor3f(0,0,0);
        glutSwapBuffers();
    }

    if ((estadojogo == 1) || (estadojogo == 3)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1,1,1);
            desenhaMinhaCena(bounds,txbackground, txgrass);
            desenhaPlayer(player1,txstorm);
            desenhaPlayer(player2,txewok);
            desenhaObstaculo(o2, txobstacle);
            desenhaObstaculo(o1, txobstacle);
            desenhaObstaculo(o3, txobstacle);
            desenhaObstaculo(o4, txobstacle);
            desenhaObstaculo(o5, txobstacle);
            desenhaObstaculo(o6, txobstacle);
            desenhaObstaculo(o7, txobstacle);
            desenhaVento(wind, txvento);
            verificaHearth(hearths,player1,player2,txhearth);
            desenhaProjetil(projetil,txbullet);
            //desenhaMira(mira,txmira);
        glColor3f(0,0,0);
        glutSwapBuffers();
    }

    if (estadojogo == 4) {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1,1,1);
            desenhaMinhaCena(bounds, txbackground, txgrass);
            desenhaSair(bounds, txsair);
        glColor3f(0,0,0);
        glutSwapBuffers();
    }

    if (estadojogo == 5) {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1,1,1);
            desenhaMinhaCena(bounds, txbackground, txgrass);
            desenhaPausa(bounds, txpausa);
        glColor3f(0,0,0);
        glutSwapBuffers();
    }

    if (estadojogo == 6) {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1,1,1);
            desenhaMinhaCena(bounds, txbackground, txgrass);
            desenhaReinicia(bounds, txreinicia);
        glColor3f(0,0,0);
        glutSwapBuffers();
    }
}

void atualiza() {
    glutPostRedisplay();
}

int verificaColisoes(Projetil p){

  if (verificaObstaculo(o1,projetil)){
    o1.dimy=o1.dimy-0.1;
    o1.posy = o1.posy - o1.dimy/16;
    return 1;
  }
  if (verificaObstaculo(o2,projetil)){
    o2.dimy=o2.dimy-0.1;
    o2.posy = o2.posy - o2.dimy/16;
    return 1;
  }
  if (verificaObstaculo(o3,projetil)){
    o3.dimy=o3.dimy-0.1;
    o3.posy = o3.posy - o3.dimy/16;
    return 1;
  }
  if (verificaObstaculo(o4,projetil)){
    o4.dimy=o4.dimy-0.1;
    o4.posy = o4.posy - o4.dimy/16;
    return 1;
  }
  if (verificaObstaculo(o5,projetil)){
    o5.dimy=o5.dimy-0.1;
    o5.posy = o5.posy - o5.dimy/16;
    return 1;
  }
  if (verificaObstaculo(o6,projetil)){
    o6.dimy=o6.dimy-0.1;
    o6.posy = o6.posy - o6.dimy/16;
    return 1;
  }
  if (verificaObstaculo(o7,projetil)){
    o7.dimy=o7.dimy-0.1;
    o7.posy = o7.posy - o7.dimy/16;
    return 1;
  }



}



void atualizaValores() {
    if(estadojogo == 1) {
        projetil = atualizaProjetil(projetil,wind);
        if(verificaPosicao(player2,projetil)) {
            //printf("ACERTOU NIGGA\n");
            wind = atualizaVento(wind);
            player2.hp=player2.hp-10*player1.atk;
            if (player2.hp>0){
              estadojogo = 2;

            }else{
              estadojogo = 7;
            }

            projetil = criaProjetil(projetil, player2, 0.01, 0.05);
            mira = criaMira(projetil,mira);
        }
        if(verificaColisoes(projetil)) {
            //printf("ERROU NIGGA\n");
            wind = atualizaVento(wind);
            estadojogo = 2;
            projetil = criaProjetil(projetil, player2, 0.01, 0.05);
            mira = criaMira(projetil,mira);
        }
    }

    if ((estadojogo == 1) && (projetil.posy<-1.0)) {
        wind = atualizaVento(wind);
        estadojogo = 2;
        projetil = criaProjetil(projetil, player2, 0.01, 0.05);
        mira = criaMira(projetil,mira);
    }

    if(estadojogo == 3) {
        projetil = atualizaProjetil(projetil,wind);
        if(verificaPosicao(player1,projetil)){
            //printf("ACERTOU NIGGA1\n");
            wind = atualizaVento(wind);
            player1.hp=player1.hp-10*player2.atk;
            if (player2.hp>0){
              estadojogo = 0;
            }else{
              estadojogo = 7;
            }
            projetil = criaProjetil(projetil, player1, 0.01, 0.05);
            mira = criaMira(projetil,mira);
        }
        if(verificaColisoes(projetil)){
            //printf("ERROU NIGGA1\n");
            wind = atualizaVento(wind);
            estadojogo = 0;
            projetil = criaProjetil(projetil, player1, 0.01, 0.05);
            mira = criaMira(projetil,mira);
        }
    }

    if((estadojogo == 3) && (projetil.posy < -1.0)) {
        estadojogo = 0;
        wind = atualizaVento(wind);
        projetil = criaProjetil(projetil, player1, 0.01, 0.05);
        mira = criaMira(projetil,mira);
    }

    glutTimerFunc(10,atualizaValores,0);
}

// NOVIDADE: uma função que vamos chamar dentro
//    do "main"
// Inicia algumas variáveis de estado do OpenGL
void setup() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Define a cor de fundo, neste caso branco
        player1 = criaStorm(bounds, player1);
        player2 = criaEwok(bounds, player2);
        projetil = criaProjetil(projetil, player1, 0.01, 0.05);
        mira = criaMira(projetil,mira);
        o1 = criaObstaculo(o1, -0.3, -0.7);
        o2 = criaObstaculo(o2, 0.0, -0.7);
        o3 = criaObstaculo(o3, 0.3, -0.7);
        o4= criaObstaculo(o3, 0.-5, -0.7);
        o5 = criaObstaculo(o3, 0.5, -0.7);
        o6 = criaObstaculo(o3, -1.3, -0.7);
        o7 = criaObstaculo(o3, 1.3, -0.7);
        wind=atualizaVento(wind);
        hearths[0]=criaHearth(hearths[0],-1.3,0.8);
        hearths[1]=criaHearth(hearths[1],-1.2,0.8);
        hearths[2]=criaHearth(hearths[2],-1.1,0.8);
        hearths[3]=criaHearth(hearths[3],1.1,0.8);
        hearths[4]=criaHearth(hearths[4],1.2,0.8);
        hearths[5]=criaHearth(hearths[5],1.3,0.8);

        // desenho preenchido vs. contorno
        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    setupfeito = 1;
}

// NOVIDADE: callback para o evento "reshape"
void redimensionada(int width, int height) {
    if (height == 0) height = 1; //

    double ratio = (double)width / (double)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    bounds = (Bounds){-ratio,ratio,-1.0,1.0};
//   printf("%f ",bounds.left);
//-ratio, ratio, -1, 1, -1, 1);//
    glOrtho(bounds.left,bounds.right, bounds.bottom,bounds.top, -1.0, 1.0);

/*  if (width<=height){
    gluOrtho2D(0.0, janelaw, 0.0, janelah*height/width);
  }else{
    gluOrtho2D(0.0, janelaw*width/height/2, 0.0, janelah);
  }*/

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void mousePressionado(int botao, int estado, int x, int y) {
    if ((botao == GLUT_LEFT_BUTTON) && (estado == GLUT_UP)) {
        printf("%d e %d\n", x, y);
        if (estadojogo == 4) {
            if ((y > 0) && (y < 600)) {
                if ((x > 0) && (x < 400)) {
                    exit(0);
                } else if ((x > 400) && (x < 1000)) {
                    estadojogo = auxiliarEstado;
                }
            }
        }

        if (estadojogo == 6 || estadojogo == 7) {
            if ((y > 0) && (y < 600)) {
                if ((x > 0) && (x < 400)) {
                    estadojogo = 0;
                    setup();
                } else if ((x > 400) && (x < 1000)) {
                    if (estadojogo == 6) estadojogo = auxiliarEstado;
                    if (estadojogo == 7) exit(0);
                }
            }
        }
    }
}

// NOVIDADE: callback de "keyboard"
void teclaPressionada(unsigned char key, int x, int y) {
    //printf("%d -> %c\n",key,key);
    // vê qual tecla foi pressionada
    switch(key)
    {
        case 27: // Tecla ESC, sai do jogo
            auxiliarEstado = estadojogo;
            estadojogo = 4;
            glutPostRedisplay();
            break;
        case 112: // Tecla "p", pausa o jogo
            if (pause == 0) {
                auxiliarEstado = estadojogo;
                estadojogo = 5;
                pause = 1;
            } else if (pause == 1) {
                estadojogo = auxiliarEstado;
                pause = 0;
            }
            glutPostRedisplay();
            break;
        case 114: // Tecla "r", reinicia o jogo
            auxiliarEstado = estadojogo;
            estadojogo = 6;
            glutPostRedisplay();
            break;
        case 99: //tecla "c"
            glutPostRedisplay();
            //glutDisplayFunc(desenhaContorno); // Desenha a trajetória do projétil
            break;
        case 119: //tecla "w"
            mira=atualizaMira(mira,0.0,0.02); // Move a mira para cima
            break;
        case 97: //tecla "A"
            mira=atualizaMira(mira,-0.02,0.0); // Move a mira para esquerda
            break;
        case 115: //tecla "S"
            mira=atualizaMira(mira,0.0,-0.02); // Move a mira para baixo
            break;
        case 100: //tecla "D"
            mira=atualizaMira(mira,0.02,0.0); // Move a mira para direita
            break;
        case 32: // espaco
            if(estadojogo == 0) {
                estadojogo=1;
                projetil= criaProjetil(projetil, player1, (mira.posx-player1.posx)/10, (mira.posy-player1.posy)/10);
            }
            if(estadojogo==2){
                estadojogo=3;
                projetil= criaProjetil(projetil, player2, (mira.posx-player2.posx)/10, (mira.posy-player2.posy)/10);
            }
            break;
        default:
            break;
    }
}

// Função principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);

//   glutInitContextVersion(1, 1);
 //  glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    srand(time(NULL));
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Star Worms");

    // Registra callbacks para alguns eventos
    glutDisplayFunc(desenho);
    glutReshapeFunc(redimensionada);
    glutKeyboardFunc(teclaPressionada);
    glutTimerFunc(10,atualizaValores,0);

    glutMouseFunc(mousePressionado);

    glutIdleFunc(atualiza);

    // Configura valor inicial de algumas
    // variáveis de estado do OpenGL
    if (!setupfeito) {
        setup();
        txmira = loadmira();
        txbackground = loadbackground();
        txgrass = loadgrass();
        txstorm = loadstorm();
        txewok = loadewok();
        txbullet = loadbullet();
        txobstacle = loadobstacle();
        txsair = loadsair();
        txpausa = loadpausa();
        txreinicia = loadreinicia();
        txvento = loadseta();
        txhearth = loadhearth();
    }
    glutMainLoop();
    return 0;
}
