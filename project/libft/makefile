
NAME = libft.a

SRC = libft_src/ft_atoi.c libft_src/ft_bzero.c libft_src/ft_isalnum.c libft_src/ft_isalpha.c libft_src/ft_isascii.c libft_src/ft_isdigit.c libft_src/ft_isprint.c \
	libft_src/ft_memccpy.c libft_src/ft_memchr.c libft_src/ft_memcmp.c libft_src/ft_memcpy.c libft_src/ft_memmove.c libft_src/ft_memset.c libft_src/ft_strcat.c \
	libft_src/ft_strchr.c libft_src/ft_strcmp.c libft_src/ft_strcpy.c libft_src/ft_strdup.c libft_src/ft_strlcat.c libft_src/ft_strlen.c libft_src/ft_strncat.c \
	libft_src/ft_strncpy.c libft_src/ft_strrchr.c libft_src/ft_strstr.c libft_src/ft_tolower.c libft_src/ft_toupper.c libft_src/ft_strnstr.c libft_src/ft_strncmp.c \
	libft_src/ft_memalloc.c libft_src/ft_memdel.c libft_src/ft_strnew.c libft_src/ft_strdel.c libft_src/ft_strclr.c libft_src/ft_putchar.c libft_src/ft_strpull_ptr.c \
	libft_src/ft_strpull_idx.c libft_src/ft_putstr.c libft_src/ft_putchar_fd.c libft_src/ft_striter.c libft_src/ft_striteri.c libft_src/ft_strmap.c libft_src/ft_strmapi.c  \
	libft_src/ft_strequ.c libft_src/ft_strnequ.c libft_src/ft_strsub.c libft_src/ft_strjoin.c libft_src/ft_strtrim.c libft_src/ft_strsplit.c libft_src/ft_lstdel.c libft_src/ft_strchr_idx.c\
	libft_src/ft_itoa.c libft_src/ft_putendl.c libft_src/ft_putnbr.c libft_src/ft_putstr_fd.c libft_src/ft_putendl_fd.c libft_src/ft_strcount.c libft_src/ft_lstdelone.c \
	libft_src/ft_putnbr_fd.c libft_src/ft_strrev.c libft_src/ft_wordlen.c libft_src/ft_intlen.c libft_src/ft_lstadd.c libft_src/ft_lstnew.c libft_src/ft_lstiter.c libft_src/ft_lstmap.c \
	libft_src/get_next_line.c libft_src/ft_isspace.c  libft_src/ft_split.c libft_src/ft_intcpy.c libft_src/ft_atol.c libft_src/ft_deldouble.c libft_src/ft_doublesize.c \
	libft_src/ft_printchardouble.c libft_src/ft_printintarray.c libft_src/ft_strmerge.c \
	printf_src/basicchecker.c printf_src/createpadding.c printf_src/createstruc.c printf_src/destroy.c printf_src/dynamicstring.c printf_src/findhex.c printf_src/findoct.c printf_src/findops.c printf_src/findunsdigit.c \
	printf_src/ft_itoa_base.c printf_src/ft_printf.c  printf_src/ft_uitoa.c printf_src/handlenonvalid.c printf_src/lengthmod.c printf_src/precision.c printf_src/strprocessing.c printf_src/ft_lltoa.c printf_src/wildcard.c \
	printf_src/findwchar.c printf_src/findwstr.c printf_src/wcharsupport.c printf_src/finddigit.c printf_src/findpointer.c printf_src/paddingsupportfunc.c printf_src/hexhash.c printf_src/overflowfunc.c \
	printf_src/findspecifer.c printf_src/findactions_one.c printf_src/findactions_two.c\

OBJ = *.o

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRC) -I.includes/ -c
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all