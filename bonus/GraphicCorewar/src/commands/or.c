/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** or
*/

#include "header.h"

int check_or(int *args, player_t *player, corewar_t *corewar, int *prototype)
{
    return 0;
}

int or_function(int *args, player_t *player,
corewar_t *corewar, int *prototype)
{
    int val1 = args[0];
    int val2 = args[1];

    if (proto_to_type[prototype[0]] == T_REG)
        val1 = player->registers[args[0] - 1];
    if (proto_to_type[prototype[0]] == T_IND)
        val1 = corewar->memory[get_mod(player->pc
        + args[0] % IDX_MOD, MEM_SIZE)];
    if (proto_to_type[prototype[1]] == T_REG)
        val2 = player->registers[args[1] - 1];
    if (proto_to_type[prototype[1]] == T_IND)
        val2 = corewar->memory[get_mod(player->pc
        + args[1] % IDX_MOD, MEM_SIZE)];
    player->registers[args[2] - 1] = val1 | val2;
    return 0;
}
