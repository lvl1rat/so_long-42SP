LIBFT_PATH		=	./lib/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SOURCES_FILES	=	so_long.c \
					read_map.c \
					map_check.c \
					game_init.c \
					draw.c \
					player_upd.c \
					gameplay.c \
					game_exit.c \
					is_winnable.c

BONUS_FILES		=	so_long_bonus.c \
					read_map_bonus.c \
					map_check_bonus.c \
					game_init_bonus.c \
					draw_bonus.c \
					player_upd_bonus.c \
					gameplay_bonus.c \
					game_exit_bonus.c \
					is_winnable_bonus.c \
					animation_bonus.c \

SOURCES_DIR		=	src

BONUS_DIR		= src_bonus

HEADER			=	$(SOURCES_DIR)/so_long.h

BONUS_HEADER	=	$(BONUS_DIR)/so_long_bonus.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

BONUS_SOURCES	=	$(addprefix $(BONUS_DIR)/, $(BONUS_FILES))

OBJECTS			= 	$(SOURCES:.c=.o)

BONUS_OBJECTS	= $(BONUS_SOURCES:.c=.o)

NAME			=	so_long

NAME_BONUS		=	so_long_bonus

CC				=	clang
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror
MLXFLAGS		=	-lmlx -lXext -lX11

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)


$(NAME):		$(LIBFT) $(OBJECTS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MLXFLAGS) -o $(NAME)


$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

bonus:			$(NAME_BONUS)


$(NAME_BONUS):	$(LIBFT) $(BONUS_OBJECTS) $(BONUS_HEADER)
				$(CC) $(CFLAGS) $(BONUS_OBJECTS) $(LIBFT) $(MLXFLAGS) -o $(NAME_BONUS)


$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME) $(NAME_BONUS) 

re:				fclean all

.PHONY:			all clean fclean re libft minilibx