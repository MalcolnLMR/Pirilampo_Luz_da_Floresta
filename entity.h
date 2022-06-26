#ifndef ENTITY_H
#define ENTITY_H

//	Lidar com as entidades do jogo

struct TEntity{
	// Coordenadas e movimenta��o
	int x, y;
	bool right, left, up, down;  // Variaves de verifica��o de movimenta��o
	
	// Atributos da entidade
	int hp, spd;                 // Vida e Velocidade de movimento
	
	// Sprite e m�scara
	unsigned char *sprite, *mask;
	int size;
	
	// Ret�ngulos de colis�o
	TRect collider;
	TRect cright, cleft, cup, cdown;
	
	// Verifica��o para desenhar na tela
	bool show;
	int stage;
	
	// Est� se movimentando
	bool isMoving;
};

void destroyEntity(TEntity *en);



#endif
