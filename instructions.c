/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 08:12:35 by mbenjell          #+#    #+#             */
/*   Updated: 2018/01/01 19:15:58 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			add_instr(t_data *d, void (*a)(t_data*, int), int p)
{
	t_action	*act;
	t_action	*tmp;

	ft_protect((void*)(act = (t_action*)malloc(sizeof(t_action))));
	act->instr = a;
	if (d->a == NULL)
	{
		d->a = act;
		act->p = p;
		act->next = NULL;
		a(d, p);
		return ;
	}
	tmp = d->a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = act;
	act->p = p;
	act->next = NULL;
	a(d, p);
}

static int		is_useless(t_action *a)
{
	if (a->p == !a->next->p)
	{
		if (a->instr == P && a->next->instr == P)
			return (1);
	}
	else
	{
		if (a->instr == R && a->next->instr == RR)
			return (1);
		else if (a->instr == RR && a->next->instr == R)
			return (1);
	}
	return (0);
}

void			count_instr(t_data *d)
{
	t_action	*temp;

	temp = d->a;
	d->nb_instr = 0;
	while (temp)
	{
		temp = temp->next;
		d->nb_instr++;
	}
}

void			move(t_data *d, t_action **a, t_action **prev)
{
	t_action	*tmp;
	t_action	*tmp2;

	if (!*prev)
	{
		tmp = *a;
		tmp2 = (*a)->next;
		*a = (*a)->next->next;
		free(tmp);
		free(tmp2);
	}
	else
	{
		tmp = (*prev)->next;
		tmp2 = (*a)->next;
		(*prev)->next = (*a)->next->next;
		*a = d->a;
		free(tmp);
		free(tmp2);
	}
}

void			delete_useless(t_data *d)
{
	t_action	*a;
	t_action	*prev;

	a = d->a;
	prev = NULL;
	while (a->next->next)
	{
		if (is_useless(a))
			move(d, &a, prev ? &prev : NULL);
		else
		{
			prev = a;
			a = a->next;
		}
	}
}
