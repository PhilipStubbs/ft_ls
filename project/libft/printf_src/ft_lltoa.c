/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 08:39:33 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/16 09:15:02 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_lltoabody(unsigned long long num, int isneg, int len)
{
	char	*ret;

	if (!(ret = (char*)ft_memalloc(len + 1)))
		return (NULL);
	ret[len + 1] = '\0';
	ret[len + 1] = '\0';
	while (num != 0)
	{
		ret[--len] = num % 10 + 48;
		num = num / 10;
	}
	if (isneg)
		ret[0] = '-';
	return (ret);
}

char	*ft_lltoa(long long n)
{
	char				*ret;
	int					len;
	int					isneg;
	unsigned long long	tmp;
	unsigned long long	num;

	if (n == 0)
		return ((ret = ft_strdup("0")));
	len = 1;
	isneg = 0;
	if (n < 0)
	{
		isneg = 1;
		n = n * -1;
	}
	tmp = n;
	num = n;
	while (tmp /= 10)
		len++;
	len += isneg;
	return (ft_lltoabody(num, isneg, len));
}
