CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBDIR = libft
LIB = $(LIBDIR)/libft.a

SRC =

SRCS := $(addprefix src/,$(SRC))
OFILES := $(addprefix ofiles/,$(SRC:.c=.o))

NAME = push_swap

ofiles/%.o: src/%.c includes/so_long.h | dirs
	$(CC) $(CFLAGS) -c $< -o $@

all : dirs $(NAME)

$(NAME) : $(OFILES) -L$(LIBDIR) -lft -o $(NAME)

$(LIB)
	make -C $(LIBDIR)

clean: 
	rm -rf ofiles
	make -C $(LIBDIR) clean
fclean: clean
	rm -f $(NAME)
	make -C $(LIBDIR) fclean

re: fclean all

dirs:
	mkdir -p ofiles

.PHONY: all clean fclean re