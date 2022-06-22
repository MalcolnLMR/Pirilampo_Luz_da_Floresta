#include "mylibrary.h"

void runStageCollider(int stage, TEntity* player, TStage stages[]){
	switch (stage){
		// Lista de Colisões do estágio 1
		case 1:
			// Colisões da ESQUERDA
			
			if(colliderEntityLine(player, stages[0].leftLimit, 1)) player->left	= false; // Parede
						
			else if(colliderEntityRect(player, stages[0].colliders[0], 1)) player->left = false;	
						
			else player->left = true;
			
			// Colisões da DIREITA
			
			if(colliderEntityLine(player, stages[0].rightLimit, 2)) player->right = false;	
			
			else if(colliderEntityRect(player, stages[0].colliders[0], 2)) player->right = false;			
			else player->right = true;
			
			// Colisões de CIMA
			if(colliderEntityLine(player, stages[0].upLimit, 3)) player->up	= false;
				
			else if(colliderEntityRect(player, stages[0].colliders[0], 3)) player->up = false;			
			else player->up = true;
			
			// Colisões de BAIXO
			if(colliderEntityLine(player, stages[0].downLimit, 4)) player->down	= false;
				
			//else if(colliderRectRect(player->collider, stages[0].colliders[0], 4)) player->down = false;	
					
			else player->down = true;
			
			break;
		case 2:
			// Colisões da ESQUERDA
			
			// Colisões da DIREITA
			
			// Colisões de CIMA
			
			// Colisões de BAIXO		
			
			break;
		case 3:
			
			
			break;
	}
}

void changeStage(int endStage){
	
}

TStage setStage(TLine leftLimit, TLine rightLimit, TLine upLimit, TLine downLimit){
	TStage temp;
	temp.leftLimit = leftLimit;
	temp.rightLimit = rightLimit;
	temp.upLimit = upLimit;
	temp.downLimit = downLimit;
	printf("%d", temp.downLimit);
	return temp;
}
