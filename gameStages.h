#ifndef GAMESTAGES_H
#define GAMESTAGES_H

/* GAME STATES */ 
#define GAME 1
#define MENU 2
#define GAMEOVER 3
#define LOADGAME 4
#define PAUSE 5
#define EXIT 6

/* GAME OBJ */
#define GLASS 0
#define SPATULA 1
#define ORB 2
#define KEYOFF 3
#define FLOWER 4
#define PAJE 5
#define KEYON 6

struct TStage{
	/* PAREDES LIMITADORAS */
	TLine leftLimit;
	TLine rightLimit;
	TLine upLimit;
	TLine downLimit;
	/* LISTA DE COLISÕES */
	TRect colliders[5];
	/* BACKGROUND */ 
	int bgx, bgy; // Coordenadas do Background
	unsigned char *background;
	bool active;
};

struct TPlataform{
	bool orientation; // Quais direções de colisão deverão ser calculadas
	TRect collider;
};


void runStageCollider(int stage, TEntity* player, TStage stages[4]);
void changeStage(int endStage);
TStage setStage(TLine leftLimit, TLine rightLimit, TLine upLimit, TLine downLimit);
void moveStage(TStage *stage, int actualStage, int dy);
void drawStage(TStage stage);



#endif
