/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:03:44 by tnard             #+#    #+#             */
/*   Updated: 2021/12/15 17:14:41 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sa(t_data *data)
{
	int		tmp;
	t_pile	*tmp2;

	if (data->size_a > 1)
	{
		tmp2 = data->pile_a;
		tmp2 = tmp2->next;
		tmp = data->pile_a->i;
		data->pile_a->i = tmp2->i;
		tmp2->i = tmp;
	}
	ft_printf("sa\n");
}

void	ft_sb(t_data *data)
{
	int		tmp;
	t_pile	*tmp2;

	if (data->size_b > 1)
	{
		tmp2 = data->pile_b;
		tmp2 = tmp2->next;
		tmp = data->pile_b->i;
		data->pile_b->i = tmp2->i;
		tmp2->i = tmp;
	}
	ft_printf("sb\n");
}

void	ft_ss(t_data *data_a, t_data *data_b)
{
	ft_sa(data_a);
	ft_sb(data_b);
}
