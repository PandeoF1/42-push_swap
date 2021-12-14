/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:13:32 by tnard             #+#    #+#             */
/*   Updated: 2021/12/14 16:08:03 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pa(t_data *data)
{
	if (data->size_b > 0)
	{
		data->last_a->next = data->pile_b;
		data->pile_b->prev = data->last_a;
		data->last_a = data->pile_b;
		data->pile_b = data->pile_b->next;
		data->last_a->next = NULL;
		data->size_a++;
		data->size_b--;
	}
}

void	ft_pb(t_data *data)
{
	t_pile_b	*tmp;

	if (data->size_b > 0)
	{
		tmp = data->pile_a;
		tmp->next = data->pile_b;
		data->pile_b = tmp;
		tmp = data->pile_a->next;
		free(data->pile_a);
		data->pile_a = tmp;
		free(tmp);
	}
	else if (data->size_b == 0)
	{
		tmp->i = data->pile_a->i;
		data->last_b = tmp;
		data->pile_b = tmp;
	}
}
