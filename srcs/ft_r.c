/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:16:51 by tnard             #+#    #+#             */
/*   Updated: 2021/12/15 11:24:33 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(t_data *data)
{
	t_pile	*tmp;

	tmp = data->pile_a->next;
	data->last_a->next = data->pile_a;	
	data->last_a->next->next = NULL;
	data->pile_a = tmp;
	ft_printf("ra\n");
}

void	ft_rra(t_data *data)
{
	int		x;
	t_pile	*tmp;

	x = 0;
	while (x < data->pile_a - 1)
	{
		tmp = data->pile_a->next;
		data->last_a->next = data->pile_a;
		data->last_a->next->next = NULL;
		data->pile_a = tmp;
		free(tmp);
		x++;
	}
}
