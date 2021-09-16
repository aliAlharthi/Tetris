#ifndef SPRITE_H
#define SPRITE_H

#include "GRAPHIC.H"


#define BOARD_WIDTH     12
#define BOARD_HEIGHT    22
#define BOARD_SIZE      (BOARD_WIDTH * BOARD_HEIGHT)
#define BOARD_OFFSET_X  14
#define BOARD_OFFSET_Y  2

#define TETROMINO_WIDTH 4
#define TETROMINO_SIZE  16


#define INFO_BOX_OFFSET_Y   3
#define INFO_BOX_WIDTH      4
#define INFO_BOX_HEIGHT     6

#define INFO_HOLD_OFFSET_X  8
#define INFO_NEXT_OFFSET_X  28

#define SCORE_WIDTH    7
#define SCORE_HEIGHT   7
#define SCORE_OFFSET_X 28
#define SCORE_OFFSET_Y 10   

#define STATS_WIDTH     7
#define STATS_HEIGHT    9
#define STATS_OFFSET_X  5
#define STATS_OFFSET_Y  10


/*Tile Info                                  */

#define BOARD_BACKGROUND    0x00
#define BOARD_BORDER        0x01
#define BOARD_TOP_LEFT      0x02
#define BOARD_TOP_RIGHT     0x03
#define BOARD_BOTTOM_LEFT   0x04
#define BOARD_BOTTOM_RIGHT  0x05
#define BOARD_SCORE_1       0x06
#define BOARD_SCORE_2       0x07
#define BOARD_SCORE_3       0x08
#define SCORE_LINES_1       0x09
#define SCORE_LINES_2       0x0A
#define SCORE_LINES_3       0x0B
#define SCORE_LEVEL_1       0x0C
#define SCORE_LEVEL_2       0x0D
#define SCORE_LEVEL_3       0x0E
#define BOARD_HOLD_1        0x0F
#define BOARD_HOLD_2        0x10
#define BOARD_NEXT_1        0x11
#define BOARD_NEXT_2        0x12

#define BOARD_STATS_1       0x13
#define BOARD_STATS_2       0x14
#define BOARD_STATS_3       0x15
#define BOARD_STATS_4       0x16
#define BOARD_STATS_5       0x17
#define STATS_TETROMINO_Z   0x18
#define STATS_TETROMINO_O   0x19
#define STATS_TETROMINO_S   0x1A
#define STATS_TETROMINO_L   0x1B
#define STATS_TETROMINO_T   0x1C
#define STATS_TETROMINO_J   0x1D
#define STATS_TETROMINO_I   0x1E

#define TETROMINO_Z         0x1F
#define TETROMINO_O         0x20
#define TETROMINO_S         0x21
#define TETROMINO_L         0x22
#define TETROMINO_T         0x23
#define TETROMINO_J         0x24
#define TETROMINO_I         0x25

#define CURSOR              0x26

#define TITLE_LOGO_1        0x27
#define TITLE_LOGO_2        0x28
#define TITLE_LOGO_3        0x29
#define TITLE_LOGO_4        0x2A
#define TITLE_LOGO_5        0x2B
#define TITLE_LOGO_6        0x2C
#define TITLE_LOGO_7        0x2D
#define TITLE_LOGO_8        0x2E
#define TITLE_LOGO_9        0x2F
#define TITLE_LOGO_10       0x30
#define TITLE_LOGO_11       0x31
#define TITLE_LOGO_12       0x32
#define TITLE_LOGO_13       0x33
#define TITLE_LOGO_14       0x34
#define TITLE_LOGO_15       0x35
#define TITLE_LOGO_16       0x36
#define TITLE_LOGO_17       0x37
#define TITLE_LOGO_18       0x38
#define TITLE_LOGO_19       0x39
#define TITLE_LOGO_20       0x3A
#define TITLE_LOGO_21       0x3B
#define TITLE_LOGO_22       0x3C
#define TITLE_LOGO_23       0x3D
#define TITLE_LOGO_24       0x3E
#define TITLE_LOGO_25       0x3F
#define TITLE_LOGO_26       0x40
#define TITLE_LOGO_27       0x41
#define TITLE_LOGO_28       0x42
#define TITLE_LOGO_29       0x43
#define TITLE_LOGO_30       0x44
#define TITLE_LOGO_31       0x45
#define TITLE_LOGO_32       0x46
#define TITLE_LOGO_33       0x47
#define TITLE_LOGO_34       0x48
#define TITLE_LOGO_35       0x49
#define TITLE_LOGO_36       0x4A
#define TITLE_LOGO_37       0x4B
#define TITLE_LOGO_38       0x4C
#define TITLE_LOGO_39       0x4D
#define TITLE_LOGO_40       0x4E
#define TITLE_LOGO_41       0x4F
#define TITLE_LOGO_42       0x50
#define TITLE_LOGO_43       0x51
#define TITLE_LOGO_44       0x52
#define TITLE_LOGO_45       0x53
#define TITLE_LOGO_46       0x54
#define TITLE_LOGO_47       0x55
#define TITLE_LOGO_48       0x56
#define TITLE_LOGO_49       0x57
#define TITLE_LOGO_50       0x58
#define TITLE_LOGO_51       0x59
#define TITLE_LOGO_52       0x5A
#define TITLE_LOGO_53       0x5B
#define TITLE_LOGO_54       0x5C
#define TITLE_LOGO_55       0x5D
#define TITLE_LOGO_56       0x5E

#define FONT_0              0x5F
#define FONT_1              0x60
#define FONT_2              0x61
#define FONT_3              0x62
#define FONT_4              0x63
#define FONT_5              0x64
#define FONT_6              0x65
#define FONT_7              0x66
#define FONT_8              0x67
#define FONT_9              0x68
#define FONT_A              0x69
#define FONT_B              0x6A
#define FONT_C              0x6B
#define FONT_D              0x6C
#define FONT_E              0x6D
#define FONT_F              0x6E
#define FONT_G              0x6F
#define FONT_H              0x70
#define FONT_I              0x71
#define FONT_J              0x72
#define FONT_K              0x73
#define FONT_L              0x74
#define FONT_M              0x75
#define FONT_N              0x76
#define FONT_O              0x77
#define FONT_P              0x78
#define FONT_Q              0x79
#define FONT_R              0x7A
#define FONT_S              0x7B
#define FONT_T              0x7C
#define FONT_U              0x7D
#define FONT_V              0x7E
#define FONT_W              0x7F
#define FONT_X              0x80
#define FONT_Y              0x81
#define FONT_Z              0x82
#define FONT_a              0x83
#define FONT_b              0x84
#define FONT_c              0x85
#define FONT_d              0x86
#define FONT_e              0x87
#define FONT_f              0x88
#define FONT_g              0x89
#define FONT_h              0x8A
#define FONT_i              0x8B
#define FONT_j              0x8C
#define FONT_k              0x8D
#define FONT_l              0x8E
#define FONT_m              0x8F
#define FONT_n              0x90
#define FONT_o              0x91
#define FONT_p              0x92
#define FONT_q              0x93
#define FONT_r              0x94
#define FONT_s              0x95
#define FONT_t              0x96
#define FONT_u              0x97
#define FONT_v              0x98
#define FONT_w              0x99
#define FONT_x              0x9A
#define FONT_y              0x9B
#define FONT_z              0x9C
#define FONT_COMMA          0x9D
#define FONT_COLON          0x9E
#define FONT_EXCLAMATION    0x9F
#define FONT_DOT            0xA0
#define FONT_EQUALS         0xA1
#define FONT_OPEN_BRACKET   0xA2
#define FONT_CLOSE_BRACKET  0xA3
#define FONT_SLASH          0xA4






























/* (14, 12) */




#endif