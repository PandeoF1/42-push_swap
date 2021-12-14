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

typedef struct s_pile_a
{
	int				i;
	struct s_pile_a	*next;
	struct s_pile_a	*prev;
}	t_pile_a;

typedef struct s_pile_b
{
	int				i;
	struct s_pile_b	*next;
	struct s_pile_b	*prev;
}	t_pile_b;

typedef struct s_data
{
	struct s_pile_a	*pile_a;
	struct s_pile_b	*pile_b;
	struct s_pile_a	*last_a;
	struct s_pile_a	*temp;
	int				size_a;
	int				size_b;
}	t_data;

int		*ft_sort_tab(int *str, int size);
int		*ft_swap(t_data *data, int *number, int size, int *sorted_tab);
void	add_nmb_a(t_data *data, int nmb);
void	add_nmb_b(t_data *data, int nmb);

#endif