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
		data.max = sorted_tab[size - 1];
		ft_swap_radix(&data, sorted_tab, size, number);
		number = ft_update(&data, size);//leaks
		while (ft_is_sorted(number, size) == 0)
		{
			ft_swap_radix(&data, sorted_tab, size, number);
			number = ft_update(&data, size); //leaks
		}
		ft_free(&data);
		free(sorted_tab);
		free(number);
	}
	else if (argc > 2 && ft_check_mult_arg(argv, argc) == 1)
	{
		str = ft_argc_to_tab(argv, argc);
		strr = ft_split(str, ' ');
		number = ft_splittochar(strr, &size);
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
		data.max = sorted_tab[size - 1];
		ft_swap_radix(&data, sorted_tab, size, number);
		number = ft_update(&data, size);//leaks
		while (ft_is_sorted(number, size) == 0)
		{
			ft_swap_radix(&data, sorted_tab, size, number);
			number = ft_update(&data, size); //leaks
		}
		ft_free(&data);
		free(str);
		free(sorted_tab);
		x = 0;
		while (strr[x])
			free(strr[x++]);
		free(strr);
	}
	else
		ft_usage();
	return (0);
}
