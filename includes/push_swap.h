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
}	t_data;

int		*ft_sort_tab(int *str, int size);
void	ft_swap(t_data *data, int *number, int size, int *sorted_tab);
void	add_nmb_a(t_data *data, int nmb);
void	add_nmb_b(t_data *data, int nmb);
void	ft_chunk(t_data *data);
int		*ft_chunk2(t_data *data, int *i);
int		ft_is_sorted(int *number, int size);
int		ft_is_rev_sorted(int *number, int size);
int		ft_sorted_in_a(t_data *data, int size);
int		*ft_update(t_data *data, int size);

void	ft_pa(t_data *data);
void	ft_pb(t_data *data);
void	ft_sb(t_data *data);
void	ft_sa(t_data *data);
void	ft_ra(t_data *data);
void	ft_rb(t_data *data);
void	ft_rra(t_data *data);
void	ft_rrb(t_data *data);
void	ft_rr(t_data *data);
void	ft_rrr(t_data *data);
void	ft_ss(t_data *data);
void	ft_free(t_data *data);

#endif