/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 08:08:35 by pstubbs           #+#    #+#             */
/*   Updated: 2018/08/20 10:23:09 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <inttypes.h>

# define NRM  "\x1B[0m"
# define RED  "\x1B[31m"
# define GRN  "\x1B[32m"
# define YEL  "\x1B[33m"
# define BLU  "\x1B[34m"
# define MAG  "\x1B[35m"
# define CYN  "\x1B[36m"
# define WHT  "\x1B[37m"

typedef	struct	s_format
{
	char		c;
	int			start;
	int			end;
	int			spacpad;
	int			zeropad;
	int			padsize;
	int			hash;
	int			minus;
	int			plus;
	int			prec;
	int			precsize;
	int			badflag;
	int			lenmod;
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
	int			wild;
	int			wchar;
}				t_format;

typedef	struct	s_printf
{
	char		*output;
	char		*raw;
	int			size;
	int			padding;
	int			lenmod;
	int			tmp;
	int			l;
	int			isspaceswitch;
}				t_printf;

int				ft_printf(char *str, ...);
char			*dynamicstring(char **ori, char *add);
char			*dynamicchar(char **ori, char add);
t_printf		*createstruc(void);
t_format		*cleanformat(void);
void			printf_destroy(t_printf **node);
int				strprocessing(t_printf *node, char *str, va_list args);

int				handlenonvalid(t_printf *node, t_format *format);
char			*createpadding(char **str, t_format *format);
int				isnormalflag(char *str, int i);
int				spacechecker(char *str, int l);
int				isvaildflag(char *str, int i);
char			*precision(t_format *format, char **str);
char			*lengthmoddig(t_format *format, long long num);
int				findundigit(t_printf *node, va_list args, t_format *format);
int				justpercent(t_printf *node, t_format *format);
void			wildcard(t_printf *node, t_format *format, va_list args);
char			*wcharfinder(t_format *format, wchar_t chr);
int				creatspecialpaddingswitch(t_format *format);
char			*specialpaddingfordigit(t_format *f, int l, char c, char **s);
char			*hexhash(char **tmpstr, char cap, t_format *format);
int				hexhashswitch(t_format *format);
int				istherezero(char *str);
int				wstrsize(wchar_t *tmp);
int				findspecifier(char *str, int i, t_format *format);
int				istherespace(char *str);
int				findwild(char *str, int i);
int				*populatehold(va_list args, t_format *format);

int				findstring(t_printf *node, va_list args, t_format *format);
int				finddigit(t_printf *node, va_list args, t_format *format);
int				findchar(t_printf *node, va_list args, t_format *format);
int				findhex(t_printf *node, va_list args, char cap, t_format *fo);
int				findoct(t_printf *node, va_list args, t_format *format);
int				findpointer(t_printf *node, va_list args, t_format *format);
int				findundigit(t_printf *node, va_list args, t_format *format);
int				findwstr(t_printf *node, va_list args, t_format *format);
int				findwchar(t_printf *node, va_list args, t_format *format);

int				findstringaction(t_printf *node, va_list args, t_format *form);
int				findwstraction(t_printf *node, va_list args, t_format *format);
int				findwcharaction(t_printf *node, va_list args, t_format *format);
int				finddigitaction(t_printf *node, va_list args, t_format *format);
int				findcharaction(t_printf *node, va_list args, t_format *format);
int				findhexaction(t_printf *no, va_list args, t_format *fo, char c);
int				findoctaction(t_printf *node, va_list args, t_format *format);
int				findpointeraction(t_printf *node, va_list args, t_format *fo);
int				findunsdigitaction(t_printf *node, va_list args, t_format *fo);

char			*ft_itoa_base(long long value, int base, int cap);
char			*ft_ulltoa(unsigned long long n);
char			*ft_lltoa(long long n);
#endif
