/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:00:06 by mbenjell          #+#    #+#             */
/*   Updated: 2018/01/05 18:16:41 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		init_data(t_data *d)
{
	(d->p)[0] = NULL;
	(d->p)[1] = NULL;
	(d->lg)[0] = 0;
	(d->lg)[1] = 0;
}

int				main(int argc, const char **argv)
{
	t_data		d;

	if (argc < 2)
		return (0);
	init_data(&d);
	if (parser(argv, &d) == ERR)
		ft_error();
	parse_instr(&d);
	if (d.lg[B] != 0)
	{
		write(1, "KO\n", 3);
		free_pile(d.p[A]);
		free_pile(d.p[B]);
		return (0);
	}
	if (!is_sort(&d, A, d.lg[A]))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free_pile(d.p[A]);
	return (0);
}
