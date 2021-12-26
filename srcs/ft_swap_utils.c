/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:49:29 by asaffroy          #+#    #+#             */
/*   Updated: 2021/12/26 13:58:23 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_in(t_data *data, int d, int k)
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

int	ft_is_in2(t_data *data, int d, int k)
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

int	ft_is_sorted(int *number, int size)
{
	int	i;

	i = 0;
	while (i < size - 2)
	{
		if (number[i] > number[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_sorted_in_a(t_data *data, int size)
{
	int	*tab;
	int	i;
	int	*number;

	number = ft_update(data, size);
	tab = ft_sort_tab(number, size);
	number = ft_update(data, size);
	i = 0;
	size--;
	if (number[size] == tab[size])
	{
		while (size >= 0 && number[size] == tab[size])
		{
			i++;
			size--;
		}
	}
	return (i);
}

int	ft_check_double(int *number, int size)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			if (x != y && number[x] == number[y])
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}
