#include "board.h"
#include <stdio.h>

const uint8_t case_mask = 0x3;

void boardInit(struct BoardState *const state) {
    state->board[0] = 0;
    state->board[1] = 0;
    state->board[2] = 0;
    state->curr_player = CROSS;
}

void validMoves(const struct BoardState *const state, struct Position positions[10]) {
    uint8_t positionsCount = 0;
    for(uint8_t row = 0; row < 3; row++) {
        for(uint8_t col = 0; col < 3; col++) {
            if((state->board[row] & (case_mask << (col << 1))) == NONE) {
                positions[positionsCount++] = (struct Position){row, col};
            }
        }
    }
    positions[positionsCount] = (struct Position){0};
}

enum Player playTurn(struct BoardState *const state, const struct Position position){
    state->board[position.row] |= state->curr_player << (position.col << 1);
    state->curr_player = state->curr_player ^ case_mask;
    return NONE;
}

void debugPrint(const struct BoardState *const state) {
    for(uint8_t row = 0; row < 3; row++) {
        printf("-------\n");
        for(uint8_t col = 0; col < 3; col++) {
            printf("|");
            switch( (state->board[row] & 0xFF) >> (col << 1) & case_mask) {
                case CROSS:
                    printf("X");
                    break;
                case CIRCLE:
                    printf("O");
                    break;
                default:
                    printf(" ");
            }
        }
        printf("|\n");
    }
    printf("-------\n");
}
