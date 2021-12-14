/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:00:11 by asaffroy          #+#    #+#             */
/*   Updated: 2021/12/13 19:51:16 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_pile	*new_nmb_b(int nmb)
{
	t_pile	*pile_b;

	pile_b = malloc(sizeof(t_pile));
	if (pile_b == NULL)
	{
		ft_printf("ERROR\nmalloc of struct nmb failed\n");
		exit(EXIT_FAILURE);
	}
	pile_b->i = nmb;
	pile_b->next = NULL;
	pile_b->prev = NULL;
	return (pile_b);
}

t_pile	*last_nmb_b(t_pile *list)
{
	t_pile	*temp;

	if (!list)
		return (list);
	while (list->next)
	{
		temp = list;
		list = list->next;
		list->prev = temp;
	}
	return (list);
}

void	add_nmb_b(t_data *data, int nmb)
{
	static int		a = 0;
	t_pile		*new;

	new = new_nmb_b(nmb);
	if (new == NULL)
		return ;
	if (a == 0)
	{
		data->pile_b = new;
		a++;
	}
	else
		last_nmb_b(data->pile_b)->next = new;
}
