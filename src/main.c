#include <stdlib.h>
#include <stdint.h>
#include <getopt.h>
#include <stdio.h>
#include <stdbool.h>

struct Config {
    int npc;
} Config;

struct Config config = {.npc = false};

void usage(char *progname) {
    fprintf(stderr, "usage: %s [-c]\n", progname);
}

static struct option const longOptions[] = {
    {"computer", no_argument, NULL, 'c'},
    {0, 0, 0, 0}
};

void parseOptions(int argc, char* argv[]) {
    char *progname = argv[0];
    int c, option_index = 0;
    while((c = getopt_long(argc, argv, "c", longOptions, &option_index)) != -1){
        switch (c)
        {
        case 'c':
            config.npc = true;
            break;
        default:
            usage(progname);
            exit(EXIT_FAILURE);
        }
    }
    if(optind != argc) {
        usage(progname);
        exit(EXIT_FAILURE);
    }
}

#include "board.h"

int main(int argc, char* argv[])
{
    parseOptions(argc, argv);
    struct BoardState board;
    boardInit(&board);
    debugPrint(&board);
    playTurn(&board, (struct Position){0, 0});
    playTurn(&board, (struct Position){1, 0});
    playTurn(&board, (struct Position){2, 2});
    playTurn(&board, (struct Position){1, 1});
    debugPrint(&board);
    exit(EXIT_SUCCESS);
}
