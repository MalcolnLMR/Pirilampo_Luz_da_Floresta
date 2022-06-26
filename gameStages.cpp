#include "mylibrary.h"

void runStageCollider(int stage, TEntity* player, TStage stages[]){
	switch (stage){
		// Lista de Colisões do estágio 1
		case 1:
			// Colisões da ESQUERDA			
			if(colliderEntityLine(player, stages[stage-1].leftLimit, 1)) player->left	= false; // Parede						
			else if(colliderEntityRect(player, stages[stage-1].colliders[0], 1)) player->left = false;						
			else if(colliderEntityRect(player, stages[stage-1].colliders[1], 1)) player->left = false;						
			else if(colliderEntityRect(player, stages[stage-1].colliders[2], 1)) player->left = false;						
			//else if(colliderEntityRect(player, stages[stage-1].colliders[3], 1)) player->left = false;							
			else if(colliderEntityRect(player, stages[stage-1].colliders[4], 1)) player->left = false;	
						
			else player->left = true;
			
			// Colisões da DIREITA			
			if(colliderEntityLine(player, stages[stage-1].rightLimit, 2)) player->right = false;				
			else if(colliderEntityRect(player, stages[stage-1].colliders[0], 2)) player->right = false;	
			//else if(colliderEntityRect(player, stages[stage-1].colliders[1], 2)) player->right = false;
			//else if(colliderEntityRect(player, stages[stage-1].colliders[2], 2)) player->right = false;
			else if(colliderEntityRect(player, stages[stage-1].colliders[3], 2)) player->right = false;
			//else if(colliderEntityRect(player, stages[stage-1].colliders[4], 2)) player->right = false;
						
			else player->right = true;
			
			// Colisões de CIMA
			if(colliderEntityLine(player, stages[stage-1].upLimit, 3)) player->up	= false;				
			else if(colliderEntityRect(player, stages[stage-1].colliders[0], 3)) player->up = false;
			else if(colliderEntityRect(player, stages[stage-1].colliders[1], 3)) player->up = false;
			//else if(colliderEntityRect(player, stages[stage-1].colliders[2], 3)) player->up = false;						
			//else if(colliderEntityRect(player, stages[stage-1].colliders[3], 3)) player->up = false;						
			//else if(colliderEntityRect(player, stages[stage-1].colliders[3], 3)) player->up = false;
			
			else player->up = true;
			
			// Colisões de BAIXO
			if(colliderEntityLine(player, stages[stage-1].downLimit, 4)) player->down	= false;				
			//else if(colliderEntityRect(player, stages[stage-1].colliders[0], 4)) player->down = false;
			else if(colliderEntityRect(player, stages[stage-1].colliders[1], 4)) player->down = false;
			//else if(colliderEntityRect(player, stages[stage-1].colliders[2], 4)) player->down = false;
			else if(colliderEntityRect(player, stages[stage-1].colliders[3], 4)) player->down = false;
			else if(colliderEntityRect(player, stages[stage-1].colliders[4], 4)) player->down = false;
					
			else player->down = true;
		
			break;
		case 2:
			
			// Colisões da ESQUERDA
			if(colliderEntityLine(player, stages[stage-1].leftLimit, 1)) player->left	= false; // Parede						
			else if(colliderEntityRect(player, stages[stage-1].colliders[0], 1)) player->left = false;						
			//else if(colliderEntityRect(player, stages[stage-1].colliders[1], 1)) player->left = false;						
			else if(colliderEntityRect(player, stages[stage-1].colliders[2], 1)) player->left = false;						
			//else if(colliderEntityRect(player, stages[stage-1].colliders[3], 1)) player->left = false;							
			//else if(colliderEntityRect(player, stages[stage-1].colliders[4], 1)) player->left = false;							
			//else if(colliderEntityRect(player, stages[stage-1].colliders[5], 1)) player->left = false;	
						
			else player->left = true;
			
			// Colisões da DIREITA			
			if(colliderEntityLine(player, stages[stage-1].rightLimit, 2)) player->right = false;				
			//else if(colliderEntityRect(player, stages[stage-1].colliders[0], 2)) player->right = false;	
			else if(colliderEntityRect(player, stages[stage-1].colliders[1], 2)) player->right = false;
			//else if(colliderEntityRect(player, stages[stage-1].colliders[2], 2)) player->right = false;
			else if(colliderEntityRect(player, stages[stage-1].colliders[3], 2)) player->right = false;
			else if(colliderEntityRect(player, stages[stage-1].colliders[4], 2)) player->right = false;
			else if(colliderEntityRect(player, stages[stage-1].colliders[5], 2)) player->right = false;
						
			else player->right = true;
			
			// Colisões de CIMA
			if(colliderEntityLine(player, stages[stage-1].upLimit, 3)) player->up	= false;				
			else if(colliderEntityRect(player, stages[stage-1].colliders[0], 3)) player->up = false;
			else if(colliderEntityRect(player, stages[stage-1].colliders[1], 3)) player->up = false;
			else if(colliderEntityRect(player, stages[stage-1].colliders[2], 3)) player->up = false;						
			//else if(colliderEntityRect(player, stages[stage-1].colliders[3], 3)) player->up = false;						
			//else if(colliderEntityRect(player, stages[stage-1].colliders[4], 3)) player->up = false;						
			else if(colliderEntityRect(player, stages[stage-1].colliders[5], 3)) player->up = false;
			
			else player->up = true;
			
			// Colisões de BAIXO
			if(colliderEntityLine(player, stages[stage-1].downLimit, 4)) player->down	= false;				
			//else if(colliderEntityRect(player, stages[stage-1].colliders[0], 4)) player->down = false;
			else if(colliderEntityRect(player, stages[stage-1].colliders[1], 4)) player->down = false;
			else if(colliderEntityRect(player, stages[stage-1].colliders[2], 4)) player->down = false;
			else if(colliderEntityRect(player, stages[stage-1].colliders[3], 4)) player->down = false;
			else if(colliderEntityRect(player, stages[stage-1].colliders[4], 4)) player->down = false;
			//else if(colliderEntityRect(player, stages[stage-1].colliders[5], 4)) player->down = false;
					
			else player->down = true;
			break;
		case 3:
			
			// Colisões da ESQUERDA
			if(colliderEntityLine(player, stages[stage-1].leftLimit, 1)) player->left	= false; // Parede						
			else if(colliderEntityRect(player, stages[stage-1].colliders[0], 1)) player->left = false;						
			//else if(colliderEntityRect(player, stages[stage-1].colliders[1], 1)) player->left = false;						
			else if(colliderEntityRect(player, stages[stage-1].colliders[2], 1)) player->left = false;						
			else if(colliderEntityRect(player, stages[stage-1].colliders[3], 1)) player->left = false;							
			//else if(colliderEntityRect(player, stages[stage-1].colliders[4], 1)) player->left = false;							
			else if(colliderEntityRect(player, stages[stage-1].colliders[5], 1)) player->left = false;	
						
			else player->left = true;
			
			// Colisões da DIREITA			
			if(colliderEntityLine(player, stages[stage-1].rightLimit, 2)) player->right = false;				
			//else if(colliderEntityRect(player, stages[stage-1].colliders[0], 2)) player->right = false;	
			else if(colliderEntityRect(player, stages[stage-1].colliders[1], 2)) player->right = false;
			//else if(colliderEntityRect(player, stages[stage-1].colliders[2], 2)) player->right = false;
			else if(colliderEntityRect(player, stages[stage-1].colliders[3], 2)) player->right = false;
			else if(colliderEntityRect(player, stages[stage-1].colliders[4], 2)) player->right = false;
			else if(colliderEntityRect(player, stages[stage-1].colliders[5], 2)) player->right = false;
						
			else player->right = true;
			
			// Colisões de CIMA
			if(colliderEntityLine(player, stages[stage-1].upLimit, 3)) player->up	= false;				
			else if(colliderEntityRect(player, stages[stage-1].colliders[0], 3)) player->up = false;
			else if(colliderEntityRect(player, stages[stage-1].colliders[1], 3)) player->up = false;
			else if(colliderEntityRect(player, stages[stage-1].colliders[2], 3)) player->up = false;						
			else if(colliderEntityRect(player, stages[stage-1].colliders[3], 3)) player->up = false;						
			//else if(colliderEntityRect(player, stages[stage-1].colliders[4], 3)) player->up = false;						
			else if(colliderEntityRect(player, stages[stage-1].colliders[5], 3)) player->up = false;
			
			else player->up = true;
			
			// Colisões de BAIXO
			if(colliderEntityLine(player, stages[stage-1].downLimit, 4)) player->down	= false;				
			//else if(colliderEntityRect(player, stages[stage-1].colliders[0], 4)) player->down = false;
			//else if(colliderEntityRect(player, stages[stage-1].colliders[1], 4)) player->down = false;
			else if(colliderEntityRect(player, stages[stage-1].colliders[2], 4)) player->down = false;
			else if(colliderEntityRect(player, stages[stage-1].colliders[3], 4)) player->down = false;
			else if(colliderEntityRect(player, stages[stage-1].colliders[4], 4)) player->down = false;
			else if(colliderEntityRect(player, stages[stage-1].colliders[5], 4)) player->down = false;
					
			else player->down = true;
			
			
			break;
		case 4:
			
			// Colisões da ESQUERDA
			if(colliderEntityLine(player, stages[stage-1].leftLimit, 1)) player->left	= false; // Parede							
			else player->left = true;
			
			// Colisões da DIREITA			
			if(colliderEntityLine(player, stages[stage-1].rightLimit, 2)) player->right = false;								
			else player->right = true;
			
			// Colisões de CIMA
			if(colliderEntityLine(player, stages[stage-1].upLimit, 3)) player->up	= false;					
			else player->up = true;
			
			// Colisões de BAIXO
			if(colliderEntityLine(player, stages[stage-1].downLimit, 4)) player->down	= false;							
			else player->down = true;
			
			
			break;
	}
}

void moveStage(TStage *stage, int actualStage, int dy){
	/*
		dir: 0 // Para baixo
		dir: 1 // Para cima
	*/
	if(dy > 0){
		stage[actualStage-1].bgy += dy;
		stage[actualStage].bgy += dy;		
	}
	else if(dy < 0){
		stage[actualStage-2].bgy += dy;
		stage[actualStage-1].bgy += dy;		
	}	
}

TStage setStage(TLine leftLimit, TLine rightLimit, TLine upLimit, TLine downLimit){
	TStage temp;
	temp.leftLimit = leftLimit;
	temp.rightLimit = rightLimit;
	temp.upLimit = upLimit;
	temp.downLimit = downLimit;
	for(int i = 0; i < 6; i++){
		temp.colliders[i].x = -1;
		temp.colliders[i].y = -1;
	}
	temp.active = false;
	temp.bgx = 0;
	temp.bgy = 0;
	return temp;
}

void drawStage(TStage stage){
	if(stage.active){
		putimage(stage.bgx, stage.bgy, stage.background, COPY_PUT);		
	}
}
