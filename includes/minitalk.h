/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:48:15 by lyaiche           #+#    #+#             */
/*   Updated: 2022/02/01 14:36:50 by lyaiche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_letter
{
	char	letter;
	int		index;
	int		bit;
}				t_letter;	

void	ft_putnbr(int n);
void	panic_button(void);
int		check_pid(char *pid);
int		ft_atoi(char *num);

#endif