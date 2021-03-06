cmake_minimum_required(VERSION 3.13)
project(fdf)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit")

#add_library (my_library STATIC|SHARED|MODULE minilibx/libmlx.a)

add_executable(fdf
		minilibx/libmlx.a
		libft/libft.h
		libft/ft_abs.c
		libft/ft_atoi.c
		libft/ft_atoi_hex.c
		libft/ft_bzero.c
		libft/ft_count_words.c
		libft/ft_isalnum.c
		libft/ft_isalpha.c
		libft/ft_isascii.c
		libft/ft_isdigit.c
		libft/ft_isprint.c
		libft/ft_itoa.c
		libft/ft_itoalen.c
		libft/ft_lstadd.c
		libft/ft_lstdel.c
		libft/ft_lstdelone.c
		libft/ft_lstiter.c
		libft/ft_lstmap.c
		libft/ft_lstnew.c
		libft/ft_memalloc.c
		libft/ft_memccpy.c
		libft/ft_memchr.c
		libft/ft_memcmp.c
		libft/ft_memcpy.c
		libft/ft_memdel.c
		libft/ft_memmove.c
		libft/ft_memset.c
		libft/ft_putchar.c
		libft/ft_putchar_fd.c
		libft/ft_putendl.c
		libft/ft_putendl_fd.c
		libft/ft_putnbr.c
		libft/ft_putnbr_fd.c
		libft/ft_putstr.c
		libft/ft_putstr_fd.c
		libft/ft_strcat.c
		libft/ft_strchr.c
		libft/ft_strchrn.c
		libft/ft_strclr.c
		libft/ft_strcmp.c
		libft/ft_strcpy.c
		libft/ft_strdel.c
		libft/ft_strdup.c
		libft/ft_strequ.c
		libft/ft_striter.c
		libft/ft_striteri.c
		libft/ft_strjoin.c
		libft/ft_strlcat.c
		libft/ft_strlen.c
		libft/ft_strmap.c
		libft/ft_strmapi.c
		libft/ft_strncat.c
		libft/ft_strncmp.c
		libft/ft_strncpy.c
		libft/ft_strnequ.c
		libft/ft_strnew.c
		libft/ft_strnstr.c
		libft/ft_strrchr.c
		libft/ft_strsplit.c
		libft/ft_strstr.c
		libft/ft_strsub.c
		libft/ft_strtrim.c
		libft/ft_tolower.c
		libft/ft_toupper.c
		libft/ft_strcut.c
		libft/get_next_line.c
		libft/ft_sqrt_up.c
		libft/ft_power.c
		includes/fdf.h
		src/main.c
		src/fdf_read.c
		src/fdf_field.c
		src/fdf_plot.c
		src/fdf_keyboard.c
		libft/ft_round_double.c
		src/fdf_evaluate.c
		libft/ft_abs_double.c
		src/fdf_rotation.c
		src/fdf_moving.c
		src/fdf_presets.c
		src/fdf_mouse.c
		src/fdf_open_close.c
		src/fdf_change_color.c
		src/fdf_color_gradient.c
		src/fdf_menu.c)