#include "mylibrary.h"

void* load_image(const char *locale, int width, int height, double scale, int ini_width, int ini_heigth){
	//Pegar imagens
	if(scale <= 1){
		void *image;
		int aux = imagesize(ini_width, ini_heigth, width-1, height-1);
		image = malloc(aux);
		readimagefile(locale, ini_width*scale, ini_heigth*scale, (width-1)*scale, (height-1)*scale);
		getimage(ini_width*scale, ini_heigth*scale, (width-1)*scale, (height-1)*scale, image);
		cleardevice();
		return image;
	} else {
		void *image;
		int aux = imagesize(ini_width, ini_heigth, (width-1)*scale, (height-1)*scale);
		image = malloc(aux);
		readimagefile(locale, ini_width, ini_heigth, (width-1)*scale, (height-1)*scale);
		getimage(ini_width, ini_heigth, (width-1)*scale, (height-1)*scale, image);
		cleardevice();
		return image;		
	}
}

void delete_image(void *image){
	free(image);
}

void *print_area(int width, int height, int x, int y){
	void *image;
	int aux = imagesize(x, y, width-1, height-1);
	image = malloc(aux);
	getimage(x, y, width-1, height-1, image);
	cleardevice();
	return image;
}

void drawEntity(TEntity en, int style){
	switch (style){
		case 0:
			putimage(en.x, en.y, en.mask, AND_PUT);
			putimage(en.x, en.y, en.sprite, OR_PUT);
			break;
		case 1:
			putimage(en.x, en.y, en.sprite, COPY_PUT);
			break;
	}
}

void  drawLine(TLine line_){
	line(line_.x1, line_.y1, line_.x2, line_.y2);
}

void  drawRect(TRect rect){
	rectangle(rect.x, rect.y, rect.x + rect.width, rect.y + rect.height);
}














