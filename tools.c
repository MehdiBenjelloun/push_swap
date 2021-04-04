/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 05:29:37 by mbenjell          #+#    #+#             */
/*   Updated: 2018/01/05 01:03:05 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_space(char **c)
{
	if (**c == ' ' || **c == '\n' || **c == '\t' || **c == '\v'
			|| **c == '\f' || **c == '\r')
	{
		(*c)++;
		return (1);
	}
	if (**c == '\\')
	{
		(*c)++;
		if (**c != 'n' && **c != 't')
			return (0);
		(*c)++;
		return (1);
	}
	return (0);
}

int			ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*((unsigned char*)s1) - *((unsigned char*)s2));
}

int			ft_watoi(char **nptr)
{
	long	nb;
	int		negatif;

	nb = 0;
	negatif = 0;
	while (is_space(nptr))
		;
	if (**nptr == '+' || **nptr == '-')
	{
		if (**nptr == '-')
			negatif = 1;
		(*nptr)++;
	}
	if (!(**nptr && **nptr >= '0' && **nptr <= '9'))
		ft_error();
	while (**nptr && **nptr >= '0' && **nptr <= '9')
	{
		if (negatif)
			nb = nb * 10 - **nptr + '0';
		else
			nb = nb * 10 + **nptr - '0';
		(nb < INT_MIN || nb > INT_MAX) ? ft_error() : 42;
		(*nptr)++;
	}
	return ((int)nb);
}

int			is_sort(t_data *d, int p, int prof)
{
	t_pile	*pl;

	pl = (d->p)[p];
	if (!pl)
		return (1);
	while (pl->next && prof--)
	{
		if (pl->next->v < pl->v)
			return (0);
		pl = pl->next;
	}
	return (1);
}

t_pile		*copy_pile(t_pile *src, int prof)
{
	t_pile	*dest;
	t_pile	*new;

	dest = NULL;
	while (src && prof--)
	{
		ft_protect((void*)(new = (t_pile*)malloc(sizeof(t_pile))));
		new->v = src->v;
		new->next = dest;
		dest = new;
		src = src->next;
	}
	return (dest);
}
