#ifndef GEOMETRICOBJ_H
#define GEOMETRICOBJ_H

struct TRect{
	int x, y;
	int width, height;
};

struct TCircle{
	int x, y, r;
};

struct TLine{
	int x1, y1, x2, y2;
};

TRect Rect(int x, int y, int width, int height);
TLine Line(int x1, int y1, int x2, int y2);

#endif
