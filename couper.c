/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   couper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 07:44:36 by mbenjell          #+#    #+#             */
/*   Updated: 2017/12/31 10:46:09 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_or_next(t_data *d, int p, int mediane, int inf_sup)
{
	int		dest;

	dest = (p + 1) % 2;
	if (inf_sup == SUP)
	{
		if ((d->p)[p]->v > mediane)
			add_instr(d, push, dest);
		else
		{
			add_instr(d, rotate, p);
			d->r++;
		}
	}
	else
	{
		if ((d->p)[p]->v <= mediane)
			add_instr(d, push, dest);
		else
		{
			add_instr(d, rotate, p);
			d->r++;
		}
	}
}

void		couper(t_data *d, int p, int mediane, int inf_sup)
{
	int		i;

	i = d->prof;
	if (i <= 3)
		return ;
	d->r = 0;
	while (i--)
		push_or_next(d, p, mediane, inf_sup);
	while (d->r--)
		add_instr(d, rotate_rev, p);
}
