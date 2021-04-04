/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:09:01 by mbenjell          #+#    #+#             */
/*   Updated: 2018/01/06 11:31:23 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE	4096
# define RESERVED	3
# define SEP 		'\n'
# define END		'\0'
# define A			0
# define B			1
# define AB			2
# define ERR		3
# define INF		4
# define SUP		5
# define BLOC		4

# define P			push
# define S			swap
# define R			rotate
# define RR			rotate_rev

typedef struct		s_mem
{
	char			*m;
	int				nb;
	struct s_mem	*next;
}					t_mem;

typedef struct		s_save
{
	int				fd;
	char			*buff_init;
	char			*buff;
	char			*p;
	int				nb;
	int				fin;
	int				i;
	size_t			j;
	struct s_mem	*mem;
	struct s_save	*next;
}					t_save;

typedef	struct		s_buffer
{
	char			buff[BUFF_SIZE + RESERVED];
	int				cpt;
}					t_buffer;

typedef struct		s_data
{
	struct s_pile	*p[2];
	struct s_pile	*temp;
	int				lg[2];
	int				deep;
	int				moved;
	struct s_action	*a;
	int				prof;
	int				r;
	int				nb_instr;
}					t_data;

typedef struct		s_pile
{
	int				v;
	struct s_pile	*next;
}					t_pile;

typedef	struct		s_action
{
	int				p;
	void			(*instr)(t_data*, int);
	struct s_action	*next;
}					t_action;

void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *s, int c, size_t n);
size_t				ft_strlen(const char *s);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
void				ft_strdel(char **as);
void				*ft_memcpy(void *dest, const void *src, size_t n);

int					get_line(t_save *s);
int					get_next_line(const int fd, char **line);

void				ft_protect(void *mem);
void				ft_error(void);
int					is_space(char **c);
int					is_inf(int v1, int v2);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_watoi(char **nptr);
int					extract(char *arg, t_data *d);
int					parse_instr(t_data *d);
int					parser(const char **argv, t_data *d);
void				write_it(t_data *d);
void				play_s(char *line, t_data *d);
void				play_p(char *line, t_data *d);
void				play_r(char *line, t_data *d);

void				push(t_data *d, int p);
void				swap(t_data *d, int p);
void				rotate(t_data *d, int p);
void				rotate_rev(t_data *d, int p);

int					is_sort(t_data *d, int p, int prof);
int					is_sort_decr(t_data *d, int p, int prof);
t_pile				*copy_pile(t_pile *src, int prof);
void				free_instr(t_action *a);
void				free_pile(t_pile *p);

void				couper(t_data *d, int p, int mediane, int inf_sup);
void				add_instr(t_data *d, void (*a)(t_data*, int), int p);

void				tri_bulle(t_data *d, int p, int card);
void				tri_optimum(t_data *d, int p);
void				tri_optimum_decr(t_data *d, int p);
void				sort3(t_data *d, int p);
void				sort5(t_data *d, int p);
void				little_pile(t_data *d, int p, int prof);

void				suite_a1(t_data *d, int p);
void				suite_a2(t_data *d, int p);
void				suite_a3(t_data *d, int p);
void				suite_a4(t_data *d, int p);
void				suite_a5(t_data *d, int p);

void				count_instr(t_data *d);
void				delete_useless(t_data *d);
void				algo(t_data *d, int p, int prof);

#endif
