/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:37:27 by mbenjell          #+#    #+#             */
/*   Updated: 2018/01/05 14:24:35 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	mediane(t_data *d, int p)
{
	int		i;
	int		parite;
	t_pile	*copy;
	t_pile	*save;

	parite = (d->lg[p] % 2 == 0) ? 1 : 0;
	if (parite && d->lg[A] == 4)
		parite--;
	if (!d->p[p])
		return (0);
	copy = copy_pile((d->p)[p], d->prof);
	save = (d->p)[p];
	(d->p)[p] = copy;
	i = 0;
	tri_bulle(d, p, d->prof);
	while (i++ < (d->prof / 2) - parite)
		d->p[p] = d->p[p]->next;
	i = d->p[p]->v;
	(d->p)[p] = save;
	free_pile(copy);
	return (i);
}

static void	cut_it(t_data *d, int p, int sens)
{
	int		middle;

	middle = mediane(d, p);
	couper(d, p, middle, sens);
}

static void	sort_it(t_data *d, int p, int prof)
{
	if (p == A)
	{
		if (prof == 2)
		{
			if (d->p[p]->v > d->p[p]->next->v)
				add_instr(d, swap, p);
		}
		else if (prof == 3)
			tri_optimum(d, p);
	}
	else
	{
		if (prof == 2)
		{
			if (d->p[p]->v < d->p[p]->next->v)
				add_instr(d, swap, p);
		}
		else if (prof == 3)
			tri_optimum_decr(d, p);
	}
}

void		algo(t_data *d, int p, int prof)
{
	int		l;
	int		p2;
	int		pushed;

	l = d->lg[p];
	p2 = (p + 1) % 2;
	if (prof < BLOC)
		sort_it(d, p, prof);
	else
	{
		d->prof = prof;
		if (p == A)
			cut_it(d, p, INF);
		if (p == B)
			cut_it(d, p, SUP);
		pushed = l - d->lg[p];
		algo(d, p, prof - pushed);
		algo(d, p2, pushed);
		while (pushed--)
			add_instr(d, push, p);
	}
}
