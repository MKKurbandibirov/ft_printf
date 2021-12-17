/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:54:13 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/11/16 09:31:18 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_putint(int n);
int		ft_putstr(char *s);
int		ft_putuint(unsigned int n);
int		ft_puthex(unsigned int n);
int		ft_puthexx(unsigned int n);
int		ft_putaddress(unsigned long int n);
size_t	ft_strlen(const char *c);
int		ft_printf(const char *format, ...);

char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
char	*ft_utoh(unsigned int n, char *alf);
char	*ft_ultoh(unsigned long int n, char *alf);
char	*ft_strdup(const char *s1);

#endif
