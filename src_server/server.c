/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:19:01 by lyaiche           #+#    #+#             */
/*   Updated: 2022/01/31 15:15:55 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	struct sigaction	one;
	struct sigaction	zero;
	int					sig;

	one.sa_sigaction = bit_one;
	zero.sa_sigaction = bit_zero;
	one.sa_flags = SA_SIGINFO;
	one.sa_flags = SA_SIGINFO;
	ft_putnbr(getpid());
	sig = sigaction(SIGUSR1, &bit_one, NULL);
	if (!sig)
		panic_button();
	sig = sigaction(SIGUSR2, &bit_zero, NULL);
	if (!sig)
		panic_button();
	while (1)
	{
	}
}
