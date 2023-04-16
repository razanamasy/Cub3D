SRC = parce_utils get_next_line get_next_line_utils strlst split \
		del parcing rendering hooks draw collision texture color modmap error main \
		init_dda init utils_calc dda_special_case dda_search_hit\
		dda_general hook_up utils_hook_up_down utils_hook_left_right hook_down \
		hook_left hook_right utils_cadran hook_rotation parce_mapinfo \
		parce_searchsymb parce_upsymb parce_checkline parce_checkvertical \
		parce_downsymb parce_utils2 collision_utils extract_wall put_to_buff draw_line \
		modmap_utils \


SRCS = $(addsuffix .c, ${SRC})

SRCP = $(addprefix bonus/, ${SRC} mouse_hook minimap_init minimap_ray draw_minimap)

SRCB = $(addsuffix _bonus.c, ${SRCP})

OBJS = ${SRCS:.c=.o}

OBJB = ${SRCB:.c=.o}

LIBMLX	= minilibx/libmlx.a

CC	= clang

FLAGS = -Wall -Wextra -Werror

#FSAN = -fsanitize=address

NAME = cub3d

NAMEB = $(addsuffix _bonus, ${NAME})

.c.o:
	$(CC) ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} ${LIBMLX}
	$(CC) ${FLAGS} ${OBJS}  minilibx/libmlx.a -Imlx_linux -lXext -lX11 -lm -lz -O3 -o ${NAME}

$(LIBMLX):
	make -C minilibx
all:	${NAME}

clean:
	rm -f ${OBJS}
	rm -f ${OBJB}

fclean:	clean
		rm -f ${NAME}
		rm -f ${NAMEB}

re: fclean all

bonus: ${OBJB} ${LIBMLX}
	$(CC) ${FLAGS} -o3 ${OBJB}  minilibx/libmlx.a -Imlx_linux -lXext -lX11 -lm -o ${NAMEB}

.PHONY:	all clean fclean re
