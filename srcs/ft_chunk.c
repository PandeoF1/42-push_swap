/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:44:00 by asaffroy          #+#    #+#             */
/*   Updated: 2021/12/15 12:27:54 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_chunk	*new_nmb_c(int *tab, int i)
{
	t_chunk	*new_c;

	new_c = malloc(sizeof(t_chunk));
	if (new_c == NULL)
	{
		ft_printf("ERROR\nmalloc of struct nmb failed\n");
		exit(EXIT_FAILURE);
	}
	new_c->tab = tab;
	new_c->size = i;
	new_c->next = NULL;
	ft_printf("size here : %d\n", new_c->size);
	return (new_c);
}

t_chunk	*last_nmb_c(t_chunk *list)
{
	t_chunk	*temp;

	if (!list)
		return (list);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void	add_nmb_c(t_data *data, int	*tab, int i)
{
	static int		a = 0;
	t_chunk			*new;

	new = new_nmb_c(tab, i);
	if (new == NULL)
		return ;
	if (a == 0)
	{
		data->chunk = new;
		a++;
	}
	else
		last_nmb_c(data->chunk)->next = new;
}

int	*ft_chunk2(t_data *data, int *i)
{
	t_pile	*tmp;
	int		*tab;
	int		a;

	a = 0;
	tmp = data->pile_b;
	while (tmp)
	{
		tmp = tmp->next;
		(*i)++;
	}
	(*i) -= data->in_list;
	tab = malloc(sizeof(int) * (*i));
	if (!tab)
		return (NULL);
	tmp = data->pile_b;
	while (a < (*i))
	{
		tab[a] = tmp->i;
		tmp = tmp->next;
		a++;
	}
	data->in_list += (*i);
	return (tab);
}

void	ft_chunk(t_data *data)
{
	int		*tab;
	int		x;
	int		i;

	x = 0;
	i = 0;
	data->chunk->size = 0;
	tab = ft_chunk2(data, &i);
	while (x < 3)
	{
		ft_printf("tyuvbgvg : %d\n", tab[x]);
		x++;
	}
	add_nmb_c(data, ft_chunk2(data, &i), i);
}
