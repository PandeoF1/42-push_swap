/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:14:58 by asaffroy          #+#    #+#             */
/*   Updated: 2021/12/12 18:14:58 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_init(t_data *data, int *number, int size)
{
	int		x;

	x = -1;
	while (++x < size)
		add_nmb_a(data, number[x]);
	data->size_a = x;
	data->size_b = 0;
	data->last_a = data->pile_a;
	while (data->last_a->next)
		data->last_a = data->last_a->next;
	data->last_b = NULL;
}

int	*ft_swap(t_data *data, int *number, int size, int *sorted_tab)
{
	int				mid;
	int				x;
	int				len_b;
	int				y;

	x = -1;
	y = 0;
	while (y < x - 2)
	{
		size /= 2;
		mid = number[size];
		len_b = 0;
		while (len_b < size)
		{
			if (data->pile_a->i < mid)
			{
				// ft_printf("pb\n");
				ft_pb(data);
				len_b++;
			}
			else if (data->last_a->i < mid)
			{
				ft_printf("rra\n");
				ft_printf("pb\n");
				len_b++;
			}
			else
			{
				if (data->pile_a->i > mid)
				{
					ft_printf("ra\n");
					if (data->pile_a->i < mid)
					{
						ft_printf("pb\n");
						len_b++;
					}
				}
			}
		}
		y += len_b;
	}
	return (0);
}
