/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:49:53 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/10/24 17:01:55 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putint(int n)
{
	char	*res;
	int		len;

	res = ft_itoa(n);
	len = ft_putstr(res);
	free(res);
	return (len);
}

int	ft_putuint(unsigned int n)
{
	char	*res;
	int		len;

	res = ft_utoa(n);
	len = ft_putstr(res);
	free(res);
	return (len);
}

int	ft_puthex(unsigned int n)
{
	char	*res;
	char	*alf;
	int		len;

	alf = "0123456789abcdef";
	res = ft_utoh(n, alf);
	len = ft_putstr(res);
	free(res);
	return (len);
}

int	ft_puthexx(unsigned int n)
{
	char	*res;
	char	*alf;
	int		len;

	alf = "0123456789ABCDEF";
	res = ft_utoh(n, alf);
	len = ft_putstr(res);
	free(res);
	return (len);
}

int	ft_putaddress(unsigned long int n)
{
	char	*res;
	char	*alf;
	int		len;

	alf = "0123456789abcdef";
	res = ft_ultoh(n, alf);
	len = ft_putstr("0x") + ft_putstr(res);
	free(res);
	return (len);
}
