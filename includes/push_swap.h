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

typedef struct s_pile
{
	int				i;
	struct s_pile	*next;
	struct s_pile	*prev;
}	t_pile;

typedef struct s_chunk
{
	int				*tab;
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
	int				size_tab;
}	t_data;

int		*ft_sort_tab(int *str, int size);
int		*ft_swap(t_data *data, int *number, int size, int *sorted_tab);
void	add_nmb_a(t_data *data, int nmb);
void	add_nmb_b(t_data *data, int nmb);

void	ft_pa(t_data *data);
void	ft_pb(t_data *data);
void	ft_ra(t_data *data);
void	ft_2a(t_data *data);
void	ft_rra(t_data *data);

#endif