# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/19 19:52:14 by fsmith            #+#    #+#              #
#    Updated: 2019/04/13 17:53:38 by fsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=			fdf

SRC_PATH :=		src/
INC_PATH :=		includes/
LIB_PATH :=		libft/
MLX_PATH :=		minilibx/
OBJ_PATH :=		.obj/

CC :=			clang
CFLAGS :=		-g -Wall -Wextra -Werror
IFLAGS :=		-I $(INC_PATH) -I $(LIB_PATH)
LFLAGS :=		-lft -L $(LIB_PATH)
MLXFLAGS :=		-lmlx -framework OpenGL -framework AppKit

HFILES :=		fdf
FILES :=		main fdf_read fdf_field fdf_plot fdf_keyboard fdf_evaluate\
				fdf_rotation fdf_moving fdf_presets fdf_mouse fdf_open_close\
				fdf_change_color fdf_color_gradient fdf_menu

LIB :=			$(LIB_PATH)libft.a
MLX :=			$(MLX_PATH)libmlx.a

HDRS :=			$(addprefix $(INC_PATH), $(addsuffix .h, $(HFILES)))
SRCS :=			$(addprefix $(SRC_PATH), $(addsuffix .c, $(FILES)))
OBJS :=			$(addprefix $(OBJ_PATH), $(SRCS:%.c=%.o))

all: $(NAME)

$(NAME): $(LIB) $(OBJ_PATH) $(OBJS) $(MLX)
	@ $(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) $(OBJS) -o $(NAME) $(MLX) $(MLXFLAGS)
$(LIB):
	@ $(MAKE) -C $(dir $@) $(notdir $@)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)$(SRC_PATH)
$(OBJ_PATH)%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean: mclean
	make clean -C $(LIB_PATH)
fclean: mfclean
	make fclean -C $(LIB_PATH)
re: fclean all

mclean:
	rm -f $(OBJS) $(DEPS)
mfclean:
	rm -f $(NAME)
	rm -rf $(OBJ_PATH)
mre: mfclean all

.PHONY: $(LIB) all clean fclean re mclean mfclean mre
