#include"mylibrary.h"

	//Iniciar as variaveis globais
//Variaveis gráficas
const int coffset = 8;   // Tamanho da projeção da colisão do jogador
void *bgTest;            // Tela de testes
bool isInChange = false; // Variavel de controle para travessia entre telas
int pg = 1;              // Controle do double buffering
int xmax, ymax;          // Valores máximos da tela
int spriteSize;          // Tamanho dos sprites

// ENTIDADES DO JOGO
TEntity player;                             // O Jogador
TEntity glassShard, magicalOrb, lowKey;     // Itens coletáveis
TEntity paje, orbe, mora, espelho, lampiao; // Objetos de cenário
TEntity taturana;                           // Inimigos

// Outros (Botões e caixas de diálogo)
TEntity btnPlay, btnExit;
TEntity dialogueBox1;
TEntity background_1;
TRect box, paredeEsq, paredeCima, paredeBaixo, paredeDir;
TRect goLeft, goRight, goUp, goDown;

	// Definindo os Estágios
int actualStage = 1;
TStage stages[6];

int gameloop = MENU;
	//Inventário
TInventory inventory = Inventory();	
const int itensLenght = 7;
TItem itens[itensLenght];
	//Interação com o jogador
POINT mouse;
HWND window;
int i;
bool gameover = false;

//Controle de input
int key;

void setup();
void finish();

//Game Loops
	// Menu
void menu_tick();
void menu_render();
	// Pause
void pause_tick();
void pause_render();
	// Carregamento
void load_tick();
void load_render();
	// Fim de jogo
void gameover_tick();
void gameover_render();
	// Jogo primário
void game_tick();
void game_render();
	// Terminar todas as inicializações do jogo
void exit_tick();


//Configurações inicias do jogo
void setup(){
	//Definir variaveis e criar tela
	initwindow(1000, 800, "Guardioes da Floresta");
	xmax = getmaxx();
	ymax = getmaxy();
	setvisualpage(pg);	
	
	/* 
		Loadingscreen
	*/
	
	setactivepage(pg);	
	if(pg == 1) pg = 2; else pg = 1;
	setvisualpage(pg);	
		
	//Carregar imagens
	//bgTest = load_image("assets/map_test2.bmp", 1000, 5000);
	background_1.sprite = load_image("assets/stage1.5.bmp", 1000, 800, 1);	
	player.sprite = load_image("assets/vagalume.bmp", 256, 256, 0.5);
	spriteSize = 128;
	paje.sprite = load_image("assets/paje.bmp", 1024, 1024);
	orbe.sprite = load_image("assets/orbe.bmp", 1024, 1024);
	mora.sprite = load_image("assets/mora.bmp", 1024, 1024);
	espelho.sprite = load_image("assets/espelho.bmp", 1024, 1024);
	lampiao.sprite = load_image("assets/lampiao.bmp", 1024, 1024);
	taturana.sprite = load_image("assets/taturana.bmp", 1024, 1024);
	
	//player.mask = load_image("assets/player_m.bmp", 128, 128, 0.5);
	
	// CRIANDO OS ESTÁGIOS
	stages[0] = setStage(Line(100, 0, 100, ymax),
	                     Line(xmax - 130, 0, xmax - 130, ymax), 
						 Line(0, 250, xmax, 250), 
						 Line(0, ymax, 650, ymax));
	stages[0].colliders[0] = Rect(420, 200, 60, 400);
	
	//Criação de retângulos de colisão
	paredeEsq = Rect(0, 0, 81, 750);
	paredeCima = Rect(0, 0, 750, 60);
	paredeBaixo = Rect(0, 680, 750, 70);
	paredeDir = Rect(649, 0, 81, 750);
	box = Rect(459, 221, 181, 42);	
	goLeft = Rect(0, 0, 50, 800);	
	goRight = Rect(950, 0, 50, 800);	
	goUp = Rect(0, 0, 950, 50);	
	goDown = Rect(0, 750, 1000, 50);	
	
		//Para o jogador:
	player.cup    = Rect(player.x, player.y - coffset, 64, 64);
	player.cdown  = Rect(player.x, player.y, 64, 64 + coffset);
	player.cright = Rect(player.x, player.y, 64 + coffset, 64);
	player.cleft  = Rect(player.x - coffset, player.y, 64, 64);		
	player.collider = Rect(player.x, player.y, 64, 64);	
	player.x = xmax/2; player.y = ymax/2; player.spd = 5;
	player.size = spriteSize;	
	
	//Criação de invetário e itens
	setcolor(RGB(15, 140, 140)); //Colorir sprite temporário do item
	setfillstyle(1, RGB(15, 140, 140));		
		// 	Definição dos itens

	TRect aux;
	for(i = 0; i <= itensLenght; i++){
		aux = Rect(200 + (i * 70), 686, 64, 64);
		itens[i] = Item(i, "item", aux);
			// TEMPORÁRIO - CRIAR SPRITE
		setfillstyle(1, RGB(15, 140, 140));	
		bar(0, 0, 64, 64);
		itens[i].sprite = print_area(64, 64);
			// SELECTED
		bar(0, 0, 64, 64);
		setfillstyle(1, RGB(140, 15, 140));	
		fillellipse(32, 32, 16, 16);
		itens[i].spriteselected = print_area(64, 64);
		
		inventory.itens[i] = itens[i];
	}
	// Criar Botões no jogo
	setfillstyle(1, RGB(140, 140, 140));	
	bar(0, 0, 128, 64);
	aux = Rect(xmax/2 - 64, ymax/2 - 35, 128, 64);
	btnPlay.collider = aux;
	btnPlay.sprite = print_area(128, 64);	
	btnPlay.x = xmax/2 - 64;
	btnPlay.y = ymax/2 - 35;	
	
	setfillstyle(1, RGB(200, 200, 200));	
	bar(0, 0, 128, 64);
	aux = Rect(xmax/2 - 64, ymax/2 + 35, 128, 64);
	btnExit.collider = aux;
	btnExit.sprite = print_area(128, 64);	
	btnExit.x = xmax/2 - 64;
	btnExit.y = ymax/2 + 35;
	
	// Balão de fala - TESTE	
	setfillstyle(1, RGB(200, 200, 200));	
	bar(0, 0, 600, 200);
	aux = Rect(50, 500, 600, 200);
	dialogueBox1.collider = aux;
	dialogueBox1.sprite = print_area(600, 200);
	dialogueBox1.x = 50;
	dialogueBox1.y = 500;
	dialogueBox1.show = false;
	
	// ITEM NA TELA
	setfillstyle(1, RGB(255,209,220));	
	bar(0, 0, 64, 64);
	aux = Rect(300, 300, 64, 64);
	glassShard.collider = aux;
	glassShard.sprite = print_area(64, 64);
	glassShard.x = 300;
	glassShard.y = 300;
	glassShard.show = true;
	
	// ITEM NA TELA
	setfillstyle(1, RGB(209,220,255));	
	bar(0, 0, 64, 64);
	aux = Rect(600, 300, 64, 64);
	magicalOrb.collider = aux;
	magicalOrb.sprite = print_area(64, 64);
	magicalOrb.x = 600;
	magicalOrb.y = 300;
	magicalOrb.show = true;
	
	// ITEM NA TELA
	setfillstyle(1, RGB(220,255,209));	
	bar(0, 0, 64, 64);
	aux = Rect(500, 500, 64, 64);
	lowKey.collider = aux;
	lowKey.sprite = print_area(64, 64);
	lowKey.x = 500;
	lowKey.y = 500;
	lowKey.show = true;
	
	// DEFINIR A LOCALIZAÇÃO DO BACKGROUND
	background_1.x = 0;
	background_1.y = 0;
	
}



void menu_tick(){
	// JOGAR - SAIR
	GetCursorPos(&mouse);
	ScreenToClient(window, &mouse);
	if (GetKeyState(VK_LBUTTON)&0x80) {		
		//Selecionar itens
		if (colliderMouseRect(mouse, btnPlay.collider)) gameloop = GAME;
		if (colliderMouseRect(mouse, btnExit.collider)) gameloop = EXIT;
	}
}

void menu_render(){
	if(pg == 1) pg = 2; else pg = 1;
	setvisualpage(pg);				
	cleardevice();
	// JOGAR - SAIR
	drawEntity(btnPlay, 1);
	drawEntity(btnExit, 1);
	setactivepage(pg);
}

void pause_tick(){
	// RETOMAR - REINICIAR - SAIR
		//LIdar com a entrada de dados do jogador
	if (kbhit()) key = getch();
	//GetKeyboardState(VK_W);
	if(key == ESC){
		gameloop = GAME;
	} 
}

void pause_render(){
	
}

void load_tick(){
	// CARREGAR O JOGO DO ZERO
	
	
}

void load_render(){
	// CARREGAR O JOGO DO ZERO
	
}

void gameover_tick(){
	// REINICIAR - SAIR
	
}

void gameover_render(){
	
}

void exit_tick(){
	// Liberar memória alocada pelos itens
	for(i = 0; i <= itensLenght; i++){
		free(itens[i].sprite);
		free(itens[i].spriteselected);
	}	
	gameover = true;
}

void game_render(){	
	if(pg == 1) pg = 2; else pg = 1;
	setvisualpage(pg);				
	cleardevice();
	

	
	//Desenhar Background
	drawEntity(background_1, 1);
	
	//Desenhar player	
	drawEntity(player, 1);
	
	//Desenhar itens no inventário
	for(i = 0; i <= inventory.lenght; i++){
		if(inventory.itens[i].show)	{
			if(inventory.itens[i].selected)
				putimage(inventory.itens[i].rect.x, inventory.itens[i].rect.y, inventory.itens[i].spriteselected, COPY_PUT);				
			else
				putimage(inventory.itens[i].rect.x, inventory.itens[i].rect.y, inventory.itens[i].sprite, COPY_PUT);
		}		
	}	
		
	if(dialogueBox1.show) drawEntity(dialogueBox1, 1);	
	if(glassShard.show)   drawEntity(glassShard, 1);	
	if(magicalOrb.show)   drawEntity(magicalOrb, 1);	
	if(lowKey.show)       drawEntity(lowKey, 1);
	
	/* DEBUG DE COLLIDERS */
	setlinestyle(0, 0, 3);
	setcolor(RGB(255,0,0));
	drawLine(stages[0].upLimit);
	drawLine(stages[0].leftLimit);
	drawLine(stages[0].rightLimit);
	drawLine(stages[0].downLimit);
	drawRect(stages[0].colliders[0]);
	/* FIM DO DEBUG DE COLLIDERS */
	
	//Atualizar display com tela já finalizada	
	
	setactivepage(pg); 		
}

void game_tick(){
	//Manter o retângulo de colisão no jogador
	syncEntityCollider(&player, coffset);
	syncEntityCollider(&dialogueBox1);
	syncEntityCollider(&glassShard);
	syncEntityCollider(&magicalOrb);
	syncEntityCollider(&lowKey);
	
	//Verificar colisões com paredes
	runStageCollider(1, &player, stages);	
	//if(colliderRectRect(player.cright, paredeDir)) player.right = false; 
	//if(colliderRectRect(player.cright, box))  player.right = false; else player.right = true;
	
	///if(colliderRectRect(player.cleft, paredeEsq)) player.left  = false; 
	//if(colliderRectRect(player.cleft, box))   player.left  = false; else player.left  = true;
	
	//if(colliderRectRect(player.cup, paredeCima, UP_)) player.up    = false; 
	//if(colliderRectRect(player.cup, box))     player.up    = false; else player.up    = true;
	
	//if(colliderRectRect(player.cdown, paredeBaixo, DOWN_)) player.down  = false; 
	//if(colliderRectRect(player.cdown, box))   player.down  = false; else player.down  = true;
	
	// Verificar caso o jogadro chegue perto da borda
	//if (player.y < ymax + spriteSize/2) isInChange = true;
	
	//LIdar com a entrada de dados do jogador
	player.isMoving = false;
	if(GetKeyState(VK_W)&0x80 && player.up){
		player.y -= player.spd;
		player.isMoving = true;		
	}
	if(GetKeyState(VK_S)&0x80 && player.down){
		player.y += player.spd;
		player.isMoving = true;	
	}
	if(GetKeyState(VK_A)&0x80 && player.left){
		player.x -= player.spd;
		player.isMoving = true;	
	}
	if(GetKeyState(VK_D)&0x80 && player.right){
		player.x += player.spd;
		player.isMoving = true;	
	}
	
	//Adicionar item ao inventário
	if (glassShard.show && colliderRectRect(player.collider, glassShard.collider)) {
		addItem(&inventory.itens[0]);
		destroyEntity(&glassShard);
	}
	if (key == 50) addItem(&inventory.itens[1]);
	
	if (magicalOrb.show && colliderRectRect(player.collider, magicalOrb.collider)) {
		addItem(&inventory.itens[2]);
		destroyEntity(&magicalOrb);
	}
	if (lowKey.show && colliderRectRect(player.collider, lowKey.collider)) {
		addItem(&inventory.itens[3]);
		destroyEntity(&lowKey);
	}
	
	if (key == 53) addItem(&inventory.itens[4]);
	if (key == 54) addItem(&inventory.itens[5]);
	
	if (key == KEY_PGUP) dialogueBox1.show = true;
	
	if (key == KEY_INSERT){
		system("pause");
	}
	
	
	// Comandos com o Mouse
	GetCursorPos(&mouse);
	ScreenToClient(window, &mouse);
	if (GetKeyState(VK_LBUTTON)&0x80) {	
	
		// Combinação de itens
		if (inventory.itens[3].selected && colliderMouseRect(mouse, inventory.itens[2].rect) ||
		    inventory.itens[2].selected && colliderMouseRect(mouse, inventory.itens[3].rect)){
		    	addItem(&inventory.itens[6]);
		    	delItem(&inventory.itens[2]);
		    	delItem(&inventory.itens[3]);
		}
		
		//Selecionar itens
		if (colliderMouseRect(mouse, inventory.itens[0].rect)) selectItem(&inventory.itens[0], &inventory);
		if (colliderMouseRect(mouse, inventory.itens[1].rect)) selectItem(&inventory.itens[1], &inventory);
		if (colliderMouseRect(mouse, inventory.itens[2].rect)) selectItem(&inventory.itens[2], &inventory);
		if (colliderMouseRect(mouse, inventory.itens[3].rect)) selectItem(&inventory.itens[3], &inventory);
		if (colliderMouseRect(mouse, inventory.itens[4].rect)) selectItem(&inventory.itens[4], &inventory);
		if (colliderMouseRect(mouse, inventory.itens[5].rect)) selectItem(&inventory.itens[5], &inventory);
		if (colliderMouseRect(mouse, inventory.itens[6].rect)) selectItem(&inventory.itens[6], &inventory);
	}
	
}

int main(){	
	unsigned long long now, lasttime;
	int count;
	lasttime = GetTickCount();
	setup();
	while(!gameover){
		now = GetTickCount();
		if(lasttime - now > 1000/60){
			lasttime = now;	
			switch (gameloop){
				case GAME:
					game_render();
					game_tick();
					break;
				case PAUSE:
					pause_render();
					pause_tick();
					break;
				case MENU:
					menu_render();
					menu_tick();
					break;
				case LOADGAME:
					load_render();
					load_tick();
					break;
				case GAMEOVER:
					gameover_render();
					gameover_tick();
					break;	
				case EXIT:
					exit_tick();
					break;									
			}			
			
		}		
	}	
	closegraph();
	return 0;
}

