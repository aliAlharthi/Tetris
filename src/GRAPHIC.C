#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include "graphic.h"

char far *videoSegmentPtr = MK_FP(VIDEO_SEGMENT, 0x0000);
fixed16_16 SIN_ACOS[1024];

void setVideoMode(int mode)
{
  _AH = 0x000;
  _AL = mode;
  geninterrupt(VIDEO_INT);
}

void putPixel(int x, int y, byte color)
{
  videoSegmentPtr[(y << 8) + (y << 6) + x] = color;
}

void line (int x1, int y1, int x2, int y2, byte color)
{
  int i,dx,dy,sdx,sdy,dxabs,dyabs,x,y,px,py;

  dx=x2-x1;      
  dy=y2-y1;      
  dxabs=abs(dx);
  dyabs=abs(dy);
  sdx=sgn(dx);
  sdy=sgn(dy);
  x=dyabs>>1;
  y=dxabs>>1;
  px=x1;
  py=y1;

  videoSegmentPtr[(py<<8)+(py<<6)+px]=color;

  if (dxabs>=dyabs)
  {
    for(i=0;i<dxabs;i++)
    {
      y+=dyabs;
      if (y>=dxabs)
      {
        y-=dxabs;
        py+=sdy;
      }
      px+=sdx;
      putPixel(px,py,color);
    }
  }
  else 
  {
    for(i=0;i<dyabs;i++)
    {
      x+=dxabs;
      if (x>=dyabs)
      {
        x-=dyabs;
        px+=sdx;
      }
      py+=sdy;
      putPixel(px,py,color);
    }
  }
}

void rect(int left,int top, int right, int bottom, byte color)
{
  word top_offset,bottom_offset,i,temp;

  if (top>bottom)
  {
    temp=top;
    top=bottom;
    bottom=temp;
  }
  if (left>right)
  {
    temp=left;
    left=right;
    right=temp;
  }

  top_offset=(top<<8)+(top<<6);
  bottom_offset=(bottom<<8)+(bottom<<6);

  for(i=left;i<=right;i++)
  {
    videoSegmentPtr[top_offset+i]=color;
    videoSegmentPtr[bottom_offset+i]=color;
  }
  for(i=top_offset;i<=bottom_offset;i+=SCREEN_WIDTH)
  {
    videoSegmentPtr[left+i]=color;
    videoSegmentPtr[right+i]=color;
  }
}

void rectFill(int x1,int y1, int x2, int y2, byte color)
{
  char far *ptr;
    int x_incr, x, y;

    ptr = videoSegmentPtr + (y1 << 8) + (y1 << 6) + x1;
    x_incr = SCREEN_WIDTH - (x2 - x1) - 1;

    for (y = y1; y <= y2; y++) {
        for (x = x1; x <= x2; x++)
            *(ptr++) = color;
        ptr += x_incr;
    }
}

/*void circle(int x,int y, int radius, byte color)
{
  fixed16_16 n=0,invradius=(1/(float)radius)*0x10000L;
  int dx=0,dy=radius-1;
  word dxoffset,dyoffset,offset = (y<<8)+(y<<6)+x;

  while (dx<=dy)
  {
    dxoffset = (dx<<8) + (dx<<6);
    dyoffset = (dy<<8) + (dy<<6);
    videoSegmentPtr[offset+dy-dxoffset] = color;  
    videoSegmentPtr[offset+dx-dyoffset] = color;  
    videoSegmentPtr[offset-dx-dyoffset] = color;  
    videoSegmentPtr[offset-dy-dxoffset] = color;  
    videoSegmentPtr[offset-dy+dxoffset] = color;  
    videoSegmentPtr[offset-dx+dyoffset] = color;  
    videoSegmentPtr[offset+dx+dyoffset] = color;  
    videoSegmentPtr[offset+dy+dxoffset] = color;  
    dx++;
    n+=invradius;
    dy = (int)((radius * SIN_ACOS[(int)(n>>6)]) >> 16);
  }
}*/

void fskip(FILE *fp, int num_bytes)
{
   int i;
   for (i=0; i<num_bytes; i++)
      fgetc(fp);
}

void loadBMP(char *file, BMP *b)
{
  FILE *ptrFile;
  long index;
  word numColors;
  int x;

  if((ptrFile = fopen(file, "rb")) == 0)
  {
    setVideoMode(MODE_TEXT);
    printf("Error oppening file %s.\n", file);
    exit(1);
  }

  if(fgetc(ptrFile) != 'B' || fgetc(ptrFile) != 'M')
  {
    fclose(ptrFile);
    setVideoMode(MODE_TEXT);
    printf("%s is not a bitmap file.\n", file);
    exit(1);
  }

  fskip(ptrFile, 16);
  fread(&b->width, sizeof(word), 1, ptrFile);
  fskip(ptrFile, 2);
  fread(&b->height, sizeof(word), 1, ptrFile);
  fskip(ptrFile, 22);
  fread(&numColors, sizeof(word), 1, ptrFile);
  fskip(ptrFile, 6);

  if(numColors == 0) { numColors = 256; }

  if((b->data = (byte *) malloc((word)(b->width * b->height))) == 0)
  {
    fclose(ptrFile);
    setVideoMode(MODE_TEXT);
    printf("Error allocating memory for file %s.\n", file);
    exit(1);
  }

  for(index=0;index<numColors;index++)
  {
    b->palette[(int)(index*3+2)] = fgetc(ptrFile) >> 2;
    b->palette[(int)(index*3+1)] = fgetc(ptrFile) >> 2;
    b->palette[(int)(index*3+0)] = fgetc(ptrFile) >> 2;
    x=fgetc(ptrFile);
  }

  for(index = (b->height - 1) * b->width; index >= 0; index -= b->width)
  {
    for(x = 0; x < b->width; x++)
    {
      b->data[(word)index+x] = (byte)fgetc(ptrFile);
    }
  }

  fclose(ptrFile);
}

void drawBitmap(BMP *b, int x, int y)
{
  int i, j;

  for(i = 0; i < b->height; i++)
  {
    for(j = 0; j < b->width; j++)
    {
      putPixel(x + j, y + i, b->data[(i * b->width) + j]);
    }
  }
}

void setPalette(byte *palette)
{
  int i;

  outp(PALETTE_INDEX,0);              

  for(i=0;i<256*3;i++)
    outp(PALETTE_DATA,palette[i]);
}

byte setTileSprites(BMP *b, TileSheet *ts)
{
  int i, j;
  for(i = 0; i < b->height; i++)
  {
    for( j = 0; j < b->width; j++)
    {
      ts->data[(i * ts->width) + j] = b->data[(i * b->width) + j];

    }
  }
}

void drawTile(int x, int y, TileSheet *ts, int index)
{
  int i, j;
  for(i = 0; i < ts->tileHeight; i++)
  {
    for(j = 0; j < ts->tileWidth; j++)
    {
        videoSegmentPtr[((y + i) << 8) + ((y + i) << 6) + x + j] 
                        = ts->data[((i) * ts->width) + (j) + index * 8];   
    }
  }
}

/*void drawTile(int x, int y, TileSheet *ts, int indexX, int indexY)
{
  int i;

  word screen_offset = (y << 8) + ( y << 6) + x;
  
  for( i = 0; i < ts->tileHeight; i++)
  {
    videoSegmentPtr[screen_offset] = ts->data[(i + (indexY * ts->tileHeight) + indexY + 1) 
                        * ts->width + ((indexX * ts->tileWidth) + indexX + 1)];
  }
}*/

void drawText(int x, int y, TileSheet *ts, int index)
{
  int i, j;
  for(i = 1; i < ts->tileHeight - 1; i++)
  {
    for(j = 2; j < ts->tileWidth; j++)
    {
      if(ts->data[((i) * ts->width) + (j) + index * 8])
      {
         videoSegmentPtr[((y + i) << 8) + ((y + i) << 6) + x + j] 
                        = ts->data[((i) * ts->width) + (j) + (index * 8)];   
      }
    }
  }
}