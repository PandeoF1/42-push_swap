/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:44:00 by asaffroy          #+#    #+#             */
/*   Updated: 2021/12/17 15:37:07 by asaffroy         ###   ########lyon.fr   */
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
	return (new_c);
}

t_chunk	*last_nmb_c(t_chunk *list)
{
	if (!list)
		return (list);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void	add_nmb_c(t_data *data, int	*tab, int i)
{
	t_chunk			*new;

	new = new_nmb_c(tab, i);
	if (new == NULL)
		return ;
	if (data->a == 0)
	{
		ft_printf("juehcue3hcje3bcub\n");
		ft_printf("juehcue3hcje3bcub\n");
		data->chunk = new;
		data->a++;
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
	int		i;

	i = 0;
	add_nmb_c(data, ft_chunk2(data, &i), i);
	data->nb_chunk++;
}
