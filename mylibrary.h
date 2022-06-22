#ifndef MYLIBRARY_H		
#define MYLIBRARY_H

//		Gerenciamento de todas as bibliotecas usadas

//	Bibliotecas do C
#include<graphics.h>      // BGI - interface gráfica
#include<stdio.h>         // Lidar com entrada e saída de dados
#include<stdlib.h>        // Biblioteca padrão de C
#include<time.h>          // Biblioteca para tempo

//	Bibliotecas genéricas para lidar com jogos
#include "geometricObj.h" // Definição de objetos geométricos
#include "entity.h"       // Definição e funções das entidades do jogo
#include "render.h"       // Funções para rederizar objetos na tela
#include "boxCollider.h"  // Funções para lidar com colisões entre objetos
#include "input.h"        // Lidar com a entrada de dados do jogador

//	Bibliotecas de mecânicas do jogo
#include "inventory.h"    // Criação de itens e inventário
#include "gameStages.h"   // Localização de colisões de cada mapa


#endif

