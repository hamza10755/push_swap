NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes

SRC = src
LIBFTDIR = libft

SRCS = main.c \
       ft_swap.c \
	   ft_push.c \
	   ft_rotate.c \
	   ft_reverse_rotate.c \
	   small_sort.c \
       utils.c \
	   radix.c \
	   utils2.c \
       errors.c

SRC_FILES = $(addprefix $(SRC)/, $(SRCS))
OBJ_FILES = $(SRCS:.c=.o)

LIBFT = $(LIBFTDIR)/libft.a

all: $(NAME)

%.o: $(SRC)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ_FILES)
	@$(CC) $(OBJ_FILES) -L$(LIBFTDIR) -lft -o $(NAME)

$(LIBFT):
	@make -C $(LIBFTDIR)

clean:
	@rm -f $(OBJ_FILES)
	@make -C $(LIBFTDIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re