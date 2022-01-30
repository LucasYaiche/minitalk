/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasyaiche <lucasyaiche@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:19:01 by lyaiche           #+#    #+#             */
/*   Updated: 2022/01/30 16:54:48 by lucasyaiche      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	struct sigaction	one;
	struct sigaction	zero;
	char				i;

	one.sa_sigaction = bit_one;
	zero.sa_sigaction = bit_zero;
	one.sa_flags = SA_SIGINFO;
	one.sa_flags = SA_SIGINFO;
	ft_putnbr(getpid());
	
}
