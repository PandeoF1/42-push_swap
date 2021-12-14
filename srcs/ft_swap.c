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

static void	ft_printls(t_data *date)
{
	t_pile	*tmp;

	tmp = date->pile_a;
	ft_printf("Debut a : ");
	while (tmp)
	{
		ft_printf("%i - ", tmp->i);
		tmp = tmp->next;
	}
	ft_printf("\nFin a.\nDebut b : ");
	tmp = date->pile_b;
	while (tmp)
	{
		ft_printf("%i - ", tmp->i);
		tmp = tmp->next;
	}
	ft_printf("\nFin b.\n");
}

static int	ft_init(t_data *data, int *number, int size)
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
	data->pile_b->next = NULL;
	ft_printf("TEEEEEESSSSSSTTTTT : %d\n", data->pile_b->i);
	return (x);
}

int	*ft_swap(t_data *data, int *number, int size, int *sorted_tab)
{
	int				mid;
	int				x;
	int				len_b;
	int				y;

	x = ft_init(data, number, size);
	y = 0;
	while (y < (x - 2))
	{
		size /= 2;
		mid = sorted_tab[size];
		len_b = 0;
		while (len_b < size)
		{
			if (data->pile_a->i < mid)
			{
				// ft_printf("pb\n");
				ft_pb(data);
				ft_printls(data);
				//ft_printf("pb_test%d\n", data->pile_b->i);
				len_b++;
			}
			else if (data->last_a->i < mid)
			{
				ft_printf("rra\n");
				ft_printls(data);
				ft_printf("pb\n");
				len_b++;
			}
			else
			{
				if (data->pile_a->i > mid)
				{
					ft_ra(data);
					ft_printls(data);
					if (data->pile_a->i < mid)
					{
						ft_pb(data);
						ft_printls(data);
						len_b++;
					}
				}
			}
			ft_printf("len : %d\n" , len_b);
		}
		y += len_b;
	}
	return (0);
}
