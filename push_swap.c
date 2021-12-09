/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:58:33 by tnard             #+#    #+#             */
/*   Updated: 2021/12/09 15:49:46 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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
	if (str[i] != ' ' || str[i] == '\0')
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
	int	n_double[OPEN_MAX + 1];

	x = -1;
	while (str[++x])
	{
		if (!ft_isdigit(str[x]))
			return (0);
		while (str[x] && (ft_atoi_check(str + x)))
		{
			ft_printf("Je suis sur : %c\n", str[x]);
			if (!n_double[ft_atoi(str + x)])
				n_double[ft_atoi(str + x)] = 0;
			else
				return (0);
			x++;
			if (str[x] && ft_space_len(str + x) == 1)
				x++;
			else if (str[x] && ft_space_len(str + x) == 0 && !str[x + 1])
				return (1);
		}
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc == 2 && ft_check_one_arg(argv[1]))
		ft_printf("gg");
		//ft_push_swap(argv[1]);
	//else if (argc > 2 && ft_check_args(argc, argv))
		//ft_printf("gg");
		//ft_push_swap(argc, argv);
	//else
	//	ft_usage();
	return (0);
}
