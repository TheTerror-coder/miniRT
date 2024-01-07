# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 16:29:00 by TheTerror         #+#    #+#              #
#    Updated: 2024/01/07 18:12:06 by lmohin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
LIBFT_LIB = $(LIBFT_PATH)libft.a


LIBFT_PATH = 		./libft/
OBJ_PATH = 		./.objs/
INTERS_PATH = 		./inters/
MATHTOOLS_PATH = 		./mathtools/
MEMTOOLS_PATH = 		./memtools/
PARSING_PATH = 		./parsing/



INCLUDE = minirt.h preprocss.h $(LIBFT_PATH)libft.h $(MEMTOOLS_PATH)memtools.h

CC = 				cc
CFLAGS=				-Wall -Werror -Wextra
MLX_OBJ_OPTIONS =	-I/usr/include -Imlx_linux -O3
MLX_LINK_OPTIONS =	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
RM =				rm -rf

SRC_INTERS = $(addprefix $(INTERS_PATH), ray_sphere.c ray_plane.c ray_cylinder.c)
SRC_MATHTOOLS = $(addprefix $(MATHTOOLS_PATH), converts.c vectors.c subtractions.c products.c \
			ft_square.c)
SRC_MEMTOOLS = $(addprefix $(MEMTOOLS_PATH), initmem.c freemem.c init_elms.c free_elms.c)
SRC_PARSING = $(addprefix $(PARSING_PATH), parsing.c ambient.c camera.c light.c \
			sphere.c plane.c cylindre.c)
SRC = main.c minirt.c ft_mlx_utils.c events.c utils.c display.c ft_atod.c ./rays/ray.c $(SRC_MEMTOOLS) \
			$(SRC_PARSING) $(SRC_MATHTOOLS) $(SRC_INTERS)

# OBJ = $(addprefix $(OBJ_PATH), $(notdir $(SRC:%.c=%.o)))
OBJ = $(SRC:%.c=%.o)

all : mk_objdir make_libft $(NAME)

c : all clean

%.o : %.c $(INCLUDE) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(MLX_OBJ_OPTIONS) -c $< -o $@
# mv $@ $(OBJ_PATH)

make_libft :
	make -C $(LIBFT_PATH)

$(NAME) : $(OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) $(MLX_LINK_OPTIONS) -o $@

mk_objdir :
	@mkdir -p $(OBJ_PATH)

clean :
	@make clean -C $(LIBFT_PATH)
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_PATH)
fclean : clean
	@make fclean -C $(LIBFT_PATH)
	@$(RM) $(NAME)
re : fclean all
