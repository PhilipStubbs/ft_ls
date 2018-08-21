
NAME = ft_ls

SRC = src/epochtostring.c src/ft_ls.c src/main_ft_ls.c src/savecurdir.c src/standardisedinitialised.c src/validflags.c \
	src/setpermission.c src/dir_link_creation.c src/destroydir.c src/recursivesearch.c \

OBJ = *.o

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -c -Wall -Werror -Wextra $(SRC) -I ./includes/ -I ./libft/includes/
	gcc -o $(NAME) $(OBJ) -I ./includes/ -I ./libft/includes/ -L. libft/libft.a
	rm -f $(OBJ)

clean:
	make clean -C libft/
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

lib:
	make re -C libft/

flib:
	make fclean -C libft/

re: fclean all