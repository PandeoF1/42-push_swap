/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:05:12 by tnard             #+#    #+#             */
/*   Updated: 2021/12/24 10:08:36 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free(t_data *data)
{
	t_pile		*tmp;
	t_chunk		*tmp1;

	while (data->pile_a)
	{
		tmp = data->pile_a;
		data->pile_a = data->pile_a->next;
		free(tmp);
	}
	while (data->pile_b)
	{
		tmp = data->pile_b;
		data->pile_b = data->pile_b->next;
		free(tmp);
	}
	// while (data->chunk)
	// {
	// 	tmp1 = data->chunk;
	// 	data->chunk = data->chunk->next;
	// 	//free(tmp1->tab);
	// 	free(tmp1);
	// }
}
