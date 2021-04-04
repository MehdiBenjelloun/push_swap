/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 19:19:34 by mbenjell          #+#    #+#             */
/*   Updated: 2017/12/31 12:12:09 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	new_buff(t_save *s)
{
	free(s->buff_init);
	if (!(s->buff = (char*)malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	s->buff_init = s->buff;
	s->nb = read(s->fd, s->buff, BUFF_SIZE);
	if (s->nb == -1)
	{
		ft_strdel(&(s->buff_init));
		return (-1);
	}
	if (!s->nb)
	{
		ft_strdel(&(s->buff_init));
		return (0);
	}
	return (1);
}

static int	begin_read(t_save *s, t_mem **new)
{
	int		r;

	if (!(*new = (t_mem*)malloc(sizeof(t_mem))))
		return (-1);
	if (!s->nb)
	{
		if ((r = new_buff(s)) == 0 || r == -1)
		{
			free(*new);
			return (r);
		}
	}
	return (1);
}

static int	nsearch(t_save *s, t_mem *new)
{
	if (!(s->p = ft_memchr((const void*)(s->buff), SEP, s->nb)))
	{
		new->next = s->mem;
		s->mem = new;
		if (!((s->mem)->m = (char*)malloc(sizeof(char) * s->nb)))
			return (-1);
		ft_memcpy((void*)(s->mem)->m, (const void*)s->buff, s->nb);
		s->mem->nb = s->nb;
		s->nb = 0;
		s->j += s->mem->nb;
	}
	else
	{
		new->next = s->mem;
		s->mem = new;
		if (!((s->mem)->m = (char*)malloc(sizeof(char) * s->nb)))
			return (-1);
		ft_memcpy((void*)(s->mem)->m, (const void*)(s->buff), s->p - s->buff);
		s->mem->nb = s->p - s->buff;
		s->nb -= s->p - s->buff + 1;
		s->buff += s->p - s->buff + 1;
		s->j += s->mem->nb;
		return (1);
	}
	return (0);
}

int			get_line(t_save *s)
{
	t_mem	*new;
	int		b;

	while (42)
	{
		if ((b = begin_read(s, &new)) == 0 || b == -1)
			return (b);
		if (nsearch(s, new) == 1)
			return (1);
	}
	return (1);
}
