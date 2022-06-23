#include "mylibrary.h"

unsigned char * load_image(const char *locale, int width, int height, double scale, int ini_width, int ini_heigth){
	//Pegar imagens
	if(scale <= 1){
		unsigned char *image;
		int aux = imagesize(ini_width, ini_heigth, width-1, height-1);
		image = (unsigned char*)malloc(aux);
		readimagefile(locale, ini_width*scale, ini_heigth*scale, (width-1)*scale, (height-1)*scale);
		getimage(ini_width*scale, ini_heigth*scale, (width-1)*scale, (height-1)*scale, image);
		cleardevice();
		return image;
	} else {
		unsigned char *image;
		int aux = imagesize(ini_width, ini_heigth, (width-1)*scale, (height-1)*scale);
		image = (unsigned char*)malloc(aux);
		readimagefile(locale, ini_width, ini_heigth, (width-1)*scale, (height-1)*scale);
		getimage(ini_width, ini_heigth, (width-1)*scale, (height-1)*scale, image);
		cleardevice();
		return image;		
	}
}

unsigned char* do_mask(unsigned char *image, int size){
	unsigned char B, G, R;
	int aux = imagesize(0, 0, size-1, size-1);
	unsigned char *mask;
	
	B = image[24];
	G = image[25];
	R = image[26];
	for(int i = 24; i < aux; i += 4) {
		if (image[i]==B and image[i+1]==G and image[i+2]==R) {
			image[i] = 0;
			image[i+1] = 0;
			image[i+2] = 0;
			mask[i] = 255;
			mask[i+1] = 255;
			mask[i+2] = 255;
		}
		else {
			mask[i] = 0;
			mask[i+1] = 0;
			mask[i+2] = 0;
		}
	}	
	return mask;
}

void delete_image(void *image){
	free(image);
}

unsigned char *print_area(int width, int height, int x, int y){
	unsigned char* image;
	int aux = imagesize(x, y, width-1, height-1);
	image = (unsigned char*)malloc(aux);
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

void  drawBG(TBackground bg){
	putimage(bg.x, bg.y, bg.image, COPY_PUT);	
}














