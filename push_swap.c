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

static int	ft_check_mult_arg(char **argv, int argc)
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
		number[(*y)] = ft_atoi(str[(*y)]);
		(*y)++;
	}
	return (number);
}

char	*ft_argc_to_tab(char **argv, int argc, int *size)
{
	char	*str;
	int		x;

	x = 2;
	str = ft_strdup(argv[1]);
	while (x < argc && argv[x])
	{
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, argv[x]);
		x++;
	}
	return (str);
}

int	ft_check_double(int *number, int size)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			if (x != y && number[x] == number[y])
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int			*number;
	int			*sorted_tab;
	int			size;
	int			x;
	t_data		data;
	t_pile	pile_a;
	t_pile	pile_b;

	data.pile_a = &pile_a;
	data.pile_b = &pile_b;
	x = 0;
	size = 0;
	if (argc == 2 && ft_strlen(argv[1]) && ft_check_one_arg(argv[1]) != 1
		&& ft_check_one_arg(argv[1]) != 0)
	{
		number = ft_splittochar(ft_split(argv[1], ' '), &size);
		ft_printf("size : %d\ntab : ", size);
		while (x < size)
			ft_printf("%d ", number[x++]);
		ft_printf("\n");
		if (ft_check_double(number, size) == 0)
		{
			ft_printf("Error : double numbers\n");
			return (0);
		}


		sorted_tab = ft_sort_tab(number, size);
//#################################je print juste mon tableau trié #####
		ft_printf("sorted tab : ");
		x = 0;
		while (x < size)
			ft_printf("%d ", sorted_tab[x++]);
		ft_printf("\n");
//##################################FIN , t moche########################
		ft_swap(&data, number, size, sorted_tab);
		free(number);
	}
	else if (argc > 2 && ft_check_mult_arg(argv, argc) == 1)
	{
		number = ft_splittochar(ft_split(ft_argc_to_tab(argv, argc, &size), ' '), &size);
		ft_printf("size : %d\ntab : ", size);
		while (x < size)
			ft_printf("%d ", number[x++]);
		ft_printf("\n");
		if (ft_check_double(number, size) == 0)
		{
			ft_printf("Error : double numbers\n");
			return (0);
		}

		sorted_tab = ft_sort_tab(number, size);
//#################################je print juste mon tableau trié #####
		ft_printf("sorted tab : ");
		x = 0;
		while (x < size)
			ft_printf("%d ", sorted_tab[x++]);
		ft_printf("\n");
//##################################FIN , t moche########################
		ft_swap(&data, number, size, sorted_tab);
		free(number);
		// ton code ici
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
