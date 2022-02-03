/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:19:01 by lyaiche           #+#    #+#             */
/*   Updated: 2022/02/03 17:12:04 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_letter	letter;

void	bit_one(int sig, siginfo_t *info, void *act)
{
	(void)sig;
	(void)info;
	(void)act;
	letter.index++;
	letter.letter <<= 1;
	letter.letter |= 1;
	if (letter.index % 8 == 0)
	{
		write(1, &letter.letter, 1);
		letter.index = 0;
		letter.letter = 0;
	}
}

void	bit_zero(int sig, siginfo_t *info, void *act)
{
	(void)sig;
	(void)info;
	(void)act;
	letter.index++;
	letter.letter <<= 1;
	if (letter.index % 8 == 0)
	{
		if (letter.letter == '\0')
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		else
		{
			write(1, &letter.letter, 1);
			letter.index = 0;
			letter.letter = 0;
		}
	}
}

int	main(void)
{
	struct sigaction	one;
	struct sigaction	zero;

	one.sa_sigaction = bit_one;
	zero.sa_sigaction = bit_zero;
	one.sa_flags = SA_SIGINFO;
	zero.sa_flags = SA_SIGINFO;
	if ((sigaction(SIGUSR2, &one, NULL)) == -1)
		write(2, "signal error\n", 13);
	if ((sigaction(SIGUSR1, &zero, NULL)) == -1)
		write(2, "signal error\n", 13);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
}
