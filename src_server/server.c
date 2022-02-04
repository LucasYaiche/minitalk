/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:19:01 by lyaiche           #+#    #+#             */
/*   Updated: 2022/02/04 11:25:54 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_letter	g_letter;

void	bit_one(int sig, siginfo_t *info, void *act)
{
	(void)sig;
	(void)info;
	(void)act;
	g_letter.index++;
	g_letter.letter <<= 1;
	g_letter.letter |= 1;
	if (g_letter.index % 8 == 0)
	{
		write(1, &g_letter.letter, 1);
		g_letter.index = 0;
		g_letter.letter = 0;
	}
}

void	bit_zero(int sig, siginfo_t *info, void *act)
{
	(void)sig;
	(void)info;
	(void)act;
	g_letter.index++;
	g_letter.letter <<= 1;
	if (g_letter.index % 8 == 0)
	{
		if (g_letter.letter == '\0')
		{
			write(1, "\nmessage :\n", 11);
			if (kill(info->si_pid, SIGUSR1))
				panic_button();
		}
		else
		{
			write(1, &g_letter.letter, 1);
			g_letter.index = 0;
			g_letter.letter = 0;
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
	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\nmessage :\n", 11);
	while (1)
		pause();
}
