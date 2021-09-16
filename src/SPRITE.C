#include "SPRITE.H"

byte getTileLocation(byte tileCode)
{
    switch(tileCode)
            {
                case BOARD_BORDER:
                    return 0;    

                case BOARD_BACKGROUND:
                    return 1;
                
                case BOARD_TOP_RIGHT:
                    return 2;
                
                case BOARD_TOP_LEFT:
                    return 3;
                
                case BOARD_BOTTOM_RIGHT:
                    return ;

                case BOARD_BOTTOM_LEFT:
                   
                    break;

                case TETROMINO_I:
                   
                    break;
                
                case TETROMINO_L:
                   
                    break;
                
                case TETROMINO_J:
                   
                    break;
                
                case TETROMINO_O:
                   
                    break;

                case TETROMINO_Z:
                   
                    break;

                case TETROMINO_S:
                   
                    break;
                
                case TETROMINO_T:
                   
                    break;
            }

    return 0;
}