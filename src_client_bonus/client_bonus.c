/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:00:41 by lyaiche           #+#    #+#             */
/*   Updated: 2022/03/21 15:57:57 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	reception(int sig, siginfo_t *info, void *act)
{
	(void)sig;
	(void)info;
	(void)act;
	write(1, "message received \n", 19);
}

void	send_bit(int pid, char c)
{
	int	bit;

	bit = 8;
	while (--bit >= 0)
	{
		if ((c >> bit) & 1)
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
}

int	main(int argc, char **argv)
{
	int					pid;
	char				*msg;
	struct sigaction	message;

	message.sa_sigaction = reception;
	message.sa_flags = SA_SIGINFO;
	if ((sigaction(SIGUSR1, &message, NULL)) == -1)
		write(2, "signal error\n", 13);
	if (argc != 3 || !check_pid(argv[1]))
	{
		write(2, "argument error\n", 15);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	while (*msg)
	{
		send_bit(pid, *msg);
		msg++;
	}
	send_bit(pid, *msg);
}
