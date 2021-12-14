/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:13:32 by tnard             #+#    #+#             */
/*   Updated: 2021/12/14 17:37:53 by tnard            ###   ########lyon.fr   */
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
	t_pile	*tmp;
	int		i;

	tmp = malloc(sizeof(t_pile));
	//check malloc
	if (data->size_b > 0)
	{
		tmp->i = data->pile_a->i;
		tmp->next = data->pile_b;
		data->pile_b = tmp;
		tmp = data->pile_a;
		data->pile_a = data->pile_a->next;
		free(tmp);
	}
	else if (data->size_b == 0)
	{
		tmp->i = data->pile_a->i;
		data->pile_b = tmp;
		data->pile_b->next = NULL;
		tmp = data->pile_a;
		data->pile_a = data->pile_a->next;
		data->last_b = data->pile_b;
		free(tmp);
	}
	data->size_b++;
	data->size_a--;
	ft_printf("pb\n");
}
