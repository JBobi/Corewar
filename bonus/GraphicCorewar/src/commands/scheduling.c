/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** tourniquet
*/

#include "header.h"

int check_execution(corewar_t *corewar, player_t *tmp)
{
    int id;

    if (tmp->executing == TRUE && check_command(tmp, corewar) == TRUE) {
        execute_command(tmp, corewar);
        tmp->executing = FALSE;
        tmp->carry = 1;
    }
    if (check_command(tmp, corewar) == TRUE
    || corewar->memory[get_mod(tmp->pc, MEM_SIZE)] == 9) {
        tmp->status = op_tab[(int)get_mod(corewar->memory[
        get_mod(tmp->pc, MEM_SIZE)] - 1, MEM_SIZE)].nbr_cycles - 1;
        tmp->executing = TRUE;
    } else {
        tmp->pc = (tmp->pc + 1 % IDX_MOD) % MEM_SIZE;
        tmp->carry = 0;
    }
    return 0;
}

int scheduling(corewar_t *corewar)
{
    player_t *tmp;

    for (tmp = corewar->players; tmp; tmp = tmp->next) {
        if (tmp->status == 0) {
            attron(COLOR_PAIR(((int)corewar->color[get_mod(tmp->pc, MEM_SIZE)] == 0) ? 8 : (int)corewar->color[tmp->pc]));
            mvprintw(tmp->pc / 128, tmp->pc % 128, "%s", " ");
            attroff(COLOR_PAIR(((int)corewar->color[get_mod(tmp->pc, MEM_SIZE)] == 0) ? 8 : (int)corewar->color[tmp->pc]));
            refresh();
            check_execution(corewar, tmp);
            attron(COLOR_PAIR(9));
            mvprintw(tmp->pc / 128, tmp->pc % 128, "%s", " ");
            attroff(COLOR_PAIR(9));
            refresh();
        } else
            tmp->status--;
    }
    return 0;
}
