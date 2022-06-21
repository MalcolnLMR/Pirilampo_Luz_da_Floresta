#include "mylibrary.h"

bool canMove(TEntity en){
	return true;
}

void destroyEntity(TEntity *en){
	en->show = false;
	//free(en->sprite);
	//free(en->mask);
}
