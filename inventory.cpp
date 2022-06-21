#include "mylibrary.h"



//Método para construir um Item
TItem Item(int id, const char *name, TRect rect){
	TItem item;
	item.id = id;
	item.name = name;
	item.show = false;
	item.selected = false;
	item.rect = rect;
	return item;
}

//Método para construir um inventário
TInventory Inventory(){
	TInventory inv;
	inv.lenght = 7;
	//inv.itens = (TItem*)malloc(sizeof(TItem) * inv.lenght);
	return inv;
}

void addItem(TItem *item){
	item->show = true;
}

void delItem(TItem *item){
	item->show = false;
}

void selectItem(TItem *item, TInventory *inv){
	if (item->show){
		for (int i = 0; i < inv->lenght; i++){
			inv->itens[i].selected = false;
		}
		item->selected = true;
	}
}

void useItem(TItem *item){
	
}
