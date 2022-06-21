#ifndef RENDER_H
#define RENDER_H

//	Lidar com a renderização de imagens

void* load_image(const char *locale, int width, int height, double scale = 1, int ini_width = 0, int ini_heigth = 0);
void  delete_image(void *image);
void* print_area(int width, int height, int x = 0, int y = 0);
void  drawEntity(TEntity en, int style = 0);



#endif
