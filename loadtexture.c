#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include "loadtexture.h"
#include "SOIL/SOIL.h"


// Carrega a textura da mira utilizando o SOIL
int loadmira(){
    int aux=SOIL_load_OGL_texture(
        "miratexture.png", // Textura da mira
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );
    if (aux==0){
        printf("Erro do SOIL: %s\n",SOIL_last_result());
    }
    return aux;
}


// Carrega a textura do background utilizando o SOIL
int loadbackground(){
    int aux=SOIL_load_OGL_texture(
        "background.png", // Textura do background
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );
    if (aux==0){
        printf("Erro do SOIL: %s\n",SOIL_last_result());
    }
    return aux;
}

// Carrega a textura do piso utilizando o SOIL
int loadgrass(){
    int aux=SOIL_load_OGL_texture(
        "grass.png", // Textura do piso
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );
    if (aux==0){
        printf("Erro do SOIL: %s\n",SOIL_last_result());
    }
    return aux;
}

// Carrega a textura do Stormtrooper utilizando o SOIL
int loadstorm(){
    int aux=SOIL_load_OGL_texture(
        "storm.png", // Textura do Stormtrooper
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );
    if (aux==0){
        printf("Erro do SOIL: %s\n",SOIL_last_result());
    }
    return aux;
}

// Carrega a textura do Obstaculo utilizando o SOIL
int loadobstacle(){
    int aux=SOIL_load_OGL_texture(
        "tree.png", // Textura da arvore
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );
    if (aux==0){
        printf("Erro do SOIL: %s\n",SOIL_last_result());
    }
    return aux;
}


// Carrega a textura do Ewok utilizando o SOIL
int loadewok(){
    int aux=SOIL_load_OGL_texture(
        "ewok.png", // Textura do Ewok
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );
    if (aux==0){
        printf("Erro do SOIL: %s\n",SOIL_last_result());
    }
    return aux;
}

// Carrega a textura do projétil utilizando o SOIL
int loadbullet(){
    int aux=SOIL_load_OGL_texture(
        "bullet.png", // Textura do projétil
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );
    if (aux==0){
        printf("Erro do SOIL: %s\n",SOIL_last_result());
    }
    return aux;
}

// Carrega a textura da tela sair utilizando o SOIL
int loadsair(){
    int aux=SOIL_load_OGL_texture(
        "sair.png", // Textura da tela sair
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );
    if (aux==0){
        printf("Erro do SOIL: %s\n",SOIL_last_result());
    }
    return aux;
}

// Carrega a textura da tela de pausa utilizando o SOIL
int loadpausa(){
    int aux=SOIL_load_OGL_texture(
        "pause.png", // Textura da tela de pause
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );
    if (aux==0){
        printf("Erro do SOIL: %s\n",SOIL_last_result());
    }
    return aux;
}



// Carrega a textura do projétil utilizando o SOIL
int loadreinicia(){
    int aux=SOIL_load_OGL_texture(
        "reiniciar.png", // Textura da tela reiniciar
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );
    if (aux==0){
        printf("Erro do SOIL: %s\n",SOIL_last_result());
    }
    return aux;
}

// Carrega a textura da seta utilizando o SOIL
int loadseta(){
    int aux=SOIL_load_OGL_texture(
        "arrow.png", // Textura da tela reiniciar
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );
    if (aux==0){
        printf("Erro do SOIL: %s\n",SOIL_last_result());
    }
    return aux;
}

int loadhearth(){
    int aux=SOIL_load_OGL_texture(
        "heart.png", // Textura da tela reiniciar
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );
    if (aux==0){
        printf("Erro do SOIL: %s\n",SOIL_last_result());
    }
    return aux;
}
