/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:50:32 by tnard             #+#    #+#             */
/*   Updated: 2021/12/10 17:48:18 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_free
{
	void			*addr;
	struct s_free	*next;
}					t_free;

typedef struct s_pile
{
	int				i;
	struct s_pile	*next;
}	t_pile;

typedef struct s_main
{
	char		*str;
	char		**strr;
	int			*number;
	int			*sorted_tab;
	int			size;
	int			a;
}	t_main;

typedef struct s_chunk
{
	int				*tab;
	int				size;
	struct s_chunk	*next;
}	t_chunk;

typedef struct s_data
{
	struct s_pile	*pile_a;
	struct s_pile	*pile_b;
	struct s_pile	*last_a;
	struct s_pile	*last_b;
	struct s_pile	*temp;
	struct s_chunk	*chunk;
	int				size_a;
	int				size_b;
	int				in_list;
	int				nb_chunk;
	int				len_chunk;
	int				nb_pa;
	int				nb_rb;
	int				nb_rb2;
	int				nb_ra;
	int				a;
	int				max;
}	t_data;

int			*ft_sort_tab(int *str, int size);
void		add_nmb_a(t_data *data, int nmb);
int			ft_is_sorted(int *number, int size);
int			ft_sorted_in_a(t_data *data, int size);
int			*ft_update(t_data *data, int size);
int			i_base(char c, char *base);
int			is_base(char c, char *base);
int			check_base(char *base);
int			ft_first_sort(char **data);
void		ft_rev_tab(char *tab, int size);
long int	ft_atoi_base(char *str, char *base);
long int	ft_fill_tab(char *tab, long int num, char *base_to);
char		*ft_convert_base(char *nbr, char *base_from, char *base_to);
void		ft_swap_radix(t_data *data, int *tab, int size, int *number);
int			ft_is_in(t_data *data, int d, int k);
int			ft_is_in2(t_data *data, int d, int k);
int			ft_check_double(int *number, int size);
int			ft_int_len(int x);
void		ft_usage(void);
void		ft_sort(int argc, char *argv[], t_main *main, t_data *data);
int			ft_space_len(char *str);
int			*ft_splittochar(char **str, int *y);
int			ft_check_one_arg(char *str);
int			ft_check_mult_arg(char **argv, int argc);
char		*ft_strcat(char *dest, char *src);
char		*ft_argc_to_tab(char **argv, int argc);

void		ft_pa(t_data *data);
void		ft_pb(t_data *data);
void		ft_sb(t_data *data);
void		ft_sa(t_data *data);
void		ft_ra(t_data *data);
void		ft_rb(t_data *data);
void		ft_rra(t_data *data);
void		ft_rrb(t_data *data);
void		ft_rrr(t_data *data);
void		ft_ss(t_data *data);
void		ft_free(t_data *data);

#endif