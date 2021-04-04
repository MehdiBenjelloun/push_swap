/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 23:38:25 by mbenjell          #+#    #+#             */
/*   Updated: 2018/01/01 23:00:14 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push(t_data *d, int p)
{
	t_pile	*tmp;
	int		from;

	from = (p + 1) % 2;
	if (!(d->p)[from])
		return ;
	tmp = (d->p)[from];
	(d->p)[from] = (d->p)[from]->next;
	tmp->next = (d->p)[p];
	(d->p)[p] = tmp;
	(d->lg)[p]++;
	(d->lg)[from]--;
}

void		swap(t_data *d, int p)
{
	int		tmp;

	if ((d->lg)[p] < 2)
		return ;
	tmp = (d->p)[p]->v;
	(d->p)[p]->v = (d->p)[p]->next->v;
	(d->p)[p]->next->v = tmp;
}

void		rotate(t_data *d, int p)
{
	t_pile	*tmp;

	if ((d->lg)[p] < 2)
		return ;
	tmp = (d->p)[p];
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = (d->p)[p];
	(d->p)[p] = (d->p)[p]->next;
	tmp->next->next = NULL;
}

void		rotate_rev(t_data *d, int p)
{
	t_pile	*tmp;
	t_pile	*sommet;

	if ((d->lg)[p] < 2)
		return ;
	tmp = (d->p)[p];
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	sommet = tmp->next;
	tmp->next = NULL;
	sommet->next = (d->p)[p];
	(d->p)[p] = sommet;
}
