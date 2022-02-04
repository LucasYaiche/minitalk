/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 13:13:14 by lyaiche           #+#    #+#             */
/*   Updated: 2022/02/04 11:24:24 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	test(long long nb, const char *str, int sign)
{
	long long	limit;

	limit = (nb * 10 + *str - 48) * sign;
	if (limit < -2147483648)
		return (0);
	else if (limit > 2147483647)
		return (-1);
	return (1);
}

int	ft_atoi(char *num)
{
	int	negative;
	int	answer;

	answer = 0;
	negative = 1;
	while (*num == ' ' || *num == '\n' || *num == '\t' || *num == '\v'
		|| *num == '\f' || *num == '\r')
		num++;
	if (*num == '-' || *num == '+')
	{
		if (*num == '-')
			negative *= -1;
		num++;
	}
	while (*num >= 48 && *num <= 57)
	{
		if (!test(answer, num, negative))
			return (0);
		else if (test(answer, num, negative) == -1)
			return (-1);
		answer = answer * 10 + (*num - 48);
		num++;
	}
	return (answer * negative);
}
