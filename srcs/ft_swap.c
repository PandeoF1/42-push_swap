/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:14:58 by asaffroy          #+#    #+#             */
/*   Updated: 2021/12/12 18:14:58 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*
static void	ft_printchunk(t_data *data)
{
	t_chunk	*tmp;
	int		x;

	tmp = data->chunk;
	while (tmp)
	{
		x = 0;
		ft_printf("Chunk (%d): ", tmp->size);
		while (x < tmp->size)
		{
			ft_printf("%d ", tmp->tab[x]);
			x++;
		}
		ft_printf("\n");
		tmp = tmp->next;
	}
	ft_printf("\n");
}*/
/*
static void	ft_printls(t_data *date)
{
	t_pile	*tmp;
	char	*str1;
	char	*str2;
	char	**split1;
	char	**split2;
	int		a;
	int		b;
	int		x;
	int		y;
	int		z;

	a = 0;
	b = 0;
	x = 0;
	y = 0;
	tmp = date->pile_a;
	str1 = ft_strdup(ft_itoa(tmp->i));
	tmp = tmp->next;
	while (tmp)
	{
		str1 = ft_strjoin(str1, " ");
		str1 = ft_strjoin(str1, ft_itoa(tmp->i));
		tmp = tmp->next;
	}
	tmp = date->pile_b;
	str2 = ft_strdup(ft_itoa(tmp->i));
	tmp = tmp->next;
	while (tmp)
	{
		str2 = ft_strjoin(str2, " ");
		str2 = ft_strjoin(str2, ft_itoa(tmp->i));
		tmp = tmp->next;
	}
	ft_printf("\n");
	ft_printf("     TAB\n");
	ft_printf("┌───────────┐\n");
	ft_printf("│  A  │  B  │\n");
	ft_printf("│     │     │\n");
	split1 = ft_split(str1, ' ');
	split2 = ft_split(str2, ' ');
	while (split1[a])
		a++;
	while (split2[b])
		b++;
	while (x < a || y < b)
	{
		z = 0;
		ft_printf("│  ");
		if (x < a)
			ft_printf("%s", split1[x++]);
		else
			ft_printf("x");
		ft_printf("  │  ");
		if (y < b)
			ft_printf("%s", split2[y++]);
		else
			ft_printf("x");
		ft_printf("  │\n");
	}
	ft_printf("└───────────┘\n");
}*/

static int	*ft_maketab(t_data *data)
{
	t_pile	*tmp;
	int		*tab;
	int		i;

	i = 0;
	tmp = data->pile_a;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	tab = malloc(sizeof(int) * i);
	if (!tab)
		return (NULL);
	tmp = data->pile_a;
	i = 0;
	while (tmp)
	{
		tab[i] = tmp->i;
		tmp = tmp->next;
		i++;
	}
	return (tab);
}

static int	ft_init(t_data *data, int *number, int size)
{
	int		x;

	x = -1;
	while (++x < size)
		add_nmb_a(data, number[x]);
	data->size_a = x;
	data->size_b = 0;
	data->last_a = data->pile_a;
	while (data->last_a->next)
		data->last_a = data->last_a->next;
	data->pile_b->next = NULL;
	data->in_list = 0;
	return (x);
}
/*
void	ft_swap2(data)
{

}
*/
void	ft_swap(t_data *data, int *number, int size, int *sorted_tab)
{
	int				mid;
	int				x;
	int				len_b;
	int				y;

	x = ft_init(data, number, size);
	y = 0;
	while (y < (x - 2))
	{
		len_b = 0;
		size = data->size_a / 2;
		mid = sorted_tab[size];
		while (len_b < size)
		{
			if (data->pile_a->i < mid)
			{
				ft_pb(data);
				len_b++;
			}
			else if (data->last_a->i < mid)
				ft_rra(data);
			else
			{
				if (data->pile_a->i >= mid)
					ft_ra(data);
			}
			//ft_printls(data);
		}
		y += len_b;
		free(sorted_tab);
		sorted_tab = ft_maketab(data);
		sorted_tab = ft_sort_tab(sorted_tab, data->size_a);
		if (data->size_a == 2)
		{
			if (data->pile_a->i > data->pile_a->next->i)
				ft_ra(data);
			//ft_printls(data);
		}
		ft_chunk(data);
		//ft_printchunk(data);
	}
	//ft_swap2(data);
}
