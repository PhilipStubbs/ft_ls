/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlenonvalid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 12:18:00 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/15 10:48:14 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	handlenonvalid(t_printf *node, t_format *format)
{
	char	*str;
	int		len;

	str = ft_strnew(1);
	str[0] = format->c;
	if (format->spacpad == 1 || format->zeropad == 1)
		str = createpadding(&str, format);
	node->output = dynamicstring(&(node)->output, str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
