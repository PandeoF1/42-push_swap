/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:58:33 by tnard             #+#    #+#             */
/*   Updated: 2021/12/09 13:24:39 by tnard            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	ft_usage(void)
{
	ft_printf("usage: ./push_swap [numbers]\n");
	exit(0);
}

static int	ft_check_arg(char *str)
{
	int	x;

	x = -1;
	while (str[++x])
	{
		if (!ft_isdigit(str[x]))
			return (0);
		while (str[x] && ft_isdigit(str[x]))
			x++;
		if (!str[x])
			return (1);
		if (str[x] && str[x] != ' ')
			return (0); 
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc == 2 && ft_check_arg(argv[1]))
		ft_printf("gg");
		//ft_push_swap(argv[1]);
	else
		ft_usage();
	return (0);
}
