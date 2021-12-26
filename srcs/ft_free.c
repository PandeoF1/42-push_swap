/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:05:12 by tnard             #+#    #+#             */
/*   Updated: 2021/12/26 13:57:50 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <limits.h>

int	ft_atoie(const char *str)
{
	long	i;
	long	nbr;
	int		revert;

	i = 0;
	nbr = 0;
	revert = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && str[i] == '-')
		revert = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		if (revert)
			nbr = (nbr * 10) - (str[i++] - '0');
		else
			nbr = (nbr * 10) + (str[i++] - '0');
	}
	if (nbr > INT_MAX || nbr < INT_MIN)
		exit(ft_printf("", ft_printf("Error : INT LIMIT !\n")));
	return (nbr);
}

void	ft_free(t_data *data, int a)
{
	t_pile		*tmp;

	while (data->pile_a)
	{
		tmp = data->pile_a;
		data->pile_a = data->pile_a->next;
		free(tmp);
	}
	while (data->pile_b && a)
	{
		tmp = data->pile_b;
		data->pile_b = data->pile_b->next;
		free(tmp);
	}
}
