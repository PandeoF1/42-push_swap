/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:13:32 by tnard             #+#    #+#             */
/*   Updated: 2021/12/14 15:33:23 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pa(t_data *data)
{
	if (data->size_b > 0)
	{
		ft_lstadd_front((&data->pile_a), data->pile_b);
		data->size_a++;
		data->size_b--;
		ft_printf("pa\n");
	}
}

void	ft_pb(t_data *data)
{
	if (data->size_b > 0)
	{
		ft_lstadd_front((&data->pile_a), data->pile_b);
		data->size_a--;
		data->size_b++;
		ft_printf("pb\n");
	}
}
