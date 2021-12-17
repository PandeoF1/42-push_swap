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

static void		solve_2(t_data *data)
{
	if (data->pile_a->i > data->pile_a->next->i)
		ft_sa(frame);
}

static void		solve_3(t_data *data)
{
	t_stack	*stack_a;
	t_stack	*tmp;

	find_biggest(frame, 'a');
	moves_to_end(frame, 'a', 2);
	if (BIG_RROTATE >= 1)
		while (BIG_RROTATE-- > 1)
			do_rra(frame);
	stack_a = frame->a;
	tmp = frame->a->next;
	if (stack_a->num > tmp->num)
		do_sa(frame);
}

static void		solve_4(t_data *data)
{
	t_stack *stack_a;

	stack_a = frame->a;
	find_biggest_smallest(frame, 'a');
	while (stack_a->num != SMALLEST)
	{
		do_ra(frame);
		stack_a = stack_a->next;
	}
	do_pb(frame);
	solve_3(frame);
	do_pa(frame);
}

static void		solve_5(t_data *data)
{
	t_stack *stack_a_end;
	t_stack	*tmp;
	int		flag;

	flag = 0;
	stack_a_end = frame->a->prev;
	median(frame, 'a');
	while (flag != 1)
	{
		frame->a == stack_a_end ? flag = 1 : 0;
		if (frame->a->num < MEDIAN)
			do_pb(frame);
		else
			do_ra(frame);
	}
	solve_3(frame);
	tmp = frame->b->next;
	frame->b->num < tmp->num ? do_sb(frame) : 0;
	do_pa(frame);
	do_pa(frame);
}

void			solve_5_or_less(t_data *data, int size)
{
	if (size == 2)
		solve_2(data);
	else if (size == 3)
		solve_3(data);
	else if (size == 4)
		solve_4(data);
	else if (size <= 5)
		solve_5(data);
}