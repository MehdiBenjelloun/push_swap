/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:04:14 by mbenjell          #+#    #+#             */
/*   Updated: 2018/01/01 21:12:40 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			play_s(char *line, t_data *d)
{
	if (!ft_strcmp(line, "sa"))
		swap(d, A);
	else if (!ft_strcmp(line, "sb"))
		swap(d, B);
	else if (!ft_strcmp(line, "ss"))
		swap(d, A);
	else
		play_p(line, d);
}

void			play_p(char *line, t_data *d)
{
	if (!ft_strcmp(line, "pa"))
		push(d, A);
	else if (!ft_strcmp(line, "pb"))
		push(d, B);
	else
		play_r(line, d);
}

void			play_r(char *line, t_data *d)
{
	if (!ft_strcmp(line, "ra"))
		rotate(d, A);
	else if (!ft_strcmp(line, "rb"))
		rotate(d, B);
	else if (!ft_strcmp(line, "rr"))
	{
		rotate(d, A);
		rotate(d, B);
	}
	else if (!ft_strcmp(line, "rra"))
		rotate_rev(d, A);
	else if (!ft_strcmp(line, "rrb"))
		rotate_rev(d, B);
	else if (!ft_strcmp(line, "rrr"))
	{
		rotate_rev(d, A);
		rotate_rev(d, B);
	}
	else
		d->moved = 0;
}

int				parse_instr(t_data *d)
{
	char		*line;

	while ((get_next_line(0, &line) == 1))
	{
		if ((ft_strlen(line) == 0))
		{
			free(line);
			ft_error();
		}
		d->moved = 1;
		play_s(line, d);
		free(line);
		line = NULL;
		if (!d->moved)
			ft_error();
	}
	free(line);
	line = NULL;
	return (0);
}
