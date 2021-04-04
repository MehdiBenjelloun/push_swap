/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 17:09:14 by mbenjell          #+#    #+#             */
/*   Updated: 2017/12/30 18:07:10 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	check_buff(t_buffer *b)
{
	if (b->cpt >= BUFF_SIZE)
	{
		write(1, b->buff, b->cpt);
		b->cpt = 0;
	}
}

static void		write_on(t_buffer *b, char *s)
{
	while (*s)
	{
		b->buff[b->cpt++] = *s++;
		check_buff(b);
	}
}

static void		write_instr(t_action *a, t_buffer *b)
{
	if (a->p == A)
	{
		if (a->instr == push)
			write_on(b, "pa\n");
		if (a->instr == swap)
			write_on(b, "sa\n");
		if (a->instr == rotate)
			write_on(b, "ra\n");
		if (a->instr == rotate_rev)
			write_on(b, "rra\n");
	}
	else if (a->p == B)
	{
		if (a->instr == push)
			write_on(b, "pb\n");
		if (a->instr == swap)
			write_on(b, "sb\n");
		if (a->instr == rotate)
			write_on(b, "rb\n");
		if (a->instr == rotate_rev)
			write_on(b, "rrb\n");
	}
}

void			write_it(t_data *d)
{
	t_buffer	b;
	t_action	*a;

	b.cpt = 0;
	a = d->a;
	while (a)
	{
		write_instr(a, &b);
		a = a->next;
	}
	write(1, b.buff, b.cpt);
}
