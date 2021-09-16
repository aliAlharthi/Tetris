#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <stdio.h>

#define VIDEO_SEGMENT	0xA000
#define VIDEO_INT	    0x10

#define MODE_13H	    0x13
#define MODE_TEXT	    0x03

#define SCREEN_WIDTH	320
#define SCREEN_HEIGHT	200

#define PALETTE_INDEX       0x03c8
#define PALETTE_DATA        0x03c9

#define sgn(x) ((x<0)?-1:((x>0)?1:0))

typedef unsigned char	byte;
typedef unsigned short  word;
typedef unsigned int    dword;
typedef long            fixed16_16;

typedef struct BMP 
{
    word width;
    word height;
    byte palette[256 * 3];
    byte *data;
} BMP;

typedef struct TileSheet
{
    int tileHeight;
    int tileWidth;
    int height;
    int width;
    byte *data;
} TileSheet;

void setVideoMode(int mode);
void putPixel(int x, int y, byte color);
void line(int x1, int y1, int x2, int y2, byte color);
void rect(int left,int top, int right, int bottom, byte color);
void rectFill(int left,int top, int right, int bottom, byte color);
/*void circle(int x,int y, int radius, byte color);*/
void drawTile(int x, int y, TileSheet *ts, int index);
void drawText(int x, int y, TileSheet *ts, int index);
void fskip(FILE *fp, int num_bytes);
void loadBMP(char *file, BMP *b);
void drawBitmap(BMP *b, int x, int y);
void setPalette(byte *palette);
byte setTileSprites(BMP *b, TileSheet *ts);
void drawTileSprites(TileSheet *ts, int x, int y, int indexX, int indexY);

#endif
