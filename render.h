#ifndef RENDER_H
#define RENDER_H

//	Lidar com a renderização de imagens

#define BTN_START 0
#define BTN_EXIT 1

struct TBackground{
	unsigned char *image;
	int x, y;
};

struct TUi{
	TBackground bg;
	TEntity btn[2];
};

struct TAnimation{
	unsigned char *frame1, *frame2, *frame3, *frame4, *frame5, *frame6;
	unsigned char *frameM1, *frameM2, *frameM3, *frameM4, *frameM5, *frameM6;
	//unsigned char *frames[5];
};

unsigned char* load_image(const char *locale, int width, int height, double scale = 1, int ini_width = 0, int ini_heigth = 0);
unsigned char* do_mask(unsigned char *image, int size);
unsigned char* print_area(int width, int height, int x = 0, int y = 0);
void *load_image_void(const char *locale, int width, int height, double scale, int ini_width, int ini_heigth);
void  delete_image(unsigned char *image);
void  drawEntity(TEntity en, int style = 0);
void  drawLine(TLine line_);
void  drawRect(TRect rect);
void  drawBG(TBackground bg);
TAnimation Animation(unsigned char *frame1, unsigned char *frame2, unsigned char *frame3, unsigned char *frame4, unsigned char *frame5);



#endif
