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
//TEntity glassShard, magicalOrb, lowKey;     // Itens coletáveis
TEntity paje, orbe, mora, espelho, lampiao; // Objetos de cenário
TEntity taturana;                           // Inimigos

// Outros (Botões e caixas de diálogo)
TEntity btnPlay, btnExit;
TEntity dialogueBox1;
TEntity background_1;
TRect box, paredeEsq, paredeCima, paredeBaixo, paredeDir;
TRect goLeft, goRight, goUp, goDown;
TUi menu;
TAnimation onScreenItens;
unsigned char* onScreenSprite, *onScreenMask;
int animationKey = 0;
bool debugMode = false;

	// Definindo os Estágios
int actualStage = 1;
int lastStage;
TStage stages[4];
int moveStageKey = 0;
int FPSCounter = 0;

int gameloop = MENU;
	//Inventário
TInventory inventory = Inventory();	
const int itensLenght = 7;
TItem itens[itensLenght];
TEntity item[itensLenght];
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
	setvisualpage(pg);
	
	/* 
		Loadingscreen
	*/
	
	setactivepage(pg);	
	if(pg == 1) pg = 2; else pg = 1;
	setvisualpage(pg);
	window = GetForegroundWindow();
	xmax = getmaxx();
	ymax = getmaxy();
		
	mciSendString("open OST.mp3 type MPEGVideo alias BGM", NULL, 0,0);
	//Carregar imagens
	//bgTest = load_image("assets/map_test2.bmp", 1000, 5000);
	menu.bg.image = load_image("assets/menu.bmp", 1000, 800);
	player.sprite = load_image("assets/entidades/VagalumeVoandoBaseBundaApagada0001.bmp", 256, 256, 0.25);
	player.mask = load_image("assets/entidades/VagalumeVoandoMascara0001.bmp", 256, 256, 0.25);
	player.size = 64;
	//player.mask = do_mask(player.sprite, 128);
	
	spriteSize = 64;
	paje.sprite = load_image("assets/entidades/Paje.bmp", 256, 256, 0.5);
	paje.sprite = load_image("assets/entidades/PajeMascara.bmp", 256, 256, 0.5);
	/*
	orbe.sprite = load_image("assets/entidades/paje.bmp", 256, 256, 0.5);
	orbe.mask = load_image("assets/entidades/paje.bmp", 256, 256, 0.5);
	*/
	/*
	mora.sprite = load_image("assets/entidades/paje.bmp", 256, 256, 0.5);
	mora.sprite = load_image("assets/entidades/paje.bmp", 256, 256, 0.5);
	*/
	espelho.sprite = load_image("assets/entidades/espelho.bmp", 256, 256, 0.5);
	espelho.sprite = load_image("assets/entidades/espelhoMascara.bmp", 256, 256, 0.5);
	lampiao.sprite = load_image("assets/lampiao.bmp", 1024, 1024);
	lampiao.sprite = load_image("assets/entidades/lampiao.bmp", 256, 256, 0.5);
	lampiao.sprite = load_image("assets/entidades/lampiaoMascara.bmp", 256, 256, 0.5);
	
	taturana.sprite = load_image("assets/entidades/Taturana0001.bmp", 256, 256, 0.5);
	taturana.sprite = load_image("assets/entidades/TaturanaMascara0001.bmp", 256, 256, 0.5);
	
	//player.mask = load_image("assets/player_m.bmp", 128, 128, 0.5);
	
	// CRIANDO OS ESTÁGIOS
	/* PRIMEIRO ESTÁGIO */
	stages[0] = setStage(Line(250, 0, 250, ymax),               //LeftLimit
	                     Line(xmax - 250, 0, xmax - 250, ymax), //RightLimit
						 Line(0, 70, xmax, 70),                 //UpLimit
						 Line(0, ymax, 0, ymax));               //DownLimit
	stages[0].colliders[0] = Rect(460, 10, 50, 280);
	stages[0].colliders[1] = Rect(250, 420, 350, 30);
	stages[0].colliders[2] = Rect(250, 450, 50, 400);
	stages[0].colliders[3] = Rect(xmax-300, 620, 100, 500);
	stages[0].colliders[4] = Rect(250, ymax-40, 250, 40);
	//stages[0].colliders[5] = Rect(xmax-300, ymax-40, 50, 40);
	stages[0].active = true;
	stages[0].background = load_image("assets/BG/Arvore1.bmp", 500, 400, 2);
	
	/* SEGUNDO ESTÁGIO */
	stages[1] = setStage(Line(240, 0, 240, ymax),               //LeftLimit
	                     Line(xmax - 260, 0, xmax - 260, ymax), //RightLimit
						 Line(0, 0, 450, 0),                    //UpLimit
						 Line(0, ymax, 0, ymax));               //DownLimit
	stages[1].colliders[0] = Rect(240, 0, 250, 150);
	stages[1].colliders[1] = Rect(xmax/2 - 30, 300, 300, 20);
	stages[1].colliders[2] = Rect(240, 500, 150, 25);
	stages[1].colliders[3] = Rect(xmax-350, ymax-60, 125, 60);
	stages[1].colliders[4] = Rect(240, ymax-60, 125, 60);
	stages[1].colliders[5] = Rect(xmax-350, 0, 100, 500);
	stages[1].background = load_image("assets/BG/Arvore2.bmp", 500, 400, 2);
	stages[1].bgy = ymax + 1;
	/* TERCEIRO ESTÁGIO */
	stages[2] = setStage(Line(100, 0, 100, ymax),               //LeftLimit
	                     Line(xmax - 130, 0, xmax - 130, ymax), //RightLimit
						 Line(0, 0, 650, 0),                    //UpLimit
						 Line(0, ymax, 650, ymax));             //DownLimit
	stages[2].colliders[0] = Rect(460, 10, 50, 280);
	stages[2].colliders[1] = Rect(250, 420, 350, 30);
	stages[2].colliders[2] = Rect(250, 450, 50, 400);
	stages[2].colliders[3] = Rect(xmax-300, 620, 100, 500);
	stages[2].colliders[4] = Rect(250, ymax-40, 250, 40);
	stages[2].background = load_image("assets/BG/Arvore3.bmp", 500, 400, 2);
	stages[2].bgy = ymax - 5;
	/* QUARTO ESTÁGIO */
	stages[3] = setStage(Line(100, 0, 100, ymax),               //LeftLimit
	                     Line(xmax - 130, 0, xmax - 130, ymax), //RightLimit
						 Line(0, 0, 650, 0),                    //UpLimit
						 Line(0, ymax, 650, ymax));             //DownLimit
	stages[3].colliders[0] = Rect(460, 10, 50, 280);
	stages[3].colliders[1] = Rect(250, 420, 350, 30);
	stages[3].colliders[2] = Rect(250, 450, 50, 400);
	stages[3].colliders[3] = Rect(xmax-300, 620, 100, 500);
	stages[3].colliders[4] = Rect(250, ymax-40, 250, 40);
	stages[3].background = load_image("assets/BG/Arvore4.bmp", 500, 400, 2);
	stages[3].bgy = ymax - 10;
	
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
	player.collider = Rect(player.x, player.y, player.size, player.size);	
	player.x = 300; player.y = 200; player.spd = 5;
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
//		setfillstyle(1, RGB(15, 140, 140));	
//		bar(0, 0, 64, 64);
		itens[i].sprite = 0;
			// SELECTED
		bar(0, 0, 64, 64);
//		setfillstyle(1, RGB(140, 15, 140));	
//		fillellipse(32, 32, 16, 16);
		itens[i].spriteselected = 0;
		
		inventory.itens[i] = itens[i];
	}
	// Lasca 
	inventory.itens[GLASS].sprite = load_image("assets/itens/lasca.bmp", 124, 124);	
	//itens[0].spriteselected = load_image("assets/itens/lasca.bmp", 124, 124, 0.5);
	//itens[0].spriteselected = 	itens[0].sprite;
	// Espatula 
	
	inventory.itens[1].sprite = load_image("assets/itens/espatula.bmp", 124, 124, 0.5);
	//itens[1].spriteselected = load_image("assets/itens/espatula.bmp", 124, 124, 0.5);
	// Orbe 
	inventory.itens[2].sprite = load_image("assets/itens/orbe.bmp", 124, 124, 0.5);
//	itens[2].spriteselected = load_image("assets/itens/orbe.bmp", 124, 124, 0.5);
	// Chave Descarregada 
	inventory.itens[3].sprite = load_image("assets/itens/chave.bmp", 124, 124, 0.5);
//	itens[3].spriteselected = load_image("assets/itens/chave.bmp", 124, 124, 0.5);
	// Flor 
	inventory.itens[4].sprite = load_image("assets/itens/flor.bmp", 124, 124, 0.5);
//	itens[4].spriteselected = load_image("assets/itens/flor.bmp", 124, 124, 0.5);
	// Alma do pajé 
	inventory.itens[5].sprite = load_image("assets/itens/paje.bmp", 124, 124, 0.5);
//	itens[5].spriteselected = load_image("assets/itens/paje.bmp", 124, 124, 0.5);
	// Chave Carregada 
	inventory.itens[6].sprite = load_image("assets/itens/chave.bmp", 124, 124, 0.5);
//	itens[6].spriteselected = load_image("assets/itens/chave.bmp", 124, 124, 0.5);
	
	// Criar Botões no jogo
	setfillstyle(1, RGB(140, 140, 140));	
	bar(0, 0, 164, 64);
	aux = Rect(xmax/2 - 64, ymax/2 - 35, 164, 64);
	menu.btn[BTN_START].collider = aux;
	menu.btn[BTN_START].sprite = print_area(164, 64);	
	menu.btn[BTN_START].x = xmax/2 - 50 - 32;
	menu.btn[BTN_START].y = ymax/2 - 30;	
	
	setfillstyle(1, RGB(200, 200, 200));	
	bar(0, 0, 128, 64);
	aux = Rect(xmax/2 - 64, ymax/2 + 35, 128, 64);
	menu.btn[BTN_EXIT].collider = aux;
	menu.btn[BTN_EXIT].sprite = print_area(128, 64);	
	menu.btn[BTN_EXIT].x = xmax/2 - 64;
	menu.btn[BTN_EXIT].y = ymax/2 + 45;
	
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
	onScreenMask   = load_image("assets/entidades/anim_3.bmp", 600, 600, 0.1);
	onScreenSprite = load_image("assets/entidades/anim_3_Mask.bmp", 600, 600, 0.1);
	for (i = 0; i < itensLenght; i++){
		item[i].sprite = onScreenSprite;
		item[i].mask = onScreenMask;
	}
	
	aux = Rect(300, 300, 64, 64);
	item[GLASS].collider = aux;	
	item[GLASS].x = 290;
	item[GLASS].y = 400;
	item[GLASS].show = true;
	
	aux = Rect(600, 300, 64, 64);
	item[ORB].collider = aux;
	item[ORB].x = 600;
	item[ORB].y = 300;
	item[ORB].show = false;
	
	aux = Rect(500, 500, 64, 64);	
	item[KEYOFF].collider = aux;
	item[KEYOFF].x = 500;
	item[KEYOFF].y = 500;
	item[KEYOFF].show = false;	
		
    mciSendString("seek BGM to start", NULL, 0, 0);
    mciSendString("play BGM repeat", NULL, 0, 0);
	cleardevice();
}



void menu_tick(){
	// JOGAR - SAIR
	GetCursorPos(&mouse);
	ScreenToClient(window, &mouse);
	if (GetKeyState(VK_LBUTTON)&0x80) {	
		window = GetForegroundWindow();
		if (colliderMouseRect(mouse, menu.btn[BTN_START].collider)) gameloop = GAME;
		if (colliderMouseRect(mouse, menu.btn[BTN_EXIT].collider)) gameloop = EXIT;
	}
}

void menu_render(){
	if(pg == 1) pg = 2; else pg = 1;
	setvisualpage(pg);				
	cleardevice();
	drawBG(menu.bg);
	
	
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
	//drawEntity(background_1, 1);
	drawStage(stages[0]);
	drawStage(stages[1]);
	drawStage(stages[2]);
	drawStage(stages[3]);
	
	//Desenhar player	
	drawEntity(player, 0);
	
	//Desenhar itens no inventário
	for(i = 0; i <= inventory.lenght; i++){
		if(inventory.itens[i].show)	{			
//			if(inventory.itens[i].selected)
//				putimage(inventory.itens[i].rect.x, inventory.itens[i].rect.y, inventory.itens[i].spriteselected, COPY_PUT);				
//			else
			putimage(inventory.itens[i].rect.x, inventory.itens[i].rect.y, inventory.itens[i].sprite, COPY_PUT);				
		}		
	}	
	
	for (i = 0; i < itensLenght; i++){
			if(item[i].show)   putimage(item[i].x, item[i].y, item[i].sprite, AND_PUT);
			if(item[i].show)   putimage(item[i].x, item[i].y, item[i].mask,  OR_PUT);
	}
	//putimage(500, 500, onScreenItens.frame1,  COPY_PUT);
	
	if (FPSCounter >= 30){
		animationKey++;
		FPSCounter = 0;
		if(animationKey >= 6){
			animationKey = 0;
		}
	}
	
	
	//Atualizar display com tela já finalizada
	
	
	if(debugMode){
		/* DEBUG DE COLLIDERS */
		setlinestyle(0, 0, 3);
		setcolor(RGB(255,0,0));
		drawLine(stages[actualStage-1].upLimit);
		drawLine(stages[actualStage-1].leftLimit);
		drawLine(stages[actualStage-1].rightLimit);
		drawLine(stages[actualStage-1].downLimit);
		if (stages[actualStage-1].colliders[0].x != -1) drawRect(stages[actualStage-1].colliders[0]);
		if (stages[actualStage-1].colliders[1].x != -1) drawRect(stages[actualStage-1].colliders[1]);
		if (stages[actualStage-1].colliders[2].x != -1) drawRect(stages[actualStage-1].colliders[2]);
		if (stages[actualStage-1].colliders[3].x != -1) drawRect(stages[actualStage-1].colliders[3]);
		if (stages[actualStage-1].colliders[4].x != -1) drawRect(stages[actualStage-1].colliders[4]);
		if (stages[actualStage-1].colliders[5].x != -1) drawRect(stages[actualStage-1].colliders[5]);
		drawRect(player.collider);
		/* FIM DO DEBUG DE COLLIDERS */			
	}
	
	setactivepage(pg); 		
}

void game_tick(){
	//Manter o retângulo de colisão no jogador
	syncEntityCollider(&player, coffset);
	syncEntityCollider(&dialogueBox1);
	syncEntityCollider(&item[0]);
	syncEntityCollider(&item[2]);
	syncEntityCollider(&item[3]);
	
	// Verificar se está em troca de estágio
	if(isInChange){
		if (lastStage < actualStage){
			if(moveStageKey <= -ymax){
				isInChange = false;
				stages[lastStage-1].active = false;
				moveStageKey = 0;
			} else if (moveStageKey == 0){
				player.y -= player.spd*2;
				moveStageKey -= 5;
			} else {
				moveStageKey -= 5;
			}
			/* MOVIMENTAR OBJETOS PARA CIMA */
			stages[lastStage-1].bgy += -5;
			stages[actualStage-1].bgy += -5;
			player.y += -5;
		} else {
			if(moveStageKey >= ymax){
				isInChange = false;
				stages[lastStage-1].active = false;	
				moveStageKey = 0;
			} else if (moveStageKey == 0){
				player.y += player.spd*2;	
				moveStageKey += 5;
			} else {
				moveStageKey += 5;
			}
			/* MOVIMENTAR OBJETOS PARA BAIXO */
			stages[lastStage-1].bgy += 5;
			stages[actualStage-1].bgy += 5;
			player.y += 5;			
		}
		
	} else{	
		// Verificar caso o jogador tente passar de cenário
		if(player.y + player.size/2 >= ymax + player.spd*2  && !isInChange){
			isInChange = true;
			lastStage = actualStage;
			stages[actualStage].active = true;
			moveStageKey = 0;
			actualStage += 1;
		} else if(player.y <= -player.size/2 - player.spd*2 && !isInChange){
			isInChange = true;
			lastStage = actualStage;
			stages[actualStage-2].active = true;
			moveStageKey = 0;
			actualStage -= 1;
		}
		
		// Verificar colisões com objetos do estágio	
		runStageCollider(actualStage, &player, stages);
		
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
		if(GetKeyState(VK_HOME)&0x80){
			debugMode = false;
		}
		if(GetKeyState(VK_END)&0x80){
			debugMode = true;
		}	
	}
	
	//Adicionar item ao inventário
	if (item[GLASS].show && colliderRectRect(player.collider, item[GLASS].collider)) {
		addItem(&inventory.itens[0]);
		destroyEntity(&item[GLASS]);
	}
	if (key == 50) addItem(&inventory.itens[1]);
	
	if (item[ORB].show && colliderRectRect(player.collider, item[ORB].collider)) {
		addItem(&inventory.itens[2]);
		destroyEntity(&item[ORB]);
	}
	if (item[KEYOFF].show && colliderRectRect(player.collider, item[KEYOFF].collider)) {
		addItem(&inventory.itens[3]);
		destroyEntity(&item[KEYOFF]);
	}
	
	if (key == 53) addItem(&inventory.itens[4]);
	if (key == 54) addItem(&inventory.itens[5]);
	
	
	// Comandos com o Mouse
	GetCursorPos(&mouse);
	ScreenToClient(window, &mouse);
	if (GetKeyState(VK_LBUTTON)&0x80) {	
	
		// Combinação de itens
		if (inventory.itens[KEYOFF].selected && colliderMouseRect(mouse, inventory.itens[ORB].rect) ||
		    inventory.itens[ORB].selected && colliderMouseRect(mouse, inventory.itens[KEYOFF].rect)){
		    	addItem(&inventory.itens[KEYON]);
		    	delItem(&inventory.itens[ORB]);
		    	delItem(&inventory.itens[KEYOFF]);
		}
		
		//Selecionar itens
		if (colliderMouseRect(mouse, inventory.itens[GLASS].rect)) selectItem(&inventory.itens[GLASS], &inventory);
		if (colliderMouseRect(mouse, inventory.itens[SPATULA].rect)) selectItem(&inventory.itens[SPATULA], &inventory);
		if (colliderMouseRect(mouse, inventory.itens[ORB].rect)) selectItem(&inventory.itens[ORB], &inventory);
		if (colliderMouseRect(mouse, inventory.itens[KEYOFF].rect)) selectItem(&inventory.itens[KEYOFF], &inventory);
		if (colliderMouseRect(mouse, inventory.itens[FLOWER].rect)) selectItem(&inventory.itens[FLOWER], &inventory);
		if (colliderMouseRect(mouse, inventory.itens[PAJE].rect)) selectItem(&inventory.itens[PAJE], &inventory);
		if (colliderMouseRect(mouse, inventory.itens[KEYON].rect)) selectItem(&inventory.itens[KEYON], &inventory);
	}
	FPSCounter++;	
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

