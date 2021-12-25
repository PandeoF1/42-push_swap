/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_radix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:08:43 by asaffroy          #+#    #+#             */
/*   Updated: 2021/12/25 14:56:24 by tnard            ###   ########lyon.fr   */
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

static long long	ft_swap_radix3(t_data *data, int d, int k, int len_max)
{
	int	i;

	k = 4;
	d *= 10;
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
	return (d);
}

static void	ft_swap_radix2(t_data *data, long long d, int len_max)
{
	int			i;
	int			k;

	while (data->max / d > 0)
	{
		k = 0;
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
		d = ft_swap_radix3(data, d, k, len_max);
	}
}

static void	ft_convert(t_data *data, int *tab)
{
	t_pile		*temp;
	int			i;
	char		*str1;
	char		*str;

	temp = data->pile_a;
	while (temp)
	{
		i = 0;
		while (temp->i != tab[i])
			i++;
		str = ft_itoa(i);
		str1 = ft_convert_base(str, "0123456789", "0123");
		if (temp->i == data->max)
		{
			temp->i = ft_atoi(str1);
			data->max = temp->i;
		}
		else
			temp->i = ft_atoi(str1);
		free(str);
		free(str1);
		temp = temp->next;
	}
}

void	ft_swap_radix(t_data *data, int *tab, int size, int *number)
{
	long long	d;
	int			len_max;
	static int	x = 0;

	d = 1;
	if (x == 0)
		ft_init(data, number, size);
	x++;
	ft_convert(data, tab);
	ft_swap_radix2(data, d, len_max);
}
