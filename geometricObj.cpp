#include "mylibrary.h"

TRect Rect(int x, int y, int width, int height){
	TRect obj;
	obj.x = x;
	obj.y = y;
	obj.width = width;
	obj.height = height;
	return obj;	
} 

TLine Line(int x1, int y1, int x2, int y2){	
	TLine obj;
	obj.x1 = x1;
	obj.y1 = y1;
	obj.x2 = x2;
	obj.y2 = y2;
	return obj;	
}
