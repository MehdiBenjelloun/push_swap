/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 12:20:58 by mbenjell          #+#    #+#             */
/*   Updated: 2018/01/05 14:27:34 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_pile *p)
{
	int		min;

	min = p->v;
	while (p)
	{
		if (p->v < min)
			min = p->v;
		p = p->next;
	}
	return (min);
}

static void	push_min(t_data *d, int p, int prof)
{
	int		h;
	int		min;
	int		first;
	t_pile	*pile;
	void	(*a)(t_data*, int);

	pile = d->p[p];
	first = d->p[p]->v;
	min = find_min(d->p[p]);
	h = 0;
	while (d->p[p]->v != min)
	{
		rotate(d, p);
		h++;
	}
	while (d->p[p]->v != first)
		rotate_rev(d, p);
	min = prof - h;
	h <= min ? (prof = h)
			: (prof = min);
	h <= min ? (a = R)
			: (a = RR);
	while (prof--)
		add_instr(d, a, p);
	add_instr(d, P, !p);
}

void		sort3(t_data *d, int p)
{
	int		first;
	int		second;
	int		third;

	first = d->p[p]->v;
	second = d->p[p]->next->v;
	third = d->p[p]->next->next->v;
	if (!is_inf(first, second) && !is_inf(first, third))
		add_instr(d, R, p);
	else if (!is_inf(second, first) && !is_inf(second, third))
		add_instr(d, RR, p);
	if (d->p[p]->v > d->p[p]->next->v)
		add_instr(d, S, p);
}

void		sort5(t_data *d, int p)
{
	push_min(d, p, 5);
	push_min(d, p, 4);
	if (d->p[!p]->v < d->p[!p]->next->v)
		add_instr(d, S, !p);
	sort3(d, p);
	add_instr(d, P, p);
	add_instr(d, P, p);
}

void		little_pile(t_data *d, int p, int prof)
{
	int		i;

	i = prof;
	if (i == 3)
		sort3(d, p);
	else if (i == 5)
		sort5(d, p);
	if (i == 3 || i == 5)
		return ;
	if (i > 5)
	{
		while (i > 5)
			push_min(d, p, i--);
		sort5(d, p);
	}
	else if (i > 3)
	{
		push_min(d, p, i--);
		sort3(d, p);
	}
	while (i++ < prof)
		add_instr(d, P, p);
}
