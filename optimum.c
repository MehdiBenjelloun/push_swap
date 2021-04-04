/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 14:00:37 by mbenjell          #+#    #+#             */
/*   Updated: 2017/12/30 18:12:14 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		suite_a1(t_data *d, int p)
{
	add_instr(d, rotate, p);
	add_instr(d, swap, p);
	add_instr(d, rotate_rev, p);
}

void		suite_a2(t_data *d, int p)
{
	add_instr(d, swap, p);
}

void		suite_a3(t_data *d, int p)
{
	add_instr(d, rotate, p);
	add_instr(d, swap, p);
	add_instr(d, rotate_rev, p);
	add_instr(d, swap, p);
}

void		suite_a4(t_data *d, int p)
{
	add_instr(d, swap, p);
	add_instr(d, rotate, p);
	add_instr(d, swap, p);
	add_instr(d, rotate_rev, p);
}

void		suite_a5(t_data *d, int p)
{
	add_instr(d, swap, p);
	add_instr(d, rotate, p);
	add_instr(d, swap, p);
	add_instr(d, rotate_rev, p);
	add_instr(d, swap, p);
}
