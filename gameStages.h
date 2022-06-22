#ifndef GAMESTAGES_H
#define GAMESTAGES_H

/* GAME STATES */ 
#define GAME 1
#define MENU 2
#define GAMEOVER 3
#define LOADGAME 4
#define PAUSE 5
#define EXIT 6

struct TStage{
	TLine leftLimit;
	TLine rightLimit;
	TLine upLimit;
	TLine downLimit;
	TRect colliders[5];
	bool active;
};

struct TPlataform{
	bool orientation; // Quais direções de colisão deverão ser calculadas
	TRect collider;
};


void runStageCollider(int stage, TEntity* player, TStage stages[6]);
void changeStage(int endStage);
TStage setStage(TLine leftLimit, TLine rightLimit, TLine upLimit, TLine downLimit);
void moveStage(TStage *stage, int dy);



#endif
