/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasyaiche <lucasyaiche@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:00:41 by lyaiche           #+#    #+#             */
/*   Updated: 2022/02/02 02:21:42 by lucasyaiche      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	int		bit;
	char	*msg;

	if (argc != 3 || !check_pid(argv[1]))
		panic_button();
	pid = ft_atoi(argv[1]);
	i = -1;
	msg = argv[2];
	while (*msg)
	{
		bit = 8;
		while (--bit >= 0)
		{
			if ((*msg >> bit) & 1)
			{
				if (kill(pid, SIGUSR2) == -1)
					panic_button();
			}
			else
			{
				if (kill(pid, SIGUSR1) == -1)
					panic_button();
			}
			usleep(50);
		}
		msg++;
	}
}
