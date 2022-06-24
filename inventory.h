#ifndef INVENTORY_H
#define INVENTORY_H

/*
 -- Situações do inventário --
	• Combinar itens    	
	    • Pegar localização do mouse para selecionar item
	    • Arrastar item para outro, combinando-os
	• Selecionar itens (Assim como mostrar a seleção)
	• Mostrar itens
	• Mostrar UI
*/

struct TItem{
	int id;
	TRect rect;
	const char *name;
	int *combinations;	
	unsigned char *sprite, *spriteselected;
	bool selected;
	bool show;
};

struct TInventory{
	int lenght;
	TItem itens[7];
};

TItem Item(int id, const char *name, TRect rect);
TInventory Inventory();
void addItem(TItem *item);
void delItem(TItem *item);
void selectItem(TItem *item, TInventory *inv);
void useItem(TItem *item);


#endif
