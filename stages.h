#ifndef STAGES_H
#define STAGES_H

#define GAME 1
#define MENU 2
#define GAMEOVER 3
#define LOADGAME 4
#define PAUSE 5
#define EXIT 6

struct TPlataform{
	bool orientation; // Quais direções de colisão deverão ser calculadas
	TRect collider;
};

struct TStage {
	int leftLimit, rightLimit, upLimit, downLimit;
};

void runStageCollider(int stage, TEntity* player);
void changeStage(int endStage);



#endif
