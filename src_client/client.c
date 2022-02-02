/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:00:41 by lyaiche           #+#    #+#             */
/*   Updated: 2022/02/02 16:59:21 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	int		bit;
	char	*msg;
	struct sigaction	breakpoint;

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
				// write(1, "oui 1\n", 7);
				if (kill(pid, SIGUSR2) == -1)
					panic_button();
			}
			else
			{
				// write(1, "oui 0\n", 7);
				if (kill(pid, SIGUSR1) == -1)
					panic_button();
			}
			while (sigaction(SIGUSR2, &breakpoint, NULL) != 0)
				pause();
		}
		msg++;
	}
}
