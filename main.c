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

int	ft_is_sorted(int *number, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (number[i] > number[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_rev_sorted(int *number, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (number[i] < number[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_sorted_in_a(t_data *data, int size)
{
	int	*tab;
	int	i;
	int	*number;

	number = ft_update(data, size);
	tab = ft_sort_tab(number, size);
	number = ft_update(data, size);
	i = 0;
	size--;
	if (number[size] == tab[size])
	{
		while (size >= 0 && number[size] == tab[size])
		{
			i++;
			size--;
		}
	}
	return (i);
}

static void	ft_usage(void)
{
	ft_printf("usage: ./push_swap [numbers]\n");
	exit(0);
}
/*
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
}*/

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
		if (str[x] == '-')
			x++;
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

char	*ft_argc_to_tab(char **argv, int argc)
{
	char	*str;
	int		x;
	int		y;

	x = 1;
	y = 0;
	while (x < argc)
		y += ft_strlen(argv[x++]) + 1;
	//ft_printf("%d\n", y);
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
	while (x < size)
	{
		//ft_printf("mh : %d\n", tmp->i);
		(number[x]) = tmp->i;
		//ft_printf("mh : %d\n", number[x]);
		tmp = tmp->next;
		x++;
	}
	return (number);
}

int	main(int argc, char *argv[])
{
	char		*str;
	char		**strr;
	int			*number;
	int			*sorted_tab;
	int			size = 10;
	int			x;
	t_data		data;
	t_pile		pile_a;
	t_pile		pile_b;
	t_chunk		chunk;

	data.pile_a = &pile_a;
	data.pile_b = &pile_b;
	data.chunk = &chunk;
	data.size_a = -1;
	x = 0;
	size = 0;
	if (argc == 2 && ft_strlen(argv[1]) && ft_check_one_arg(argv[1]) != 1
		&& ft_check_one_arg(argv[1]) != 0)
	{
		number = ft_splittochar(ft_split(argv[1], ' '), &size);
		// ft_printf("size : %d\ntab : ", size);
		// while (x < size)
		// 	ft_printf("%d ", number[x++]);
		// ft_printf("\n");
		if (ft_check_double(number, size) == 0)
		{
			ft_printf("Error : double numbers\n");
			return (0);
		}
		if (ft_is_sorted(number, size) == 1)
		{
			ft_printf("Error : sorted\n");
			return (0);
		}
		sorted_tab = ft_sort_tab(number, size);
//#################################je print juste mon tableau trié #####
		// ft_printf("sorted tab : ");
		// x = 0;
		// while (x < size)
		// 	ft_printf("%d ", sorted_tab[x++]);
		// ft_printf("\n");
//##################################FIN , t moche########################
		ft_swap(&data, number, size, sorted_tab);
		number = ft_update(&data, size);//leaks
		while (ft_is_sorted(number, size) == 0)
		{
			ft_swap(&data, number, size, sorted_tab);
			number = ft_update(&data, size); //leaks
		}
		ft_free(&data);
		free(number);
		x = 0;
		while (strr[x])
			free(strr[x++]);
		free(strr);
		//free(number);
	}
	else if (argc > 2 && ft_check_mult_arg(argv, argc) == 1)
	{
		str = ft_argc_to_tab(argv, argc);
		strr = ft_split(str, ' ');
		number = ft_splittochar(strr, &size);
		// ft_printf("size : %d\ntab : ", size);
		// while (x < size)
		// 	ft_printf("%d ", number[x++]);
		// ft_printf("\n");
		if (ft_check_double(number, size) == 0)
		{
			ft_printf("Error : double numbers\n");
			return (0);
		}
		if (ft_is_sorted(number, size) == 1)
		{
			ft_printf("Error : sorted\n");
			return (0);
		}
		sorted_tab = ft_sort_tab(number, size);
		//#################################je print juste mon tableau trié #####
		// ft_printf("sorted tab : ");
		// x = 0;
		// while (x < size)
		// 	ft_printf("%d ", sorted_tab[x++]);
		// ft_printf("\n");
		ft_swap(&data, number, size, sorted_tab);
		number = ft_update(&data, size);//leaks
		while (ft_is_sorted(number, size) == 0)
		{
			sorted_tab = ft_sort_tab(number, size);
			ft_swap(&data, number, size, sorted_tab);
			number = ft_update(&data, size); //leaks
		}
		ft_free(&data);
		free(str);
		x = 0;
		while (strr[x])
			free(strr[x++]);
		free(strr);
		//free(number);
	}
	else
		ft_usage();
	return (0);
}
