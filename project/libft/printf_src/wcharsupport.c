/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wcharsupport.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 18:53:15 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/15 15:45:10 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	wcharrip(wchar_t chr, char *ret, int wchar_len)
{
	if (wchar_len == 2)
	{
		ret[0] = ((chr >> 6) | 0xC0);
		ret[1] = ((chr & 0x3F) | 0x80);
	}
	else if (wchar_len == 3)
	{
		ret[0] = (((chr >> 12)) | 0xE0);
		ret[1] = (((chr >> 6) & 0x3F) | 0x80);
		ret[2] = ((chr & 0x3F) | 0x80);
	}
	else if (wchar_len == 4)
	{
		ret[0] = (((chr >> 18)) | 0xF0);
		ret[1] = (((chr >> 12) & 0x3F) | 0x80);
		ret[2] = (((chr >> 6) & 0x3F) | 0x80);
		ret[3] = ((chr & 0x3F) | 0x80);
	}
}

char	*wcharfinder(t_format *format, wchar_t chr)
{
	int		wchar_len;
	char	*ret;

	wchar_len = 0;
	ret = NULL;
	if (chr <= 0x7F)
		wchar_len = 1;
	else if (chr <= 0x7FF)
		wchar_len = 2;
	else if (chr <= 0xFFFF)
		wchar_len = 3;
	else if (chr <= 0x10FFFF)
		wchar_len = 4;
	format->wchar += wchar_len;
	if (wchar_len == 1)
	{
		ret = ft_strnew(wchar_len);
		ret[0] = (char)chr;
	}
	else
	{
		ret = ft_strnew(wchar_len);
		wcharrip(chr, ret, wchar_len);
	}
	return (ret);
}
