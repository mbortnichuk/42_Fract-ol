# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/22 13:45:06 by mbortnic          #+#    #+#              #
#    Updated: 2018/07/22 13:45:07 by mbortnic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c \
		ft_bship.c \
		ft_color.c \
		ft_esc_time_fr.c \
		ft_get_fract.c \
		ft_julia.c \
		ft_keyhooks.c \
		ft_mandelbrot.c \
		ft_mousehooks.c \
		ft_palette.c \
		ft_render_image.c \
		ft_set_fract_table.c \
		ft_tools.c

INC = fractol.h

CFLAGS = -Wall -Wextra -Werror -I

OBJ = $(SRC:.c=.o)

LIBD = ./libft/

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ) $(LIBD)libft.a
	@ gcc -I $(INC) $(OBJ) -o $(NAME) -L$(LIBD) -lft -O3 -lmlx -framework OpenGL -framework AppKit
	@ echo "\033[32;1m$(NAME) is ready\033[0m"

%.o: %.c
	@ gcc -I $(INC) -c $< -o $@

$(LIBD)libft.a:
	@ make -C $(LIBD)

clean:
	@ make clean -C $(LIBD)
	@ $(RM) $(OBJ)
	@ echo "\033[33;1m$(NAME) obj files are removed\033[0m"

fclean: clean
	@ make fclean -C $(LIBD)
	@ $(RM) $(NAME)
	@ echo "\033[31;m$(NAME) is deleted\033[0m"

re: fclean all
	@ echo "\033[36;1mre performed\033[0m"

norm:
	@ echo "\033[35;1mWait a sec.\033[0m"
	@ norminette *.c *.h ./libft/*.c *.h
	@ echo "\033[35;1mnorminette check finished\033[0m"

.PHONY: all clean fclean re norm
