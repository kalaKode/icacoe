#ifndef __BOARD_HEADER__
#define __BOARD_HEADER__

#include <stdint.h>

typedef uint8_t Board[3];
struct Position {
    uint8_t row;
    uint8_t col;
};
enum Player {
    CROSS = 1,
    CIRCLE = 2,
    NONE = 0
};
struct BoardState {
    enum Player curr_player;
    Board board;
};

void boardInit(struct BoardState *const inout_state);
void validMoves(const struct BoardState *const in_state, struct Position out_moves[10]);
enum Player playTurn(struct BoardState *const inout_state, const struct Position in_position);
void debugPrint(const struct BoardState *const state);

#endif
