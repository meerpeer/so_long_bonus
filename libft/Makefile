NAME = libft.a

SRCS = ft_isdigit.c ft_memset.c ft_isprint.c\
ft_strlcat.c ft_atoi.c\
ft_strlcpy.c ft_tolower.c ft_bzero.c ft_strlen.c\
ft_toupper.c ft_memchr.c ft_isalnum.c\
ft_memcmp.c  ft_strncmp.c ft_isalpha.c ft_memcpy.c ft_strchr.c\
ft_strnstr.c ft_isascii.c ft_memmove.c ft_strrchr.c\
ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c\
ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
get_next_line.c get_next_line_utils.c\

SRCS_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c\

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC	= gcc
CFLAGS = -Wall -Wextra -Werror

RM	= rm -f

ifdef BONUS
	COMP_OBJS = $(OBJS) $(OBJS_BONUS)
else
	COMP_OBJS = $(OBJS)
endif

all: $(NAME)

$(NAME): $(COMP_OBJS)
	ar rcs $(NAME) $(COMP_OBJS)

%.o:%.c
	$(CC) $(CFLAGS) -c $<

bonus:
	@$(MAKE) BONUS=1 all

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean re fclean
