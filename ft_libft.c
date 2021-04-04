/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 10:26:03 by mbenjell          #+#    #+#             */
/*   Updated: 2017/12/31 12:22:40 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

void		ft_strdel(char **as)
{
	if (!as)
		return ;
	ft_memdel((void**)as);
}

void		ft_memdel(void **ap)
{
	free(*ap);
	*ap = NULL;
}

void		*ft_memalloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (!p)
		return (NULL);
	ft_bzero(p, size);
	return (p);
}
