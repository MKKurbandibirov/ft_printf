/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:46:54 by nfarfetc          #+#    #+#             */
/*   Updated: 2021/11/15 17:45:17 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_processor(va_list factor, const char *c, int i)
{
	void			*tmp_p;
	unsigned int	tmp_h;
	int				count;

	count = 0;
	if (c[i] == 'x')
	{
		tmp_h = va_arg(factor, unsigned int);
		count = ft_puthex(tmp_h);
	}
	else if (c[i] == 'X')
	{
		tmp_h = va_arg(factor, unsigned int);
		count = ft_puthexx(tmp_h);
	}
	else if (c[i] == 'p')
	{
		tmp_p = va_arg(factor, void *);
		count = ft_putaddress((unsigned long int)tmp_p);
	}
	return (count);
}

int	int_processor(va_list factor, const char *c, int i)
{
	int				count;
	int				tmp_i;
	unsigned int	tmp_u;

	count = 0;
	if (c[i] == 'd' || c[i] == 'i')
	{
		tmp_i = va_arg(factor, int);
		count = ft_putint(tmp_i);
	}
	else if (c[i] == 'u')
	{
		tmp_u = va_arg(factor, unsigned int);
		count = ft_putuint(tmp_u);
	}
	return (count);
}

int	chars_processor(va_list factor, const char *c, int i)
{
	char	tmp_c;
	char	*tmp_s;
	int		count;

	count = 0;
	if (c[i] == 's')
	{
		tmp_s = va_arg(factor, char *);
		count = ft_putstr(tmp_s);
	}
	else if (c[i] == 'c')
	{
		tmp_c = va_arg(factor, int);
		count = ft_putchar(tmp_c);
	}
	else if (c[i] == '%')
		count = ft_putchar('%');
	return (count);
}

int	printf_proc(const char *c, va_list factor)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (c[i])
	{
		if (c[i] != '%')
			count += ft_putchar(c[i]);
		else
		{
			i++;
			if (c[i] == 'd' || c[i] == 'i' || c[i] == 'u')
				count += int_processor(factor, c, i);
			else if (c[i] == 'x' || c[i] == 'X' || c[i] == 'p')
				count += hex_processor(factor, c, i);
			else if (c[i] == 'c' || c[i] == 's' || c[i] == '%')
				count += chars_processor(factor, c, i);
			else
				count += ft_putchar(c[i]);
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	factor;

	count = 0;
	va_start(factor, format);
	count = printf_proc(format, factor);
	va_end(factor);
	return (count);
}
