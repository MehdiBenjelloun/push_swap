/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 20:17:29 by mbenjell          #+#    #+#             */
/*   Updated: 2017/11/12 17:19:50 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_protect(void *mem)
{
	if (mem == NULL)
		ft_error();
}

void			ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
