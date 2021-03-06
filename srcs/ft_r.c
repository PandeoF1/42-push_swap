/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:16:51 by tnard             #+#    #+#             */
/*   Updated: 2021/12/26 13:58:07 by tnard            ###   ########lyon.fr   */
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
	data->last_a = data->last_a->next;
	ft_printf("ra\n");
}

void	ft_rb(t_data *data)
{
	t_pile	*tmp;

	tmp = data->pile_b->next;
	data->last_b->next = data->pile_b;
	data->last_b->next->next = NULL;
	data->pile_b = tmp;
	data->last_b = data->last_b->next;
	ft_printf("rb\n");
}

void	ft_rra(t_data *data)
{
	int		x;
	t_pile	*tmp;

	x = 0;
	while (x < data->size_a - 1)
	{
		tmp = data->pile_a->next;
		data->last_a->next = data->pile_a;
		data->last_a->next->next = NULL;
		data->pile_a = tmp;
		data->last_a = data->last_a->next;
		x++;
	}
	ft_printf("rra\n");
}

void	ft_rrb(t_data *data)
{
	int		x;
	t_pile	*tmp;

	x = 0;
	while (x < data->size_b - 1)
	{
		tmp = data->pile_b->next;
		data->last_b->next = data->pile_b;
		data->last_b->next->next = NULL;
		data->pile_b = tmp;
		data->last_b = data->last_b->next;
		x++;
	}
	ft_printf("rrb\n");
}

void	ft_rrr(t_data *data)
{
	int		x;
	t_pile	*tmp;
	t_pile	*tmp2;

	x = 0;
	while (x < data->size_a - 1)
	{
		tmp = data->pile_a->next;
		data->last_a->next = data->pile_a;
		data->last_a->next->next = NULL;
		data->pile_a = tmp;
		data->last_a = data->last_a->next;
		x++;
	}
	x = 0;
	while (x < data->size_b - 1)
	{
		tmp2 = data->pile_b->next;
		data->last_b->next = data->pile_b;
		data->last_b->next->next = NULL;
		data->pile_b = tmp2;
		data->last_b = data->last_b->next;
		x++;
	}
	ft_printf("rrr\n");
}
