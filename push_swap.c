/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:59:21 by mbenjell          #+#    #+#             */
/*   Updated: 2018/01/05 18:08:08 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		init_data(t_data *d)
{
	(d->p)[0] = NULL;
	(d->p)[1] = NULL;
	(d->lg)[0] = 0;
	(d->lg)[1] = 0;
	d->a = NULL;
	d->nb_instr = 0;
}

static void		little_sort(t_data *d)
{
	little_pile(d, A, d->lg[A]);
	if (d->nb_instr > 3)
		delete_useless(d);
	count_instr(d);
	write_it(d);
	free_instr(d->a);
	free_pile(d->p[A]);
	exit(1);
}

int				main(int argc, const char **argv)
{
	t_data		d;

	if (argc < 2)
		return (0);
	init_data(&d);
	if (parser(argv, &d) == ERR)
		ft_error();
	if (is_sort(&d, A, d.lg[A]))
	{
		free_pile(d.p[A]);
		return (0);
	}
	if (d.lg[A] > 2 && d.lg[A] < 20)
		little_sort(&d);
	algo(&d, A, d.lg[A]);
	count_instr(&d);
	if (d.nb_instr > 3)
		delete_useless(&d);
	count_instr(&d);
	write_it(&d);
	free_instr(d.a);
	free_pile(d.p[A]);
	return (0);
}
