NAME = fractol
LIBNAME = libft/libft.a
EXTRFLAGGEN = -lmlx -lXext -lX11

CFLAGGEN = -Wall -Wextra -Werror

CC = cc

QUELLE_DATEIEN = ft_math.c complex_math.c iterations.c graphics.c draw.c colorscheme.c io.c fractol.c

OBJEKT_DATEIEN = $(QUELLE_DATEIEN:.c=.o)


all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGGEN) -c $< -o $@

libft/libft.a:
	cd libft && make

$(NAME): $(OBJEKT_DATEIEN) libft/libft.a
	$(CC) $(CFLAGGEN) $(OBJEKT_DATEIEN) $(LIBNAME) $(EXTRFLAGGEN) -o $(NAME)

clean: 
	rm -f $(OBJEKT_DATEIEN)
	cd libft && make clean

fclean: clean 
	rm -f $(NAME)
	rm -f $(LIBNAME)

re: fclean all

.PHONY: all clean flcean re
