#ifndef _TADS_H_
#define _TADS_H_

typedef struct bounds {
    double left;
    double right;
    double bottom;
    double top;
} Bounds;

typedef struct player {
    double posx;
    double posy;
    double dimx;
    double dimy;

    int hp;
    int atk;
    int def;
    int spd;
    int id;

    int skillpoints;
} Player;

typedef struct projetil {
    double posx;
    double posy;
    double dim;

    double vx;
    double vy;

    int live;
} Projetil;

typedef struct mira {
    double posx;
    double posy;
    double dim;
} Mira;

typedef struct obstacle{
  double posx;
  double posy;
  double dimx;
  double dimy;
  double hits;

} Obstacle;

typedef struct vento{

  double power;

}Vento;

typedef struct hearth {
    double posx;
    double posy;
    double dim;
} Hearth;




#endif
