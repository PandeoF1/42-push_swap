/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_radix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:08:43 by asaffroy          #+#    #+#             */
/*   Updated: 2021/12/24 11:23:50 by asaffroy         ###   ########lyon.fr   */
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
	data->pile_b->next = NULL;
}

static int	ft_is_in(t_data *data, int d, int k)
{
	t_pile	*tmp;

	tmp = data->pile_a;
	while (tmp)
	{
		if (((tmp->i / d) % 10) == k)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int	ft_is_in2(t_data *data, int d, int k)
{
	t_pile	*tmp;

	tmp = data->pile_b;
	while (tmp)
	{
		if (((tmp->i / d) % 10) == k)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_swap_radix(t_data *data, int *tab, int size, int *number)
{
	t_pile		*temp;
	int			i;
	int			k;
	long long	d;
	int			len_max;
	static int	x = 0;

	d = 1;
	i = 0;
	if (x == 0)
		ft_init(data, number, size);
	x++;
	temp = data->pile_a;
	while (temp)
	{
		while (temp->i != tab[i])
			i++;
		if (temp->i == data->max)
		{
			temp->i
				= ft_atoi(ft_convert_base(ft_itoa(i), "0123456789", "0123"));
			data->max = temp->i;
		}
		else
			temp->i
				= ft_atoi(ft_convert_base(ft_itoa(i), "0123456789", "0123"));
		i = 0;
		temp = temp->next;
	}
	while (data->max / d > 0)
	{
		k = 0;
		i = 0;
		while (k <= 4)
		{
			i = 0;
			len_max = data->size_a;
			if (ft_is_in(data, d, k))
			{
				while (i < len_max)
				{
					if ((data->pile_a->i / d % 10) == k)
						ft_pb(data);
					else if (data->size_a > 1)
						ft_ra(data);
					i++;
				}
			}
			k++;
		}
		k = 4;
		d *= 10;
		//temp = data->pile_a;
		i = 0;
		while (k >= 0)
		{
			i = 0;
			len_max = data->size_b;
			if (ft_is_in2(data, d, k))
			{
				while (i < len_max)
				{
					if ((data->pile_b->i / d % 10) == k)
						ft_pa(data);
					else if (data->size_b > 1)
						ft_rb(data);
					i++;
				}
			}
			k--;
		}
		d *= 10;
	}
}
