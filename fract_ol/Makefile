NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror

VPATH = srcs

SRCS =	main.c		\
		draw.c		\
		init.c		\
		julia.c		\
		mandelbrot.c	\
		burningship.c	\
		colors.c	\
		events.c	\


OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

INCL_DIR = includes
LIBS_HEADERS =	$(INCL_DIR)/mlx.h\
				$(INCL_DIR)/mlx_int.h\
				$(INCL_DIR)/libft.h\
				$(INCL_DIR)/ft_printf.h

LIBS_DIR = libs
LIBS = -lft -lmlx -lftprintf -lmlx_Linux -lX11 -lXext

ARCHIVES =	$(addprefix $(LIBS_DIR)/, libmlx.a libft.a libftprintf.a libmlx_Linux.a)

all:	$(NAME)

libft:
	make -C libft
	cp libft/libft.a libs
	cp libft/libft.h includes

libs/libft.a:	libft
includes/libft.h:	libft

mlx:
	make -C mlx/minilibx-linux
	cp mlx/minilibx-linux/libmlx_Linux.a libs
	cp mlx/minilibx-linux/libmlx.a libs
	cp mlx/minilibx-linux/mlx.h includes
	cp mlx/minilibx-linux/mlx_int.h includes

libs/libmlx.a: mlx
libs/libmlx_Linux.a: mlx
includes/mlx.h: mlx

ftprintf:
	make -C ft_printf
	cp ft_printf/libftprintf.a libs
	cp ft_printf/ft_printf.h includes

libs/libftprintf.a: ftprintf
includes/ft_printf.h: ftprintf

$(NAME): $(OBJS) $(ARCHIVES) $(LIBS_HEADERS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I $(INCL_DIR) -L $(LIBS_DIR) $(LIBS)

$(OBJS_DIR)/%.o:	%.c
	@if [ ! -d $(OBJS_DIR) ]; then	\
		mkdir $(OBJS_DIR);			\
		echo mkdir $(OBJS_DIR);		\
	fi
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INCL_DIR) -L $(LIBS_DIR) $(LIBS)

clean:
	rm -rf $(OBJS_DIR)/*.o

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libft mlx ftprintf
