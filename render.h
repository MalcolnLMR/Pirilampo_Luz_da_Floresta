#ifndef RENDER_H
#define RENDER_H

//	Lidar com a renderização de imagens

#define BTN_START 0
#define BTN_EXIT 1

struct TBackground{
	void* image;
	int x, y;
};

struct TUi{
	TBackground bg;
	TEntity btn[2];
};

void* load_image(const char *locale, int width, int height, double scale = 1, int ini_width = 0, int ini_heigth = 0);
void  delete_image(void *image);
void* print_area(int width, int height, int x = 0, int y = 0);
void  drawEntity(TEntity en, int style = 0);
void  drawLine(TLine line_);
void  drawRect(TRect rect);
void  drawBG(TBackground bg);



#endif
