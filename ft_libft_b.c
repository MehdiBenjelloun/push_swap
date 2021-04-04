/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 12:20:17 by mbenjell          #+#    #+#             */
/*   Updated: 2017/12/31 12:23:25 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	if (n == 0)
		return (NULL);
	if (*(unsigned char*)s == (unsigned char)c)
		return ((void*)s);
	return ((n - 1) ? ft_memchr((const void*)((unsigned char*)(++s)), c, --n)
																	: NULL);
}

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*p_init;

	p_init = dest;
	while (n--)
		*((unsigned char*)dest++) = *((unsigned char*)src++);
	return (p_init);
}

void		ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void		*ft_memset(void *s, int c, size_t n)
{
	while (n)
		((unsigned char*)s)[--n] = (unsigned char)c;
	return (s);
}
