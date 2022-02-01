/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:19:01 by lyaiche           #+#    #+#             */
/*   Updated: 2022/02/01 16:18:53 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_letter	letter;

void	bit_operation(int sig, siginfo_t *info, void *act)
{
	(void)sig;
	(void)info;
	(void)act;

	letter.index++;
	letter.letter <<= 1;
	if (letter.bit)
	{
		if (letter.index % 8 == 0)
		{
			if (letter.letter == '\0')
				kill(info->si_pid, SIGUSR1);
			else
				write(1, &letter.letter, 1);
			letter.letter = 0;
		}
	}
	else if (!letter.bit)
	{
		letter.letter |= 1;
		if (letter.index % 8 == 0)
		{
			write(1, &letter.letter, 1);
			letter.letter = 0;
		}
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	bit;
	int					sig;

	bit.sa_sigaction = bit_operation;
	bit.sa_flags = SA_SIGINFO;
	ft_putnbr(getpid());
	write(1, "\n", 1);
	pause();
	letter.bit = 0;
	sig = sigaction(SIGUSR1, &bit, NULL);
	if (!sig)
		write(2, "signal error\n", 13);
	letter.bit = 1;
	sig = sigaction(SIGUSR2, &bit, NULL);
	if (!sig)
		write(2, "signal error\n", 13);
	letter.index = 0;
	letter.letter = 0;
	while (1)
	{
	}
}
