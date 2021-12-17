/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:13:32 by tnard             #+#    #+#             */
/*   Updated: 2021/12/17 12:09:42 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pa(t_data *data)
{
	t_pile	*tmp;

	tmp = malloc(sizeof(t_pile));
	if (!tmp)
		return ;
	if (data->size_a > 0)
	{
		tmp->i = data->pile_b->i;
		tmp->next = data->pile_a;
		data->pile_a = tmp;
		tmp = data->pile_b;
		data->pile_b = data->pile_b->next;
	}
	else if (data->size_a == 0)
	{
		tmp->i = data->pile_b->i;
		data->pile_a = tmp;
		data->pile_a->next = NULL;
		tmp = data->pile_b;
		data->pile_b = data->pile_b->next;
		data->last_a = data->pile_a;
	}
	free(tmp);
	ft_printf("pa\n", data->size_a++, data->size_b--);
}

void	ft_pb(t_data *data)
{
	t_pile	*tmp;

	tmp = malloc(sizeof(t_pile));
	if (!tmp)
		return ;
	if (data->size_b > 0)
	{
		tmp->i = data->pile_a->i;
		tmp->next = data->pile_b;
		data->pile_b = tmp;
		tmp = data->pile_a;
		data->pile_a = data->pile_a->next;
	}
	else if (data->size_b == 0)
	{
		tmp->i = data->pile_a->i;
		data->pile_b = tmp;
		data->pile_b->next = NULL;
		tmp = data->pile_a;
		data->pile_a = data->pile_a->next;
		data->last_b = data->pile_b;
	}
	free(tmp);
	ft_printf("pb\n", data->size_b++, data->size_a--);
}
