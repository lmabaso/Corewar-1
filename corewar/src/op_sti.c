/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 07:50:28 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/26 11:04:02 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_function.h"

void	op_sti(struct s_process *bot)
{
	char	*mem;
	int		offset;
	int		*args;
	char	big_e[4];

	mem = g_env.memory;
	args = bot->args;
	args[0] = bot->reg[args[0]];
	f_little_to_big_endian(args[0], big_e);
	args[1] = (bot->is_reg[1]) ? bot->reg[args[1]] : args[1];
	args[2] = (bot->is_reg[2]) ? bot->reg[args[2]] : args[2];
	offset = bot->current_pc + WRAP_IDX(args[1] + args[2]);
	mem[WRAP_MEM(offset++)] = big_e[0];
	mem[WRAP_MEM(offset++)] = big_e[1];
	mem[WRAP_MEM(offset++)] = big_e[2];
	mem[WRAP_MEM(offset)] = big_e[3];
}

void	op_sti_verb(struct s_process *bot)
{
	char	*mem;
	int		offset;
	int		*args;
	char	big_e[4];

	mem = g_env.tmp_memory;
	args = bot->args;
	START_VERB(
		PRINT_PROCESS("sti");
		PRINT_REG(bot->args[0] + 1);)
	args[0] = bot->reg[args[0]];
	f_little_to_big_endian(args[0], big_e);
	args[1] = (bot->is_reg[1]) ? bot->reg[args[1]] : args[1];
	args[2] = (bot->is_reg[2]) ? bot->reg[args[2]] : args[2];
	offset = WRAP_MEM(bot->current_pc + WRAP_IDX(args[1] + args[2]));
	mem[offset] = big_e[0];
	mem[WRAP_MEM(offset + 1)] = big_e[1];
	mem[WRAP_MEM(offset + 2)] = big_e[2];
	mem[WRAP_MEM(offset + 3)] = big_e[3];
	START_VERB(
		PRINT_ARG(args[1]);
		PRINT_ARG(args[2]);
		PRINT_ENDL;
		PRINT_OFFSET;
		f_printf(" -> store to %d + %d = %d (with pc and mod %d)",
			args[1], args[2], args[1] + args[2], offset);
		PRINT_ENDL;)
}

void	op_sti_vis(struct s_process *bot)
{
	char	*mem;
	int		offset;
	int		*args;
	char	big_e[4];
	int		player;

	mem = g_env.memory;
	args = bot->args;
	args[0] = bot->reg[args[0]];
	f_little_to_big_endian(args[0], big_e);
	args[1] = (bot->is_reg[1]) ? bot->reg[args[1]] : args[1];
	args[2] = (bot->is_reg[2]) ? bot->reg[args[2]] : args[2];
	offset = bot->current_pc + WRAP_IDX(args[1] + args[2]);
	player = GET_OWNER(bot->current_pc);
	SET_VIS_MEM(WRAP_MEM(offset), big_e[0], player);
	g_env.memory[WRAP_MEM(offset++)] = big_e[0];
	SET_VIS_MEM(WRAP_MEM(offset), big_e[1], player);
	g_env.memory[WRAP_MEM(offset++)] = big_e[1];
	SET_VIS_MEM(WRAP_MEM(offset), big_e[2], player);
	g_env.memory[WRAP_MEM(offset++)] = big_e[2];
	SET_VIS_MEM(WRAP_MEM(offset), big_e[3], player);
	g_env.memory[WRAP_MEM(offset)] = big_e[3];
}
