/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:03:44 by tnard             #+#    #+#             */
/*   Updated: 2021/12/14 14:11:29 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sa(t_data *data)
{
	int		tmp;

	if (data->size_a > 1)
	{
		tmp = data->pile_a[0].i;
		data->pile_a[0].i = data->pile_a[1].i;
		data->pile_a[1].i = tmp;
	}
	ft_printf("sa\n");
}

void	ft_sb(t_data *data)
{
	int		tmp;

	if (data->size_b > 1)
	{
		tmp = data->pile_b[0].i;
		data->pile_b[0].i = data->pile_b[1].i;
		data->pile_b[1].i = tmp;
	}
	ft_printf("sb\n");
}

void	ft_ss(t_data *data_a, t_data *data_b)
{
	ft_sa(data_a);
	ft_sb(data_b);
}
