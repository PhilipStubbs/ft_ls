/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findwstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:47:12 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/16 11:58:42 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		findwstroutputnull(t_printf *node)
{
	char	*tmpstr;

	tmpstr = ft_strdup("(null)");
	node->output = dynamicstring(&node->output, tmpstr);
	free(tmpstr);
	return (6);
}

int		findwstroutputnullterm(t_printf *node, char **tmpstr)
{
	free(*tmpstr);
	*tmpstr = ft_strdup("{\\0}");
	node->output = dynamicstring(&node->output, *tmpstr);
	node->lenmod += 3;
	free(*tmpstr);
	return (4);
}

int		findwstrbody(t_format *fo, t_printf *node, char **ret, char **ts)
{
	int	len;

	if (fo->prec == 1)
		*ret = precision(fo, ret);
	if (istherezero(node->raw) == 0)
		fo->prec = 0;
	if ((fo->spacpad == 1 || fo->zeropad == 1))
		*ret = createpadding(ret, fo);
	len = ft_strlen(*ret);
	node->output = dynamicstring(&node->output, *ret);
	free(*ret);
	free(*ts);
	return (len);
}

void	findwstrbody_two(t_format *fo, wchar_t *tmp, char **ret, char **tmpstr)
{
	int	i;
	int	len;

	i = 0;
	len = wstrsize(tmp);
	while (tmp[i] && i <= len && tmp != NULL)
	{
		free(*tmpstr);
		*tmpstr = wcharfinder(fo, tmp[i]);
		if (*ret == NULL)
			*ret = ft_strdup(*tmpstr);
		else
			*ret = dynamicstring(ret, *tmpstr);
		if (fo->prec == 1 && fo->wchar > fo->precsize)
			break ;
		i++;
	}
}

int		findwstr(t_printf *node, va_list args, t_format *format)
{
	int		i;
	char	*ret;
	char	*tmpstr;
	wchar_t	*tmp;

	i = 0;
	if (format->wild > 0)
		wildcard(node, format, args);
	tmp = va_arg(args, wchar_t *);
	if (tmp == NULL)
		return (findwstroutputnull(node));
	if (ft_strcmp((char*)tmp, "") == 0)
		return (0);
	tmpstr = wcharfinder(format, tmp[i]);
	if (tmp == 0)
		findwstroutputnullterm(node, &tmpstr);
	ret = NULL;
	findwstrbody_two(format, tmp, &ret, &tmpstr);
	return (findwstrbody(format, node, &ret, &tmpstr));
}
