/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:22:44 by asaffroy          #+#    #+#             */
/*   Updated: 2021/12/26 13:58:26 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_int_len(int x)
{
	int	y;

	y = 0;
	if (x > 0)
	{
		if (x > 9)
			y += ft_int_len(x / 10);
		y++;
	}
	return (y);
}

void	ft_usage(void)
{
	ft_printf("usage: ./push_swap [numbers]\n");
	exit(0);
}

int	ft_space_len(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] == ' ')
			x++;
		else
			return (x);
	}
	return (x);
}

int	*ft_splittochar(char **str, int *y)
{
	int		*number;

	(*y) = 0;
	while (str[(*y)])
		(*y)++;
	number = malloc(sizeof(int) * (*y));
	(*y) = 0;
	while (str[(*y)])
	{
		number[(*y)] = ft_atoie(str[(*y)]);
		(*y)++;
	}
	return (number);
}

char	*ft_strcat(char *dest, char *src)
{
	int	n;
	int	a;

	n = 0;
	a = 0;
	while (dest[n])
		n++;
	while (src[a])
		dest[n++] = src[a++];
	dest[n] = '\0';
	return (dest);
}
