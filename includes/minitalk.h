/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasyaiche <lucasyaiche@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:48:15 by lyaiche           #+#    #+#             */
/*   Updated: 2022/02/02 02:26:22 by lucasyaiche      ###   ########.fr       */
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
}				t_letter;	

void	ft_putnbr(int n);
void	panic_button(void);
int		check_pid(char *pid);
int		ft_atoi(char *num);

#endif