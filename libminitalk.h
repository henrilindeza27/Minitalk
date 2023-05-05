/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libminitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrique <henrique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:28:15 by hlindeza          #+#    #+#             */
/*   Updated: 2023/05/04 03:12:48 by henrique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMINITALK_H
# define LIBMINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnubr(long int num);
int		ft_atoi(char *num);
int	    ft_itsdigit(char *num);

#endif
