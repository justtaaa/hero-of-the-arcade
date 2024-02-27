//
// Created by kevinCuni2004 on 26/02/2024.
//

#ifndef HERO_OF_THE_ARCADE_TETRIS_H
#define HERO_OF_THE_ARCADE_TETRIS_H
#define BOARD_HEIGHT 20
#define BOARD_WIDTH 10

//Block Pieces
int l-block[4][4] = {0,0,0,0,
                     0,1,0,0,
                     0,1,0,0,
                     0,1,1,0};

int j-block[4][4] = {0,0,0,0,
                     0,0,1,0,
                     0,0,1,0,
                     0,1,1,0};

int o-block[4][4] = {0,0,0,0,
                     0,1,1,0,
                     0,1,1,0,
                     0,0,0,0};

int z-block[4][4] = {0,0,0,0,
                     0,1,1,0,
                     0,0,1,1,
                     0,0,0,0};

int s-block[4][4] = {0,0,0,0,
                     0,0,1,1,
                     0,1,1,0,
                     0,0,0,0};

int t-block[4][4] = {0,0,0,0,
                     0,1,1,1,
                     0,0,1,0,
                     0,0,0,0};

#endif //HERO_OF_THE_ARCADE_TETRIS_H