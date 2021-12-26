/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:32:57 by asaffroy          #+#    #+#             */
/*   Updated: 2021/12/26 01:08:20 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_one_arg(char *str)
{
	int	x;
	int	b;

	x = 0;
	b = 0;
	while (str[x])
	{
		if (str[x] == '-')
			x++;
		if (ft_isdigit(str[x]))
		{
			if (str[x] == '0')
				x++;
			else
				x += ft_int_len(ft_atoie(str + x));
			b++;
		}
		else if (str[x] == ' ')
			x++;
		else
			return (0);
	}
	return (b);
}

int	ft_check_mult_arg(char **argv, int argc)
{
	int	x;
	int	b;

	x = 1;
	b = 0;
	while (x < argc)
	{
		if (ft_check_one_arg(argv[x]) == 0)
			return (0);
		x++;
	}
	return (1);
}

char	*ft_argc_to_tab(char **argv, int argc)
{
	char	*str;
	int		x;
	int		y;

	x = 1;
	y = 0;
	while (x < argc)
		y += ft_strlen(argv[x++]) + 1;
	str = malloc(sizeof(char) * (y) + 1);
	str[0] = '\0';
	x = 1;
	while (x < argc)
	{
		ft_strcat(str, argv[x]);
		ft_strcat(str, " ");
		x++;
	}
	return (str);
}

int	*ft_update(t_data *data, int size)
{
	t_pile	*tmp;
	int		*number;
	int		x;

	x = 0;
	number = malloc(sizeof(int) * (size));
	if (!number)
		return (NULL);
	tmp = data->pile_a;
	while (x < size - 1)
	{
		(number[x]) = tmp->i;
		tmp = tmp->next;
		x++;
	}
	return (number);
}

int	ft_first_sort(char **data)
{
	int	x;
	int	z;

	x = 0;
	z = -1;
	while (data[x])
		x++;
	while (++z < x - 1)
		if (ft_atoie(data[z]) > ft_atoie(data[z + 1]))
			return (0);
	return (1);
}
