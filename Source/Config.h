#ifndef _CONFIG_H_
#define _CONFIG_H_
                       // movimientos binarios  1<<0=1  1<<1=10  1<<2=100   1<<3=1000
#define BORDE_IZQUIERDO  1<<0  //ESTE 0001 con << nos da el valor de borde_izquierdo y asi con todos
#define BORDE_SUPERIOR   1<<1  //ESTE 0010
#define BORDE_DERECHO    1<<2  //ESTE 0100
#define BORDE_INFERIOR   1<<3  //ESTE 1000  TODOS SON BINARIOS
#define WIDTH_SCREEN 640
#define HEIGHT_SCREEN 480
#define SPRITE_MODULE_MI_NAVE  0

#endif