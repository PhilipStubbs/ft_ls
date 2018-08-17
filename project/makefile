
NAME = ft_ls

SRC = 

OBJ = *.o

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -c -Wall -Werror -Wextra $(SRC) -I. includes/ -I. libft/includes/
	gcc -o $(NAME) $(OBJ) -I. includes/ -I. libft/includes/ -L. ../libft/libft.a

clean:
	make clean -C libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all