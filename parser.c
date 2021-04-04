/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 04:09:08 by mbenjell          #+#    #+#             */
/*   Updated: 2018/01/05 15:22:08 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	existe(int v, t_pile *p)
{
	while (p)
	{
		if (v == p->v)
			return (1);
		p = p->next;
	}
	return (0);
}

int			extract(char *arg, t_data *d)
{
	t_pile	*new;

	if (!*arg)
		return (0);
	while (*arg)
	{
		while (is_space(&arg))
			;
		ft_protect((void*)(new = (t_pile*)malloc(sizeof(t_pile))));
		new->v = ft_watoi(&arg);
		if (existe(new->v, d->p[B]))
			ft_error();
		new->next = d->p[B];
		d->p[B] = new;
		d->lg[B]++;
		if (*arg && !is_space(&arg))
			ft_error();
		while (is_space(&arg))
			;
	}
	return (0);
}

int			parser(const char **argv, t_data *d)
{
	size_t	i;
	char	**arg;

	arg = (char**)argv;
	i = 1;
	while (arg[i])
	{
		while (is_space(&arg[i]))
			;
		if (!*arg)
			continue ;
		if (extract(arg[i++], d) == ERR)
			return (ERR);
	}
	while ((d->p)[B])
		push(d, A);
	return (0);
}
