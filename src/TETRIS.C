#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>

#include "input.h"
#include "SPRITE.H"

#include "GRAPHIC.H"


byte titleScreen[7 * 18] = {BOARD_TOP_LEFT, 0x01, 0x01, 0x01, 0x01,   0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, BOARD_TOP_RIGHT,
                            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
                            0x01, 0x00, TITLE_LOGO_1, TITLE_LOGO_2, TITLE_LOGO_3, TITLE_LOGO_4, TITLE_LOGO_5, TITLE_LOGO_6, TITLE_LOGO_7, TITLE_LOGO_8, TITLE_LOGO_9, TITLE_LOGO_10, TITLE_LOGO_11, TITLE_LOGO_12, TITLE_LOGO_13, TITLE_LOGO_14, 0x00,0x01,
                            0x01, 0x00, TITLE_LOGO_15, TITLE_LOGO_16, TITLE_LOGO_17, TITLE_LOGO_18, TITLE_LOGO_19, TITLE_LOGO_20, TITLE_LOGO_21, TITLE_LOGO_22, TITLE_LOGO_23, TITLE_LOGO_24, TITLE_LOGO_25, TITLE_LOGO_26, TITLE_LOGO_27, TITLE_LOGO_28, 0x00,0x01,
                            0x01, 0x00, TITLE_LOGO_29, TITLE_LOGO_30, TITLE_LOGO_31, TITLE_LOGO_32, TITLE_LOGO_33, TITLE_LOGO_34, TITLE_LOGO_35, TITLE_LOGO_36, TITLE_LOGO_37, TITLE_LOGO_38, TITLE_LOGO_39, TITLE_LOGO_40, TITLE_LOGO_41, TITLE_LOGO_42, 0x00,0x01,
                            0x01, 0x00, TITLE_LOGO_43, TITLE_LOGO_44, TITLE_LOGO_45, TITLE_LOGO_46, TITLE_LOGO_47, TITLE_LOGO_48, TITLE_LOGO_49, TITLE_LOGO_50, TITLE_LOGO_51, TITLE_LOGO_52, TITLE_LOGO_53, TITLE_LOGO_54, TITLE_LOGO_55, TITLE_LOGO_56, 0x00,0x01,
                            BOARD_BOTTOM_LEFT, 0x01, 0x01, 0x01, 0x01,0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, BOARD_BOTTOM_RIGHT};

byte board[BOARD_SIZE] =   {BOARD_TOP_LEFT, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, BOARD_TOP_RIGHT,
                            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
                            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
                            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
                            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
                            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
                            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
                            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
                            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
                            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
                            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
                            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
                            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
                            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
                            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
                            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,                                
                            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
                            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
                            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
                            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
                            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
                            BOARD_BOTTOM_LEFT, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, BOARD_BOTTOM_RIGHT,};

byte infoHold[INFO_BOX_HEIGHT * INFO_BOX_WIDTH] =   {BOARD_TOP_LEFT, BOARD_HOLD_1, BOARD_HOLD_2, BOARD_TOP_RIGHT,
                                                     0x01, 0x00, 0x00, 0x01,
                                                     0x01, 0x00, 0x00, 0x01,
                                                     0x01, 0x00, 0x00, 0x01,
                                                     0x01, 0x00, 0x00, 0x01,
                                                     BOARD_BOTTOM_LEFT, 0x01, 0x01, BOARD_BOTTOM_RIGHT};

byte infoNext[INFO_BOX_HEIGHT * INFO_BOX_WIDTH] =   {BOARD_TOP_LEFT, BOARD_NEXT_1, BOARD_NEXT_2, BOARD_TOP_RIGHT,
                                                     0x01, 0x00, 0x00, 0x01,
                                                     0x01, 0x00, 0x00, 0x01,
                                                     0x01, 0x00, 0x00, 0x01,
                                                     0x01, 0x00, 0x00, 0x01,
                                                     BOARD_BOTTOM_LEFT, 0x01, 0x01, BOARD_BOTTOM_RIGHT}; 

byte infoStats[STATS_HEIGHT * STATS_WIDTH] =        {BOARD_TOP_LEFT, BOARD_STATS_1, BOARD_STATS_2, BOARD_STATS_3, BOARD_STATS_4, BOARD_STATS_5, BOARD_TOP_RIGHT,
                                                     0x01, STATS_TETROMINO_I, 0x00, 0x00, 0x00, 0x00, 0x01,
                                                     0x01, STATS_TETROMINO_S, 0x00, 0x00, 0x00, 0x00, 0x01,
                                                     0x01, STATS_TETROMINO_Z, 0x00, 0x00, 0x00, 0x00, 0x01,
                                                     0x01, STATS_TETROMINO_L, 0x00, 0x00, 0x00, 0x00, 0x01,
                                                     0x01, STATS_TETROMINO_J, 0x00, 0x00, 0x00, 0x00, 0x01,
                                                     0x01, STATS_TETROMINO_T, 0x00, 0x00, 0x00, 0x00, 0x01,
                                                     0x01, STATS_TETROMINO_O, 0x00, 0x00, 0x00, 0x00, 0x01,
                                                     BOARD_BOTTOM_LEFT, 0x01, 0x01, 0x01, 0x01, 0x01, BOARD_BOTTOM_RIGHT};

byte infoScore[SCORE_HEIGHT * SCORE_WIDTH] =        {BOARD_TOP_LEFT, 0x01, BOARD_SCORE_1, BOARD_SCORE_2, BOARD_SCORE_3, 0x01, BOARD_TOP_RIGHT,
                                                     0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
                                                     0x01, 0x01, SCORE_LINES_1, SCORE_LINES_2, SCORE_LINES_3, 0x01, 0x01,
                                                     0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
                                                     0x01, 0x01, SCORE_LEVEL_1, SCORE_LEVEL_2, SCORE_LEVEL_3, 0x01, 0x01,
                                                     0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
                                                     BOARD_BOTTOM_LEFT, 0x01, 0x01, 0x01, 0x01, 0x01, BOARD_BOTTOM_RIGHT};

byte dbTetromino[7][TETROMINO_SIZE] =      {{0x00, 0x00, TETROMINO_I, 0x00,    0x00, 0x00, TETROMINO_I, 0x00,     0x00, 0x00, TETROMINO_I, 0x00,     0x00, 0x00, TETROMINO_I, 0x00},                                    
                                            {0x00, TETROMINO_S, 0x00, 0x00,    0x00, TETROMINO_S, TETROMINO_S, 0x00,     0x00, 0x00, TETROMINO_S, 0x00,     0x00, 0x00, 0x00, 0x00},                                    
                                            {0x00, 0x00, TETROMINO_Z, 0x00,    0x00, TETROMINO_Z, TETROMINO_Z, 0x00,     0x00, TETROMINO_Z, 0x00, 0x00,     0x00, 0x00, 0x00, 0x00},                                    
                                            {0x00, TETROMINO_L, 0x00, 0x00,    0x00, TETROMINO_L, 0x00, 0x00,     0x00, TETROMINO_L, TETROMINO_L, 0x00,     0x00, 0x00, 0x00, 0x00},                                    
                                            {0x00, 0x00, TETROMINO_J, 0x00,    0x00, 0x00, TETROMINO_J, 0x00,     0x00, TETROMINO_J, TETROMINO_J, 0x00,     0x00, 0x00, 0x00, 0x00},                                    
                                            {0x00, 0x00, TETROMINO_T, 0x00,    0x00, TETROMINO_T, TETROMINO_T, 0x00,     0x00, 0x00, TETROMINO_T, 0x00,     0x00, 0x00, 0x00, 0x00},
                                            {0x00, TETROMINO_O, TETROMINO_O, 0x00,    0x00, TETROMINO_O, TETROMINO_O, 0x00,     0x00, 0x00, 0x00, 0x00,     0x00, 0x00, 0x00, 0x00}};

typedef struct Player
{
    int inPlay;
    int px, py;
    byte tetromino[TETROMINO_SIZE];
} Player;

typedef struct Info
{
    int score;
    int level;
    int line;
    int hold;
    int next;
} Info;

typedef struct Menu
{
    int cursorPosition;
} Menu;

typedef struct Game
{
    int level;
    int gameover;
    int stats[8];

} Game;


clock_t startTime, timer;
double tick = 100;
double cpuTimeUsed;




void drawBoard(TileSheet ts);
void updateBoard(Player *player, TileSheet ts);
void setTetromino(Player *player, Info *info, TileSheet ts, int type, Game *game);
int checkPath(Player player, int direction);
int checkRotationPath(byte tetromino[TETROMINO_SIZE], int x, int y);
void setPlayer(Player *player, byte *board, TileSheet ts, Info *info, int type, Game *game);
void rotateTetromino(Player *player, int direction);
void control(Player *player, int direction, TileSheet ts, Info *info, Game *game);
void checkLine(byte *board, TileSheet ts, Info *info);
void drawInfoBox(TileSheet ts, int offsetX, byte *box);
void drawStatsBox(TileSheet ts, Game game);
void drawScoreBox(TileSheet ts, Info info);
void updateInfoBox(TileSheet ts, Info info, int offsetX);
void setHold(TileSheet ts, Info *info, Player *player, Game *game);
int ticker();
void print(TileSheet ts, char *str, int x, int y, int letterSpacing);
void printInfoLine(TileSheet ts, Info info);
void printInfoScore(TileSheet ts, Info info);
void printInfoLevel(TileSheet ts, Info info);
void setMenu(Menu *menu);
void drawTitleScreen(TileSheet ts);
void drawCursor(TileSheet ts, Menu menu);
void moveCursor();
void clearScreen();
void setNewGame(Game *game, Info *info, Player *player);
void menuControl(Menu *menu, TileSheet ts, int direction, Game *game, Info *info, Player *player);
void addToBoard(Player *player, byte *board, TileSheet ts, Info *info, Game *game);
void printInfoStats(TileSheet ts, Game game, int index);
void speedup();

void speedup()
{
    tick -= 10;
}

void setMenu(Menu *menu)
{    
    menu->cursorPosition = 0;
}

void setNewGame(Game *game, Info *info, Player *player)
{
    int i, j;
    game->gameover = 0;
    game->level = 1;
    
    for(i = 0; i < 7; i++)
    {
        game->stats[i] = 0;
    }

    info->score = 0;
    info->level = 1;
    info->next = 8;
    info->hold = 8;
    info->line = 0;

    for(i = 1; i < BOARD_HEIGHT -1; i++)
    {
        for(j = 1; j < BOARD_WIDTH -1; j++)
        {
            board[i * BOARD_WIDTH + j] = 0x00;
        }
    }
    
}

void clearScreen()
{
    rectFill(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
}


void print(TileSheet ts, char *str, int x, int y, int letterSpacing)
{
    int i;
    for(i = 0; i < strlen(str); i++)
    {
        switch(str[i])
        {
            case '0':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_0);
                break;

            case '1':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_1);
                break;
            
            case '2':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_2);
                break;

            case '3':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_3);
                break;

            case '4':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_4);
                break;

            case '5':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_5);
                break;

            case '6':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_6);
                break;
            
            case '7':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_7);
                break;

            case '8':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_8);
                break;
            
            case '9':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_9);
                break;

            case 'A':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_A);
                break;

            case 'B':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_B);
                break;

            case 'C':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_C);
                break;

            case 'D':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_D);
                break;

            case 'E':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_E);
                break;

            case 'F':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_F);
                break;
            
            case 'G':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_G);
                break;

            case 'H':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_H);
                break;

            case 'I':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_I);
                break;

            case 'J':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_J);
                break;

            case 'K':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_K);
                break;

            case 'L':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_L);
                break;

            case 'M':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_M);
                break;
            
            case 'N':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_N);
                break;

            case 'O':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_O);
                break;

            case 'P':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_P);
                break;

            case 'Q':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_Q);
                break;

            case 'R':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_R);
                break;

            case 'S':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_S);
                break;

            case 'T':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_T);
                break;
            
            case 'U':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_U);
                break;

            case 'V':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_V);
                break;

            case 'W':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_W);
                break;

            case 'X':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_X);
                break;

            case 'Y':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_Y);
                break;
            
            case 'Z':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_Z);
                break;

            case 'a':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_a);
                break;
            
            case 'b':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_b);
                break;

            case 'c':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_c);
                break;

            case 'd':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_d);
                break;

            case 'e':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_e);
                break;

            case 'f':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_f);
                break;

            case 'g':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_g);
                break;

            case 'h':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_h);
                break;
            
            case 'i':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_i);
                break;

            case 'j':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_j);
                break;

            case 'k':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_k);
                break;

            case 'l':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_l);
                break;

            case 'm':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_m);
                break;

            case 'n':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_n);
                break;

            case 'o':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_o);
                break;
            
            case 'p':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_p);
                break;

            case 'q':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_q);
                break;

            case 'r':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_r);
                break;

            case 's':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_s);
                break;

            case 't':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_t);
                break;
            
            case 'u':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_u);
                break;

            case 'v':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_v);
                break;
            
            case 'w':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_w);
                break;

            case 'x':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_x);
                break;

            case 'y':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_y);
                break;

            case 'z':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_z);
                break;

            case ',':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_COMMA);
                break;
            
            case ':':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_COLON);
                break;

            case '!':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_EXCLAMATION);
                break;
            
            case '.':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_DOT);
                break;

            case '=':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_EQUALS);
                break;

            case '(':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_OPEN_BRACKET);
                break;

            case ')':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_CLOSE_BRACKET);
                break;

            case '/':
                drawText(((x + i) * (ts.tileWidth - letterSpacing)), (y) * ts.tileHeight, &ts, FONT_SLASH);
                break;
        }
    }
}

void printInfoLine(TileSheet ts, Info info)
{
    int i;
    char str[3];

    sprintf(str, "%03d", info.line);

    for(i = 0; i < 5; i++)
    {
    drawTile((SCORE_OFFSET_X + 1 + i) * ts.tileWidth, (SCORE_OFFSET_Y + 3) * ts.tileHeight, &ts, BOARD_BACKGROUND);
    }
    print(ts, str,SCORE_OFFSET_X + 2, SCORE_OFFSET_Y + 3, 0);
}

void printInfoScore(TileSheet ts, Info info)
{
    int i;
    char str[9];

    sprintf(str, "%07d", info.score);

    for(i = 0; i < 5; i++)
    {
    drawTile((SCORE_OFFSET_X + 1 + i) * ts.tileWidth, (SCORE_OFFSET_Y + 1) * ts.tileHeight, &ts, BOARD_BACKGROUND);
    }
    print(ts, str,SCORE_OFFSET_X + 18, SCORE_OFFSET_Y + 1, 3);
}

void printInfoLevel(TileSheet ts, Info info)
{
    int i;
    char str[5];

    sprintf(str, "%02d", info.level);

    for(i = 0; i < 5; i++)
    {
    drawTile((SCORE_OFFSET_X + 1 + i) * ts.tileWidth, (SCORE_OFFSET_Y + 5) * ts.tileHeight, &ts, BOARD_BACKGROUND);
    }
    print(ts, str,SCORE_OFFSET_X - 1, SCORE_OFFSET_Y + 5, -1);
}

void printInfoStats(TileSheet ts, Game game, int index)
{
    int i;
    char str[5];

    sprintf(str, "%03d", game.stats[index]);

    for(i = 0; i < 3; i++)
    {
    drawTile((STATS_OFFSET_X + 3 + i) * ts.tileWidth, (STATS_OFFSET_Y + 1 + index) * ts.tileHeight, &ts, BOARD_BACKGROUND);
    }
    print(ts, str,STATS_OFFSET_X + 3, STATS_OFFSET_Y + 1 + index, 0);
}

void drawTitleScreen(TileSheet ts)
{
    int i, j;

    for(i = 0; i < 7; i++)
    {
        for(j = 0; j < 18; j++)
        {
            drawTile((j + 11) * ts.tileWidth, (i + 5) * ts.tileHeight, &ts, titleScreen[(i * 18) + j]);
        }
    }

    print(ts, "Start Game", 21, 13, 2);
    print(ts, "Quit", 24, 14, 2);

    print(ts, "by  Ali Alharthi", 18 , 21, 2);
    print(ts, "(c) 2021 Boker Productions",13 , 23, 2);
    
}

void drawCursor(TileSheet ts, Menu menu)
{

    rectFill(14 * ts.tileWidth, 13 * ts.tileHeight, 15 * ts.tileWidth, 15 * ts.tileHeight, 0);       

    drawTile(14 * ts.tileWidth, (13 + menu.cursorPosition) * ts.tileHeight, &ts, CURSOR);
}

void drawBoard(TileSheet ts)
{
    int i, j;

    for(i = 0; i < BOARD_HEIGHT; i++)
    {
        for(j = 0; j < BOARD_WIDTH; j++)
        {
            drawTile((BOARD_OFFSET_X + j) * ts.tileWidth, (BOARD_OFFSET_Y + i) * ts.tileHeight, &ts, board[(i * BOARD_WIDTH) + j]);
        }
    }
}

void drawInfoBox(TileSheet ts, int offsetX, byte *box)
{
    int i, j;
    
    for(i = 0; i < INFO_BOX_HEIGHT; i++)
    {
        for(j = 0; j < INFO_BOX_WIDTH; j++)
        {
            drawTile((offsetX + j) * ts.tileWidth, (INFO_BOX_OFFSET_Y + i) * ts.tileHeight, &ts, box[(i * INFO_BOX_WIDTH) + j]);
        }
    }
}

void drawStatsBox(TileSheet ts, Game game)
{
    int i, j;
    
    for(i = 0; i < STATS_HEIGHT; i++)
    {
        for(j = 0; j < STATS_WIDTH; j++)
        {
            
            drawTile((STATS_OFFSET_X + j) * ts.tileWidth, (STATS_OFFSET_Y + i) * ts.tileHeight, &ts, infoStats[(i * STATS_WIDTH) + j]);
        }
    }
    for(i = 0; i < 7; i++)
    {
        printInfoStats(ts, game, i);
    }
}

void drawScoreBox(TileSheet ts, Info info)
{
    int i, j;
    
    for(i = 0; i < SCORE_HEIGHT; i++)
    {
        for(j = 0; j < SCORE_WIDTH; j++)
        {
            drawTile((SCORE_OFFSET_X + j) * ts.tileWidth, (SCORE_OFFSET_Y + i) * ts.tileHeight, &ts, infoScore[(i * SCORE_WIDTH) + j]);
        }
    }
    printInfoScore(ts, info);
    printInfoLine(ts, info);
    printInfoLevel(ts, info);
}

void updateInfoBox(TileSheet ts, Info info, int offsetX)
{
    int i, j;

    for(i = 1; i < 5; i++)
    {
        for(j = 1; j < 3; j++)
        {
            if(offsetX == INFO_NEXT_OFFSET_X)
            {
                drawTile((INFO_NEXT_OFFSET_X + j) * ts.tileWidth, (INFO_BOX_OFFSET_Y + i) * ts.tileHeight, &ts, dbTetromino[info.next][((i - 1) * TETROMINO_WIDTH) + j]);
            }
            else
            {
                drawTile((INFO_HOLD_OFFSET_X + j) * ts.tileWidth, (INFO_BOX_OFFSET_Y + i) * ts.tileHeight, &ts, dbTetromino[info.hold][((i - 1) * TETROMINO_WIDTH) + j]);
            }
        }
    }
}

void setHold(TileSheet ts, Info *info, Player *player, Game *game)
{
    if(info->hold != 8)
    {
        int temp = info->hold;
        info->hold = player->inPlay;
        player->inPlay = temp;
        setPlayer(player, board, ts, info, 1, game);
    }
    else
    {
        info->hold = player->inPlay;
        setPlayer(player, board, ts, info, 0, game);
    }


    
    updateInfoBox(ts, *info, INFO_HOLD_OFFSET_X);
    drawBoard(ts);
    
    

}

void updateBoard(Player *player, TileSheet ts)
{
    int i, j;
    for(i = -2; i < TETROMINO_WIDTH + 1; i++)
    {
        for(j = -1; j < TETROMINO_WIDTH + 1; j++)
        {
            if(i > -1 && j > -1 && i < TETROMINO_WIDTH && j < TETROMINO_WIDTH && 
                player->tetromino[(i * TETROMINO_WIDTH) + j] > 0x05)
            {
                drawTile((BOARD_OFFSET_X + player->px + j) * ts.tileWidth, (BOARD_OFFSET_Y + player->py + i) * ts.tileHeight, &ts, player->tetromino[(i * TETROMINO_WIDTH) + j]);
            }
            else if((player->px + j) > -1 && ((player->py + i) > -1) && (player->px + j) < BOARD_WIDTH && (player->py + i) < BOARD_HEIGHT)
            {
                drawTile((BOARD_OFFSET_X + player->px + j) * ts.tileWidth, (BOARD_OFFSET_Y + player->py + i) * ts.tileHeight, &ts, board[((player->py + i) * BOARD_WIDTH) + (player->px + j)]);
            }
        }
    }
}

void setTetromino(Player *player, Info *info, TileSheet ts, int type, Game *game)
{
    int i;
    if(type == 0)
    {
        if(info->next == 8)
        {
            info->next = rand() % 7;
        }

        for(i = 0; i < TETROMINO_SIZE; i++)
        {
            player->tetromino[i] = dbTetromino[info->next][i];
        }

        player->inPlay = info->next;
        
        info->next = rand() % 7;
        
        game->stats[player->inPlay]++;
        printInfoStats(ts, *game, player->inPlay);

        updateInfoBox(ts, *info, INFO_NEXT_OFFSET_X);
        if(!checkPath(*player, 0))
        {
            game->gameover = 1;
        }
    }
    else
    {
        for(i = 0; i < TETROMINO_SIZE; i++)
        {
            player->tetromino[i] = dbTetromino[player->inPlay][i];
        }
    }

}

int checkPath(Player player, int direction)
{
    int i, j;

    switch(direction)
    {
        case DOWN:
            player.py++;
            break;

        case LEFT:
            player.px--;
            break;

        case RIGHT:
            player.px++;
            break;
    }

    for(i = 0; i < TETROMINO_WIDTH; i++)
    {
        for(j = 0; j < TETROMINO_WIDTH; j++)
        {
            if(player.tetromino[(i * TETROMINO_WIDTH) + j] > 0 && board[((i + player.py) * BOARD_WIDTH) + j + player.px])
            {    
                return 0;
            }
        }
    }
    return 1;
}

int checkRotationPath(byte tetromino[TETROMINO_SIZE], int x, int y)
{
    int i, j;

    for(i = 0; i < TETROMINO_WIDTH; i++)
    {
        for(j = 0; j < TETROMINO_WIDTH; j++)
        {
            if(tetromino[(i * TETROMINO_WIDTH) + j] > 0 && board[((i + y) * BOARD_WIDTH) + j + x])
            {    
                return 0;
            }
        }
    }
    return 1;
}

void setPlayer(Player *player, byte *board, TileSheet ts, Info *info, int type, Game *game)
{
    int i, j;

    player->px = 3;
    player->py = 1;

    setTetromino(player, info, ts, type, game);
    
    checkLine(board, ts, info);
}

void addToBoard(Player *player, byte *board, TileSheet ts, Info *info, Game *game)
{
    int i, j;

    for(i = 0; i < TETROMINO_WIDTH; i++)
    {
        for(j = 0; j < TETROMINO_WIDTH; j++)
        {
            if(player->tetromino[(i * TETROMINO_WIDTH) + j] > 0)
            {
                *(board + ((player->py + i) * BOARD_WIDTH) + (player->px + j)) = player->tetromino[(i * TETROMINO_WIDTH) + j];
            }
        }
    }
    setPlayer(player, board, ts, info, 0, game);
    
}

void rotateTetromino(Player *player, int direction)
{
    int i, j;
    unsigned char temp[TETROMINO_SIZE];
    switch(direction)
    {
        case RIGHT:

            for(i = 0; i < TETROMINO_WIDTH; i++)
            {
                for(j = 0; j < TETROMINO_WIDTH; j++)
                {
                    temp[(i * TETROMINO_WIDTH) + j] = player->tetromino[12 + i - (j * 4)];
                }
            }
            break;

        case LEFT:
            for(i = 0; i < TETROMINO_WIDTH; i++)
            {
                for(j = 0; j < TETROMINO_WIDTH; j++)
                {
                    temp[(i * TETROMINO_WIDTH) + j] = player->tetromino[3 - i + (j * 4)];
                }
            }
            break;

    }

    if(checkRotationPath(temp, player->px, player->py))
    {
        for(i = 0; i < TETROMINO_SIZE; i++)
        {
            player->tetromino[i] = temp[i];
        }
        
        /* sound effect here */
    }
    
}

void menuControl(Menu *menu, TileSheet ts, int direction, Game *game, Info *info, Player *player)
{
    switch(direction)
    {
        case UP:
            if(menu->cursorPosition > 0)
            {
                menu->cursorPosition--;
            }
            drawCursor(ts, *menu);
            break;
        case DOWN:
            if(menu->cursorPosition < 1)
            {
                menu->cursorPosition++;
            }
            drawCursor(ts, *menu);
            break;
        case ENTER_KEY:
            if(menu->cursorPosition == 0)
            {
                setNewGame(game, info, player);
            }
            else if( menu->cursorPosition == 1)
            {
                setVideoMode(MODE_TEXT);
                exit(0);
            }
    }
}

void pauseGame()
{
    int pause = 1;

    while(pause == 1)
    {
        if(kbhit())
        {
            if(getch() == ENTER_KEY)
                pause = 0;
        }
    }
}

void control(Player *player, int direction, TileSheet ts, Info *info, Game *game)
{
    int i, j;

    switch(direction)
    {
        case UP:
            
            break;

        case DOWN:

            startTime = clock();
            if(checkPath(*player, DOWN))
            {
                player->py++;
            }
            else
            {
                updateBoard(player, ts);
                addToBoard(player, board, ts, info, game);
            }
            break;

        case LEFT:
            if(checkPath(*player, LEFT))
            {
                /* sound effect here */
                player->px--;
            }
            break;

        case RIGHT:
            if(checkPath(*player, RIGHT))
            {
                /* sound effect here */

                player->px++;
            }
            break;

        case ENTER_KEY:
            print(ts, "PAUSE", BOARD_OFFSET_X + 6, BOARD_OFFSET_Y + 10, 1);
            pauseGame();
            drawBoard(ts);
            break;
        case Z_KEY:
            rotateTetromino(player, LEFT);
            break;
        
        case X_KEY:
            rotateTetromino(player, RIGHT);
            break;

        case C_KEY:
            setHold(ts, info, player, game);
            break;

        case SPACE_KEY:
            while(checkPath(*player, DOWN))
            {
                player->py++;
            }

            /* sound effect here*/

            drawBoard(ts);
            updateBoard(player, ts);
            addToBoard(player, board, ts, info, game);
            break;
    }
}

void checkLine(byte *board, TileSheet ts, Info *info)
{
    int i, j, k, lineCounter = 0;
    byte temp[BOARD_WIDTH - 2];

    for(i = 1 ; i < BOARD_HEIGHT - 1; i++)
    {
        int counter = 0;
        for(j = 1; j < BOARD_WIDTH - 1; j++)
        {
            if(board[(i * BOARD_WIDTH) + j] > 0)
            {
                counter++;
            }
            
        }

        if(counter == BOARD_WIDTH - 2)
        {
            
            for(j = 1; j < BOARD_WIDTH - 1; j++)
            {
                board[(i * BOARD_WIDTH) + j] = 0;
            }
            for(k = i - 1; k >= 1; k--)
            {
                for(j = 1; j < BOARD_WIDTH - 1; j++)
                {
                    temp[j - 1] = board[(k * BOARD_WIDTH) + j];
                    board[((k + 1) * BOARD_WIDTH) + j] = temp[j - 1];
                }
            }
            info->line++;
            lineCounter++;
            printInfoLine(ts, *info);
            drawBoard(ts);
            if(info->line / info->level == 20)
            {
                info->level ++;
                printInfoLevel(ts, *info);
                speedup();
            }
        }
    }

    switch(lineCounter)
    {
        case 1:
            info->score += 40;
            printInfoScore(ts, *info);
            break;
        case 2:
            info->score += 100;
            printInfoScore(ts, *info);
            break;
        case 3:
            info->score += 300;
            printInfoScore(ts, *info);
            break;
        case 4:
            info->score += 1200;
            printInfoScore(ts, *info);
            break;
    }
    if(lineCounter > 3)
    {

    /* sound for 4 lines*/

    }
    else if(lineCounter > 0)
    {
    /* sound for line */
    }
    
}

int ticker()
{
    if(tick - ((clock() - startTime)/.1) <= 0)
    {
        return 1;
    }

    return 0;
}

void printDosMessage()
{
    printf("\n*********************************\n");
    printf("* Welcome To Tetris version 0.1 *\n");
    printf("*********************************\n\n");
    printf("Developed by ALI\n\n");
    printf("Game controls:\n");
    printf("Direction = Arrow Keys\n");
    printf("Rotate\t  = z, x\n");
    printf("Hold\t  = c\n");
    printf("Quit\t  = Enter\n\n");
    printf("Press any key to continue....");
    getch();
}

int main(void)
{
    int i, j;
    Menu menu;
    Game game;
    Player player;
    BMP b;
    TileSheet ts;
    Info info;

    game.gameover = 1;

    srand(time(0));
    printDosMessage();

    setVideoMode(MODE_13H);
    loadBMP("tiles.bmp", &b);


    
    ts.tileHeight = 8;
    ts.tileWidth = 8;
    ts.height = b.height;
    ts.width = b.width;
    
    setTileSprites(&b, &ts);
    setPalette(b.palette);
    
    while(1)
    {
        menu.cursorPosition = 0;
        clearScreen();
        drawTitleScreen(ts);
        drawCursor(ts, menu);

        while(game.gameover == 1)
        {
        if(kbhit())
            {
                menuControl(&menu, ts, getch(), &game, &info, &player);
            }
        }
        clearScreen();
        
        
        
        drawBoard(ts);
        drawInfoBox(ts, INFO_HOLD_OFFSET_X, infoHold);
        drawInfoBox(ts, INFO_NEXT_OFFSET_X, infoNext);
        drawStatsBox(ts, game);
        drawScoreBox(ts, info);
        setPlayer(&player, board, ts, &info, 0, &game);
        startTime = clock();
        while(game.gameover == 0)
        {
            if(kbhit())
            {
                control(&player, getch(), ts, &info, &game);
            }

            if(ticker())
            {
                control(&player, DOWN, ts, &info, &game);
            }
        
            updateBoard(&player, ts);   
        }
    }
    getch();
    return 0;
}