/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:24:38 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/16 12:07:37 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char				*createinfoupper(unsigned long long v, int b, int l, int n)
{
	char	*ret;
	char	*tab;

	tab = ft_strdup("0123456789ABCDEF");
	l = l + n;
	ret = (char*)malloc(sizeof(char) * l + 1);
	ret[l] = '\0';
	if (n == 1)
		ret[0] = '-';
	while (v > 0)
	{
		ret[--l] = tab[v % b];
		v = v / b;
	}
	free(tab);
	return (ret);
}

char				*createinfolower(unsigned long long v, int b, int l, int n)
{
	char	*ret;
	char	*tab;

	tab = ft_strdup("0123456789abcdef");
	l = l + n;
	ret = (char*)malloc(sizeof(char) * l + 1);
	ret[l] = '\0';
	if (n == 1)
		ret[0] = '-';
	while (v > 0)
	{
		ret[--l] = tab[v % b];
		v = v / b;
	}
	free(tab);
	return (ret);
}

unsigned long long	itoa_base_size(long long value, int base)
{
	unsigned long long	i;
	int					len;

	len = 1;
	i = value;
	while (i /= base)
		len++;
	return (len);
}

char				*ft_itoa_base(long long value, int base, int cap)
{
	int					len;
	int					isneg;
	char				*ret;

	isneg = 0;
	if (value == 0)
	{
		ret = ft_strdup("0");
		return (ret);
	}
	if (base < 2 || base > 16)
		return (0);
	if (value < 0 && base == 10)
	{
		isneg = 1;
		value *= -1;
	}
	len = itoa_base_size(value, base);
	if (cap == 1)
		ret = createinfoupper(value, base, len, isneg);
	else
		ret = createinfolower(value, base, len, isneg);
	return (ret);
}
