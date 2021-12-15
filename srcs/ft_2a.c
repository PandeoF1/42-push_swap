/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:31:08 by asaffroy          #+#    #+#             */
/*   Updated: 2021/12/15 13:48:29 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_2a(t_data *data)
{
	int	temp_i;

	if (data->pile_a->i > data->pile_a->next->i)
	{
		temp_i = data->pile_a->i;
		data->pile_a->i = data->pile_a->next->i;
		data->pile_a->next->i = temp_i;
		ft_printf("ra\n");
	}
	return ;
}
