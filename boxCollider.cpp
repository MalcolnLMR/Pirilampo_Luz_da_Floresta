#include "mylibrary.h"


int getRectWidth(TRect obj){
	return (obj.x + obj.width);
}

int getRectHeight(TRect obj){
	return (obj.y + obj.height);
}


bool colliderRectRect(TRect obj1, TRect obj2, int orientation){
	int left1 = obj1.x, right1 = getRectWidth(obj1);
	int up1   = obj1.y, down1  = getRectHeight(obj1);
	int left2 = obj2.x, right2 = getRectWidth(obj2);
	int up2   = obj2.y, down2  = getRectHeight(obj2);
	
	switch (orientation){
		case 0:/*
			if ((left1 <= right2 && left1 >= left2) && ((up1 <= down2 && up1 >= up2) || (down1 >= up2 && down1 <= down2))) return true;
			if ((right1 >= left2 && right1 <= right2) && ((up1 <= down2 && up1 >= up2) || (down1 >= up2 && down1 <= down2))) return true;
			if ((up1 <= down2 && up1 >= up2) && ((left1 <= right2 && left1 >= left2) || (right1 >= left2 && right1 <= right2))) return true;
			if ((down1 >= up2 && down1 <= down2) && ((left1 <= right2 && left1 >= left2) || (right1 >= left2 && right1 <= right2))) return true;*/
			if ((left1 <= right2 && right1 >= left2) && ((up1 <= down2) && (down1 >= up2))) return true;
			return false;
			break;
		case 1:
			if ((left1 <= right2) && ((up1 <= down2) && (down1 >= up2))) return true;
			else return false;			
			break;
		case 2:
			if ((right1 >= left2) && ((up1 <= down2) && (down1 >= up2))) return true;	
			else return false;
			break;
		case 3:
			if ((up1 <= down2) && ((left1 <= right2) && (right1 >= left2))) return true;	
			else return false;
			break;
		case 4:
			if ((down1 >= up2) && ((left1 <= right2) && (right1 >= left2))) return true;	
			else return false;			
			break;
		default:
			return false;
	}
}

bool colliderEntityRect(TEntity* en, TRect rect, int orientation){
	int rectx2 = rect.x + rect.width, recty2 = rect.y + rect.height;
	switch (orientation){
		case 1: // ESQUERDA
			if ((en->x - en->spd <= rectx2 && en->x >= rect.x) && (en->y + en->size >= rect.y && en->y <= recty2)) return true;
			else return false;			
			break;
		case 2: // DIREITA
			if ((en->x + en->spd + en->size >= rect.x && en->x <= rectx2) && (en->y + en->size >= rect.y && en->y <= recty2)) return true;	
			else return false;
			break;
		case 3: // CIMA
			if ((en->y - en->spd <= recty2 && en->y >= rect.y) && (en->x + en->size >= rect.x && en->x <= rectx2)) return true;	
			else return false;
			break;
		case 4: // BAIXO
			if ((en->y + en->spd >= rect.y && en->y <= recty2) && (en->x + en->size >= rect.x && en->x <= rectx2)) return true;	
			else return false;			
			break;
		default:
			return false;
	}
}

bool colliderEntityLine(TEntity* en, TLine line, int orientation){
	
	switch (orientation){
		case 1: // ESQUERDA
			if ((en->x - en->spd <= line.x1) && ((en->y - en->size >= line.y1) && (en->y <= line.y2))) return true;
			else return false;			
			break;
		case 2:	// DIREITA		
			if ((en->x + en->spd + en->size >= line.x1) && ((en->y - en->size >= line.y1) && (en->y <= line.y2))) return true;
			else return false;
			break;
		case 3: // CIMA
//			printf("X: %d - (%d, %d)\n", en->x, line.x1, line.x2);
//			printf("Y: %d - (%d, %d)\n", en->y, line.y1, line.y2);
			if ((en->y - en->spd <= line.y1) && ((en->x + en->size >= line.x1) && (en->x <= line.x2))) return true;	
			else return false;
			break;
		case 4: // BAIXO
			if ((en->y + en->spd + en->size >= line.y1) && ((en->x + en->size >= line.x1) && (en->x <= line.x2))) return true;		
			else return false;			
			break;
		default:
			return false;
	}
}

//imgX <= mouse.x && mouse.x <= imgX+imgLado-1 && imgY <= mouse.y && mouse.y <= imgY+imgLado-1
bool colliderMouseRect(POINT mouse, TRect obj){
	if (obj.x <= mouse.x && mouse.x <= obj.width+obj.x && obj.y <= mouse.y && mouse.y <= obj.height+obj.y)
		return true;
	else return false;
}

void seekEntity(TRect* collider, TEntity *en, int offsetX, int offsetY){
	collider->x = en->x + offsetX;
	collider->y = en->y + offsetY;	
}

void syncEntityCollider(TEntity *en, int coffset){
	seekEntity(&en->collider, en);
	seekEntity(&en->cup, en, 0, -coffset);
	seekEntity(&en->cdown, en);
	seekEntity(&en->cleft, en, -coffset);
	seekEntity(&en->cright, en);	
}




