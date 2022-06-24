#ifndef ENTITY_H
#define ENTITY_H

//	Lidar com as entidades do jogo

struct TEntity{
	// Coordenadas e movimentação
	int x, y;
	bool right, left, up, down;  // Variaves de verificação de movimentação
	
	// Atributos da entidade
	int hp, spd;                 // Vida e Velocidade de movimento
	
	// Sprite e máscara
	unsigned char *sprite, *mask;
	int size;
	
	// Retângulos de colisão
	TRect collider;
	TRect cright, cleft, cup, cdown;
	
	// Verificação para desenhar na tela
	bool show;
	int stage;
	
	// Está se movimentando
	bool isMoving;
};

void destroyEntity(TEntity *en);



#endif
