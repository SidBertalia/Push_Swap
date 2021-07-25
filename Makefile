NAME	= push_swap
BONUS	= checker

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address
RM		= /bin/rm -f
SILENCE	= --no-print-directory

PS_PATH	=	src/push_swap/
CH_PATH	=	src/checker/

PS_SRCS	=	$(PS_PATH)push_swap.c $(PS_PATH)algorithm.c $(PS_PATH)algorithm_utils.c \
			$(PS_PATH)push_swap_moves.c $(PS_PATH)push_swap_utils.c

CH_SRCS =	$(CH_PATH)checker.c $(CH_PATH)checker_moves.c $(PS_PATH)push_swap_utils.c

PS_OBJS	=	$(PS_SRCS:.c=.o)
CH_OBJS	=	$(CH_SRCS:.c=.o)
SUBDIRS	=	push_swap checker

INC_PATH	= include/
INCLUDES	= -I$(INC_PATH)

LIBFT		= $(LIBFT_PATH)libft.a
LIBFT_PATH	= libft/
LIBFT_FLAGS	= -L $(LIBFT_PATH) -lft

all:		$(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(PS_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(PS_OBJS) -I $(LIBFT_PATH) $(LIBFT_FLAGS)
	@echo "push_swap [OK]\n"

$(LIBFT):
	@make -C $(LIBFT_PATH) $(SILENCE)

bonus: $(BONUS)

$(BONUS): $(CH_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(BONUS) $(CH_OBJS) -I $(LIBFT_PATH) $(LIBFT_FLAGS)
	@echo "checker [OK]\n"

clean:
	@make -C $(LIBFT_PATH) clean $(SILENCE)
	@$(RM) $(PS_OBJS) $(CH_OBJS)

fclean:		clean
	@$(RM) $(NAME) $(BONUS)
	@make -C $(LIBFT_PATH) fclean $(SILENCE)

re:			fclean all

rebonus:	re bonus

.PHONY:		all clean fclean re bonus rebonus
