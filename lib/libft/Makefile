NAME	= libft.a
CC	= gcc -c
CFLAGS	= -Wall -Wextra -Werror
RM	= /bin/rm -f
AR	= ar rc

SOURCES =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c\
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		get_next_line_utils.c \
		get_next_line.c \
		ft_printf_utils.c \
		ft_printf_utils2.c \
		ft_printf.c

OBJECTS =	$(SOURCES:.c=.o)

BONUS = ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c

BONUS_OBJECTS = $(BONUS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

$(OBJECTS): $(SOURCES)
	$(CC) $(FLAGS) $(SOURCES)

bonus: $(BONUS_OBJECTS)
	$(AR) $(NAME) $(BONUS_OBJECTS)

$(BONUS_OBJECTS): $(BONUS)
	$(CC) $(FLAGS) $(BONUS)

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)


fclean: clean
	$(RM) $(NAME)

re: fclean all
