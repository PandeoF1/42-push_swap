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
}

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
}

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
	data->nb_chunk = 0;
	return (x);
}

void	ft_swap2(t_data *data, int x)
{
	int		y;
	t_chunk	*tmp;
	t_chunk	*tmp1;
	int		i;
	int		*sorted_tab;
	while (data->size_b > 0)
	{
		y = 0;
		tmp = data->chunk;
		tmp1 = data->chunk;
		while (tmp->next)
		{
			y++;
			tmp = tmp->next;
		}
		if (y > 0)
			while (y-- - 1)
				tmp1 = tmp1->next;
		sorted_tab = ft_sort_tab(tmp->tab, tmp->size);
		y = sorted_tab[tmp->size / 2];
		data->len_chunk = tmp->size;
		data->nb_rb = 0;
		data->nb_ra = 0;
		data->nb_rb2 = 0;
		while (tmp->size > 0)
		{
			// ft_printf("mama\n");
			// ft_printf("size :%d\n", tmp->size);
			// ft_printf("tab : %d\n", tmp->tab[0]);
			i = 0;
			data->in_list = data->size_b - tmp->size;
			tmp->tab = ft_chunk2(data, &i);
			i = 0;
			if (ft_is_rev_sorted(tmp->tab, tmp->size) == 1 && data->nb_rb == 0)
			{
				while (i < tmp->size)
				{
					ft_pa(data);
					if (data->pile_a->i > data->pile_a->next->i)
						ft_sa(data);
					tmp->size--;
					// data->in_list = data->size_b - tmp->size;
					// tmp->tab = ft_chunk2(data, &i);
					i = 0;
				}
			}
			else if (tmp->size == 1 && data->nb_rb == 0)
			{
				ft_pa(data);
				tmp->size--;
			}
			else if (tmp->size == 2 && data->nb_rb == 0)
			{
				if (data->pile_b->i < data->pile_b->next->i)
					ft_sb(data);
				ft_pa(data);
				ft_pa(data);
				tmp->size -= 2;
			}
			else if (data->len_chunk == 0)
			{
				while (data->nb_rb > 0)
				{
					if (data->nb_chunk != 1)
						ft_rrb(data);
					data->nb_rb--;
				}
				data->in_list = data->size_b - tmp->size;
				tmp->tab = ft_chunk2(data, &i);
				free(sorted_tab);
				sorted_tab = ft_sort_tab(tmp->tab, tmp->size);
				y = sorted_tab[tmp->size / 2];
				data->len_chunk = tmp->size;
			}
			else
			{
				if (data->pile_b->i > y)
				{
					if (data->pile_b->next->i > data->pile_b->i)
					{
						while (data->pile_b->next->i > data->pile_b->i)
						{
							ft_sb(data);
							ft_pa(data);
							while (data->pile_a->i > data->pile_a->next->i)
							{
								if (data->pile_b->next->i > data->pile_b->i)
									ft_ss(data);
								else
									ft_sa(data);
								while (data->pile_a->next->next && (data->pile_a->next->next->i < data->pile_a->next->i))
								{
									ft_pb(data);
									ft_sa(data);
									data->nb_ra++;
								}
								while (data->nb_ra > 0)
								{
									ft_pa(data);
									data->nb_ra--;
								}
							}
							tmp->size--;
							data->len_chunk--;
						}
					}
					else
					{
						ft_pa(data);
						if (data->pile_a->i > data->pile_a->next->i)
							ft_sa(data);
						while (data->pile_a->next->next && (data->pile_a->next->next->i < data->pile_a->next->i))
						{
							ft_pb(data);
							if (data->size_b >= 2 && (data->pile_b->i < data->pile_b->next->i))
								ft_sb(data);
							ft_sa(data);
							data->nb_ra++;
						}
						while (data->nb_ra > 0)
						{
							ft_pa(data);
							if (data->pile_a->next && (data->pile_a->i > data->pile_a->next->i))
								ft_sa(data);
							data->nb_ra--;
						}
						tmp->size--;
						data->len_chunk--;
					}
				}
				else if (data->pile_b->i <= y)
				{
					ft_rb(data);
					data->len_chunk--;
					data->nb_rb++;
				}
			}
		}
		//free(tmp);
		//free(tmp->tab);
		tmp1->next = NULL;
		data->nb_chunk--;
		// if (data->nb_chunk != 0)
		// {
		// 	ft_printls(data);
		// 	ft_printchunk(data);
		// }
	}
}

void	ft_swap(t_data *data, int *number, int size, int *sorted_tab)
{
	int				mid;
	static int		x = 0;
	int				len_b;
	int				y;
	int				j;

	if (data->size_a == -1)
		x = ft_init(data, number, size);
	data->in_list = 0;
	data->len_chunk = 0;
	data->nb_chunk = 0;
	data->nb_rb = 0;
	data->a = 0;
	y = 0;
	y += ft_sorted_in_a(data, size);
	j = 0;
	while (y < data->size_a)
	{
		len_b = 0;
		//y = 0;//
		size = data->size_a / 2;
		mid = sorted_tab[size];
		while (len_b < size)
		{
			if (y != data->size_a)
			{
				if (data->pile_a->i < mid)
				{
					if (data->pile_a->i > data->pile_a->next->i)
					{
						while (data->pile_a->i > data->pile_a->next->i)
						{
							if (data->size_b >= 2 && (data->pile_b->i < data->pile_b->next->i))
								ft_ss(data);
							else
								ft_sa(data);
							ft_pb(data);
							len_b++;
						}
					}
					else
					{
						if (data->size_b >= 2 && (data->pile_b->i < data->pile_b->next->i))
							ft_sb(data);
						ft_pb(data);
						len_b++;
					}
				}
				else if (data->last_a->i < mid)
				{
					if (data->size_b >= 2 && data->pile_b->i < data->last_b->i)
						ft_rrr(data);
					else
						ft_rra(data);
				}
				else
				{
					if (data->pile_a->i >= mid)
					{
						if (data->size_b >= 2 && (data->pile_b->i < data->last_b->i))
							ft_rr(data);
						else
							ft_ra(data);
					}
				}
				//ft_printls(data);
				y = ft_sorted_in_a(data, data->size_a);//
			}
			else
				len_b++;
		}
		j = len_b;
		free(sorted_tab);
		sorted_tab = ft_sort_tab(ft_maketab(data), data->size_a);
		if (data->size_a == 2)
		{
			if (data->pile_a->i > data->pile_a->next->i)
				ft_ra(data);
			//ft_printls(data);
		}
		y = ft_sorted_in_a(data, data->size_a);//
		ft_chunk(data);
		//ft_printchunk(data);
	}
	free(sorted_tab);
	ft_swap2(data, x);
}

//if size_b plus grand < size_a qui arrive -> met plus petit de B en haut et pose le A dessus
//if size_a qui arrive < un des B -> trouve le B le plus grand le plus proche et met le plus petit au dessus

//push minimum ou maxi en haut ou bas en fonction de plus rapide