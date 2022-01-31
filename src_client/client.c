/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:00:41 by lyaiche           #+#    #+#             */
/*   Updated: 2022/01/31 15:43:50 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	int	bit;

	if (argc != 3 || !check_pid(argv[1]))
		arg_error();
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		bit = -1;
		while(++bit <= 7)
			if ()
	}
}
