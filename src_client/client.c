/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasyaiche <lucasyaiche@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:00:41 by lyaiche           #+#    #+#             */
/*   Updated: 2022/01/30 16:50:38 by lucasyaiche      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void	handle_sigusr1(int )

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3 || !check_pid(argv[1]))
		arg_error();
	pid = ft_atoi(argv[1]);
}
