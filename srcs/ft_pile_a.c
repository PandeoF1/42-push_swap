/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:59:00 by asaffroy          #+#    #+#             */
/*   Updated: 2021/12/13 20:13:30 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_pile	*new_nmb_a(int nmb)
{
	t_pile	*new_a;

	new_a = malloc(sizeof(t_pile));
	if (new_a == NULL)
	{
		ft_printf("ERROR\nmalloc of struct nmb failed\n");
		exit(EXIT_FAILURE);
	}
	new_a->i = nmb;
	new_a->next = NULL;
	return (new_a);
}

t_pile	*last_nmb_a(t_pile *list)
{
	if (!list)
		return (list);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void	add_nmb_a(t_data *data, int nmb)
{
	static int		a = 0;
	t_pile			*new;

	new = new_nmb_a(nmb);
	if (new == NULL)
		return ;
	if (a == 0)
	{
		data->pile_a = new;
		a++;
	}
	else
		last_nmb_a(data->pile_a)->next = new;
	free(new);
}
