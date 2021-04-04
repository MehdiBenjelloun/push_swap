/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 13:32:51 by mbenjell          #+#    #+#             */
/*   Updated: 2017/12/31 13:39:18 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			free_pile(t_pile *p)
{
	t_pile		*tmp;

	while (p)
	{
		tmp = p;
		p = p->next;
		free(tmp);
	}
}

void			free_instr(t_action *a)
{
	t_action	*tmp;

	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}
