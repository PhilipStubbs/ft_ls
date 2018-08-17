/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 09:27:25 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/15 16:51:55 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		returnputstr(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
	return (5);
}

int		checkcolour(char *s, int i, int *colourflag)
{
	int	ret;

	ret = 0;
	if (s[i] != '{')
		return (0);
	if (ft_strncmp(s + i, "{RED}", 5) == 0)
		ret = returnputstr(RED);
	else if (ft_strncmp(s + i, "{GRN}", 5) == 0)
		ret = returnputstr(GRN);
	else if (ft_strncmp(s + i, "{YEL}", 5) == 0)
		ret = returnputstr(YEL);
	else if (ft_strncmp(s + i, "{BLU}", 5) == 0)
		ret = returnputstr(BLU);
	else if (ft_strncmp(s + i, "{MAG}", 5) == 0)
		ret = returnputstr(MAG);
	else if (ft_strncmp(s + i, "{CYN}", 5) == 0)
		ret = returnputstr(CYN);
	else if (ft_strncmp(s + i, "{WHT}", 5) == 0)
		ret = returnputstr(WHT);
	else if (ft_strncmp(s + i, "{NRM}", 5) == 0)
		ret = returnputstr(NRM);
	if (ret == 5)
		*colourflag = 1;
	return (ret);
}

int		customputchar(t_printf *node)
{
	int		i;
	int		colourflag;
	char	*s;

	i = 0;
	s = node->output;
	while (node->output[i])
	{
		i += checkcolour(s, i, &colourflag);
		if (s[i] == '\0')
			break ;
		if (s[i] == '{' && s[i + 1] == '\\' && s[i + 2] == '0' &&
		s[i + 3] == '}')
		{
			write(1, "\0", 1);
			i += 4;
		}
		else
		{
			ft_putchar(node->output[i]);
			i++;
		}
	}
	return (colourflag);
}

void	ft_printfbody(t_printf *node, int *ret)
{
	int colourflag;

	colourflag = 0;
	colourflag = customputchar(node);
	*ret = ft_strlen(node->output);
	if (colourflag == 1)
		ft_putstr(NRM);
}

int		ft_printf(char *str, ...)
{
	t_printf	*node;
	va_list		args;
	int			error;
	int			ret;
	int			colourflag;

	error = 0;
	ret = 0;
	colourflag = 0;
	node = createstruc();
	node->raw = ft_strdup(str);
	va_start(args, str);
	node->size = ft_strlen(str);
	error = strprocessing(node, str, args);
	if (ft_strcmp(str, "%") == 0 || ft_strcmp(node->raw, "") == 0)
		error = 1;
	va_end(args);
	if (error == 0)
		ft_printfbody(node, &ret);
	ret -= node->lenmod;
	destroy(&node);
	return (ret);
}
