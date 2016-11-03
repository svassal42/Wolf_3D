NAME =		wolf3d
COMP =		clang
SRC_DIR =	srcs
OBJ_DIR =	obj
SRC =		bresenham.c \
			compass.c \
			controls.c \
			env.c \
			events.c \
			image.c \
			map.c \
			memory.c \
			minimap.c \
			raycasting.c \
			wolf.c
OBJ =		$(SRC:.c=.o)
SRC_FILES =		$(addprefix srcs/, $(SRC))
OBJ_FILES =		$(addprefix obj/, $(OBJ))
INC =		-I includes
LFT =		-Llibft -lft
LMLX =		-Lmlx -lmlx
LIB =		$(LFT) $(LMLX)
GRAPH =		-framework OpenGL -framework AppKit
FLAGS =		-Wall -Wextra -Werror
DEBUG = 	-g
SINGLE = $(findstring s, $(MAKEFLAGS))

$(NAME):	$(OBJ_FILES)
ifeq ("$(SINGLE)", "")
		make -C libft/
		make -C mlx/
endif
		$(COMP) -o $(NAME) $(OBJ_FILES) $(LIB) $(GRAPH)

debug:		$(OBJ_FILES)
ifeq ("$(SINGLE)", "")
		make -C libft/
		make -C mlx/
endif
		$(COMP) -o $(NAME) $(OBJ_FILES) $(LIB) $(GRAPH) $(DEBUG)

all:		$(NAME)

clean:
ifeq ("$(SINGLE)", "")
		make clean -C libft/
		make clean -C mlx/
endif
		rm -f $(OBJ_FILES)

fclean:		clean
ifeq ("$(SINGLE)", "")
		make fclean -C libft/
		make clean -C mlx/
endif
		rm -f $(NAME)

re:			fclean all

norme:
		norminette libft/*.c
		norminette libft/includes/*.h
		norminette srcs/*.c
		norminette includes/*.h

obj/%.o:		srcs/%.c
		@test -d $(dir $@) || mkdir -p $(dir $@) 2> /dev/null
		@$(COMP) -c $(INC) $(FLAGS) $^ -o $@ && echo "Wolf3D: Built $@"