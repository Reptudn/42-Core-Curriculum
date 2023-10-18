/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:27:26 by jonask            #+#    #+#             */
/*   Updated: 2023/10/18 10:12:11 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <sys/_types/_va_list.h>
#include <unistd.h>

#include "specifiers.h"
#include "ft_printf.h"

int	is_specifier(char identifier, char type)
{
	if (identifier != '%' || type == 0)
		return (0);
	if (type == 'c')
		return ('c');
	if (type == 's')
		return ('s');
	if (type == 'd')
		return ('d');
	if (type == 'p')
		return ('p');
	if (type == 'd')
		return ('d');
	if (type == 'u')
		return ('u');
	if (type == 'x')
		return ('x');
	if (type == 'X')
		return ('X');
	return (0);
}

int	count_args(const char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != 0)
	{
		if (str[i + 1] != 0 && is_specifier(str[i], str[i + 1]))
		{
			count++;
			i++;
		}
		i++;
	}
	return (count);
}

void	print_argument(va_list *to_print, int type)
{
	if (to_print == 0 || type == 0)
		return ;
	if (type == CHAR)
		put_char(va_arg(*to_print, int));
	else if (type == STRING)
		put_string(va_arg(*to_print, char *));
	else if (type == POINTER)
		put_pointer(va_arg(*to_print, void *));
	else if (type == DECIMAL)
		put_number(va_arg(*to_print, double));
	else if (type == INTEGER)
		put_number(va_arg(*to_print, int));
	else if (type == UINTEGER)
		put_number(va_arg(*to_print, unsigned int));
	else if (type == HEXBIG)
		put_base(*va_arg(*to_print, long *), 16, 1);
	else if (type == HEXSMALL)
		put_base(*va_arg(*to_print, long *), 16, 0);
}

long	reverse_num(long num)
{
	long		r;

	r = 0;
	while (num > 0)
	{
		r = (r * 10) + (num % 10);
		num /= 10;
	}
	return (r);
}
