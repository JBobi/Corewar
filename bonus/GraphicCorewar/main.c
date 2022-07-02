/*
** EPITECH PROJECT, 2022
** B-CPE-201-LYN-2-1-corewar-leo.dubosclard
** File description:
** main
*/

#include "header.h"

void init_window(void)
{
    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();
    clear();
    refresh();
}

void init_colors(void)
{
    start_color();
    init_pair(0, COLOR_BLACK, COLOR_BLACK);
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);
    init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(4, COLOR_BLUE, COLOR_BLUE);
    init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(6, COLOR_CYAN, COLOR_CYAN);
    init_pair(7, COLOR_WHITE, COLOR_WHITE);
    init_pair(8, COLOR_BLACK, COLOR_BLACK);
    init_pair(9, COLOR_WHITE, COLOR_WHITE);
}

int main(int ac, char **av)
{
    initscr();
    init_colors();
    init_window();
    return vm(ac, av);
}
