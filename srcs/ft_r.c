/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:16:51 by tnard             #+#    #+#             */
/*   Updated: 2021/12/14 17:42:56 by tnard            ###   ########lyon.fr   */
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
