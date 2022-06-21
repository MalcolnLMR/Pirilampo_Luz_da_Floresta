#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H

#define LEFT_ 1
#define RIGHT_ 2
#define UP_ 3
#define DOWN_ 4

// "PAUSA" PARA TROCA DE ESTÁGIO
// VERTICAL E HORIZONTAL

struct TStage{
	TRect colliders[10];
	bool active;
	int size;
};

bool colliderRectRect(TRect obj1, TRect obj2, int orientation = 0);
bool colliderCircleRect(TCircle obj1, TRect obj2);
bool colliderMouseRect(POINT mouse, TRect obj);
int getRectWidth(TRect obj);
int getRectHeight(TRect obj);
TRect Rect(int x, int y, int width, int height);
void seekEntity(TRect* collider, TEntity *en,int offsetX = 0, int offsetY = 0);
void syncEntityCollider(TEntity *en, int coffset = 0);
void addCollider(TStage *stg, TRect collider);



#endif
