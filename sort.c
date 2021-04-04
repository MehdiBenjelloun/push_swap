/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 03:45:07 by mbenjell          #+#    #+#             */
/*   Updated: 2017/12/31 16:46:14 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		balayage(t_data *d, int p, int card)
{
	int		size;

	size = card;
	while (card > 1)
	{
		if ((d->p)[p]->v > (d->p)[p]->next->v)
			swap(d, p);
		rotate(d, p);
		card--;
	}
	rotate_rev(d, p);
	card++;
	while (card < size)
	{
		if ((d->p)[p]->v > (d->p)[p]->next->v)
			swap(d, p);
		rotate_rev(d, p);
		card++;
	}
}

void		tri_bulle(t_data *d, int p, int card)
{
	while (!is_sort(d, p, card))
		balayage(d, p, card);
}

int			is_inf(int v1, int v2)
{
	return (v1 < v2);
}

void		tri_optimum(t_data *d, int p)
{
	int		a;
	int		b;
	int		c;

	a = d->p[p]->v;
	b = d->p[p]->next->v;
	c = d->p[p]->next->next->v;
	if (is_inf(a, b) && !is_inf(b, c) && is_inf(a, c))
		suite_a1(d, p);
	if (!is_inf(a, b) && is_inf(b, c) && is_inf(a, c))
		suite_a2(d, p);
	if (is_inf(a, b) && !is_inf(b, c) && !is_inf(a, c))
		suite_a3(d, p);
	if (!is_inf(a, b) && is_inf(b, c) && !is_inf(a, c))
		suite_a4(d, p);
	if (!is_inf(a, b) && !is_inf(b, c) && !is_inf(a, c))
		suite_a5(d, p);
}

void		tri_optimum_decr(t_data *d, int p)
{
	int		a;
	int		b;
	int		c;

	a = d->p[p]->v;
	b = d->p[p]->next->v;
	c = d->p[p]->next->next->v;
	if (is_inf(a, b) && is_inf(b, c) && is_inf(a, c))
		suite_a5(d, p);
	if (is_inf(a, b) && !is_inf(b, c) && is_inf(a, c))
		suite_a4(d, p);
	if (!is_inf(a, b) && is_inf(b, c) && is_inf(a, c))
		suite_a3(d, p);
	if (is_inf(a, b) && !is_inf(b, c) && !is_inf(a, c))
		suite_a2(d, p);
	if (!is_inf(a, b) && is_inf(b, c) && !is_inf(a, c))
		suite_a1(d, p);
}
