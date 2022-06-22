#ifndef MYLIBRARY_H		
#define MYLIBRARY_H

//		Gerenciamento de todas as bibliotecas usadas

//	Bibliotecas do C
#include<graphics.h>      // BGI - interface gr�fica
#include<stdio.h>         // Lidar com entrada e sa�da de dados
#include<stdlib.h>        // Biblioteca padr�o de C
#include<time.h>          // Biblioteca para tempo

//	Bibliotecas gen�ricas para lidar com jogos
#include "geometricObj.h" // Defini��o de objetos geom�tricos
#include "entity.h"       // Defini��o e fun��es das entidades do jogo
#include "render.h"       // Fun��es para rederizar objetos na tela
#include "boxCollider.h"  // Fun��es para lidar com colis�es entre objetos
#include "input.h"        // Lidar com a entrada de dados do jogador

//	Bibliotecas de mec�nicas do jogo
#include "inventory.h"    // Cria��o de itens e invent�rio
#include "gameStages.h"   // Localiza��o de colis�es de cada mapa


#endif

