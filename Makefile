GREEN   =  	\033[32m
RED     =  	\033[31m
BLUE    =  	\033[34m
RESET   =  	\033[0m

NAME    = 	fractol
CC      = 	cc
CFLAG   = 	-Wall -Wextra -Werror
LDFLAGS = 	-L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

MLX_DIR = MLX

SRC     = 	src/fractol.c 	src/utils.c 	src/event.c 	src/draw.c
OBJS    = 	$(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAG) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "$(BLUE)Linking $(NAME)... ✅$(RESET)"

%.o: %.c fractol.h
	@$(CC) $(CFLAG) -c $< -o $@

clean:
	@echo "$(RED)Cleaning up... 🧹$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Fully cleaning... 🚮$(RESET)"
	@rm -f $(NAME)

re: fclean all
	@echo "$(GREEN)Rebuilding $(NAME)... ♻️$(RESET)"

.PHONY: all clean fclean re