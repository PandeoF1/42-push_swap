/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:34:44 by asaffroy          #+#    #+#             */
/*   Updated: 2021/12/12 05:03:59 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*ft_sort_tab(int *str, int size)
{
	int	i;
	int	temp;
	int	*tab;

	i = -1;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (0);
	while (++i < size)
		tab[i] = str[i];
	i = 0;
	while (i < size)
	{
		if ((i + 1) < size && (tab[i + 1] < tab[i]))
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = -1;
		}
		i++;
	}
	return (tab);
}
