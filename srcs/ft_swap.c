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

int	*ft_swap(t_data *data, int *number, int size, int *sorted_tab)
{
	int				mid;
	int				x;
	int				len_b;

	mid = number[size / 2];
	x = -1;
	while (++x < size)
		add_nmb_a(data, number[x]);
	data->first_a = data->pile_a;
	data->last_a = data->pile_a;
	while (data->last_a->next)
	{
		data->temp = data->last_a;
		data->last_a = data->last_a->next;
		data->last_a->prev = data->temp;
	}
	x = 0;
	len_b = 0;
	while (len_b < (mid - 1))
	{
		if (data->first_a->i < mid)
		{
			ft_printf("pb\n");
			add_nmb_b(data, data->first_a->i);
			data->temp = data->first_a;
			data->first_a = data->first_a->next;
			free(data->temp);
			len_b++;
		}
		else if (data->last_a->i < mid)
		{
			ft_printf("rra\n");
			//printf("gud%d\n", data->last_a->i);
			while (data->last_a->prev)
			{
				data->last_a = data->last_a->prev;
				//data->temp = data->first_a;
				//data->first_a = data->first_a->prev;
				//printf("guh%d\n", data->first_a->i);
				//data->first_a = data->first_a->next;
				ft_printf("gud%d\n", data->last_a->i);
			}
			// data->first_a = data->pile_a;
			// while (data->first_a->next)
			// {
			// 	data->first_a = data->first_a->next;
			// }
			len_b++;
		}
		else
		{
			if (data->first_a->i > mid)
			{
				ft_printf("ra\n");
				data->temp = data->first_a;
				data->last_a = data->first_a;
				free(data->temp);
				len_b++;
			}
		}
	}
	return (0);
}
