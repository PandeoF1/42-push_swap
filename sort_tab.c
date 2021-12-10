/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:34:44 by asaffroy          #+#    #+#             */
/*   Updated: 2021/12/10 18:11:18 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

char	*ft_sort_tab(char *str)
{
	int		i;
	char	temp;
	char	*tab;

	i = -1;
	tab = malloc(sizeof(char) * ft_strlen(str));
	if (!tab)
		return (0);
	while (str[++i])
		tab[i] = str[i];
	i = 0;
	while (tab[i])
	{
		if (tab[i + 1] && (tab[i + 1] < tab[i]))
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
