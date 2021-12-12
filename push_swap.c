/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:58:33 by tnard             #+#    #+#             */
/*   Updated: 2021/12/12 05:19:27 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	ft_int_len(int x)
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

static void	ft_usage(void)
{
	ft_printf("usage: ./push_swap [numbers]\n");
	exit(0);
}

static int	ft_atoi_check(char *str)
{
	long	i;
	long	nbr;

	i = 0;
	nbr = 0;
	if (str[i] != '\0' && str[i] == '-')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		nbr = (nbr * 10) + (str[i++] - '0');
	if (str[i] != ' ' && str[i] != '\0')
		return (0);
	return (1);
}

static int	ft_space_len(char *str)
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

static int	ft_check_one_arg(char *str)
{
	int	x;
	int	b;

	x = 0;
	b = 0;
	while (str[x])
	{
		if (ft_isdigit(str[x]))
		{
			if (str[x] == '0')
				x++;
			else
				x += ft_int_len(ft_atoi(str + x));
			b++;
		}
		else if (str[x] == ' ')
			x++;
		else
			return (0);
	}
	return (b);
}

int *ft_splittochar(char **str, int *y)
{
	int		*number;

	(*y) = 0;
	while (str[(*y)])
		(*y)++;
	number = malloc(sizeof(int) * (*y));
	(*y) = 0;
	while (str[(*y)])
	{
		number[(*y)] = ft_atoi(str[(*y)]);
		(*y)++;
	}
	return (number);
}

int	main(int argc, char *argv[])
{
	int	*number;
	int	size;
	int	x;

	x = 0;
	size = 0;
	if (argc == 2 && ft_strlen(argv[1]) && ft_check_one_arg(argv[1]) != 1 && ft_check_one_arg(argv[1]) != 0)
	{
		number = ft_splittochar(ft_split(argv[1], ' '), &size);
		ft_printf("size : %d\ntab : ", size);
		while (x < size)
			ft_printf("%d ", number[x++]);
		ft_printf("\n");
//##################################################je print juste mon tableau trié ###############################################################################
		ft_printf("sorted tab : ");
		x = 0;
		while (x < size)
			ft_printf("%d ", ft_sort_tab(number, size)[x++]);
		ft_printf("\n");
//##################################################FIN , t moche###############################################################################
		free(number);
	}
	else
		ft_usage();
		//ft_push_swap(argv[1]);
	//else if (argc > 2 && ft_check_args(argc, argv))
		//ft_printf("gg");
		//ft_push_swap(argc, argv);
	//else
	//	ft_usage();
	return (0);
}
