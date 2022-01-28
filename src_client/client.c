/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:00:41 by lyaiche           #+#    #+#             */
/*   Updated: 2022/01/28 14:26:28 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;
	// int	j;
	int	i;

	if (argc < 3 || !check_pid(argv[1]))
		arg_error();
	pid = ft_atoi(argv[1]);
	i = 2;
	// while (*argv[++i])
	// {
	// 	j = -1;
	// 	while (argv[i][++j])
	// 	{
			
	// 	}
	// }
}
