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

static int	*ft_maketab(t_data *data)
{
	t_pile	*tmp;
	int		*tab;
	int		i;

	i = 0;
	tmp = data->pile_a;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	tab = malloc(sizeof(int) * i);
	if (!tab)
		return (NULL);
	tmp = data->pile_a;
	i = 0;
	while (tmp)
	{
		tab[i] = tmp->i;
		tmp = tmp->next;
		i++;
	}
	return (tab);
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
				ft_pb(data);
				ft_printls(data);
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
		}
		y += len_b;
		free(sorted_tab);
		sorted_tab = ft_maketab(data);
		//ft_chunk(data);
		sorted_tab = ft_sort_tab(sorted_tab, data->size_a);
		if (data->size_a == 2)
		{
			ft_2a(data);
			ft_pb(data);
		}
		ft_printls(data);
	}
	return (0);
}
