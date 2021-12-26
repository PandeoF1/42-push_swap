/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:08:08 by tnard             #+#    #+#             */
/*   Updated: 2021/12/17 11:08:08 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	solve_2(t_data *data)
{
	if (data->pile_a->i > data->pile_a->next->i)
		ft_printf("sa\n");
}

static void	solve_3(t_data *data)
{
	if (data->pile_a->i > data->pile_a->next->i
		&& data->pile_a->next->i > data->pile_a->next->next->i)
	{
		ft_sa(data);
		ft_ra(data);
		ft_ra(data);
	}
	else if (data->pile_a->i > data->pile_a->next->next->i
		&& data->pile_a->i < data->pile_a->next->i)
		ft_rra(data);
	else if (data->pile_a->i > data->pile_a->next->next->i)
	{
		ft_ra(data);
		if (data->pile_a->next->i > data->pile_a->next->next->i)
			ft_ra(data);
	}
	else if (data->pile_a->i < data->pile_a->next->next->i)
	{
		ft_sa(data);
		if (data->pile_a->next->i > data->pile_a->next->next->i
			|| data->pile_a->i > data->pile_a->next->next->i)
			ft_ra(data);
	}
}

static void	ft_push_b_min(t_data *data)
{
	int		min;
	t_pile	*tmp;

	min = data->pile_a->i;
	tmp = data->pile_a;
	while (tmp)
	{
		if (min > tmp->i)
			min = tmp->i;
		else
			tmp = tmp->next;
	}
	tmp = data->pile_a;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->i == min)
		ft_rra(&(*data));
	else
		while (data->pile_a->i != min)
			ft_ra(&(*data));
	ft_pb(&(*data));
}

static void	solve_5(t_data *data, int size)
{
	int	x;

	x = size;
	while (x-- > 3)
		ft_push_b_min(&(*data));
	if (data->pile_a->i < data->pile_a->next->i
		&& data->pile_a->next->i < data->pile_a->next->next->i)
	{
		while (x++ < size - 1)
			ft_pa(&(*data));
	}
	else
		solve_3(&(*data));
	while (x++ < size - 1)
		ft_pa(&(*data));
}

void	ft_sort(t_main *main, t_data *data)
{
	ft_init(data, main->number, main->size);
	main->a = 0;
	if (main->size == 2)
		solve_2(&(*data));
	else if (main->size == 3)
		solve_3(&(*data));
	else if (main->size <= 5)
		solve_5(&(*data), main->size);
	return ;
}
