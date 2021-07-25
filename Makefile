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
	@echo "  Creating object files..........................\033[32m[DONE]\033[0m"
	@sleep 1

$(NAME):	$(PS_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(PS_OBJS) -I $(LIBFT_PATH) $(LIBFT_FLAGS)
	@echo "\033[32m   ____  _   _ ____  _   _   ______        ___    ____  \033[0m"
	@sleep 1
	@echo "\033[32m  |  _ \| | | / ___|| | | | / ___\ \      / / \  |  _ \ \033[0m"
	@sleep 1
	@echo "\033[32m  | |_) | | | \___ \| |_| | \___  \\ \ /\ / / _ \ | |_) |\033[0m"
	@sleep 1
	@echo "\033[32m  |  __/| |_| |___) |  _  |  ___) |\ V  V / ___ \|  __/ \033[0m"
	@sleep 1
	@echo "\033[32m  |_|    \___/|____/|_| |_| |____/  \_/\_/_/   \_\_|    \033[0m"
	@sleep 1
	@echo "\033[35m  =====================================================\033[0m"
	@echo "  push_swap......................................\033[32m[DONE]\033[0m\n"

$(LIBFT):
	@echo "  Compiling library.......................\033[32m[\033[34mPLEASE WAIT\033[32m]\033[0m"
	@make -C $(LIBFT_PATH) $(SILENCE)
	@echo "  Library........................................\033[32m[DONE]\033[0m"
	@sleep 1
	@echo "  Making awsome things...........................\033[32m[DONE]\033[0m\n"
	@sleep 1

bonus: $(BONUS)

$(BONUS): $(CH_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(BONUS) $(CH_OBJS) -I $(LIBFT_PATH) $(LIBFT_FLAGS)
	@echo "\033[31m 	   ____ _   _ _____ ____ _  _______ ____  \033[0m"
	@sleep 1
	@echo "\033[31m  	 /  ___| | | | ____/ ___| |/ / ____|  _ \ \033[0m"
	@sleep 1
	@echo "\033[31m 	 | |   | |_| |  _|| |   | ' /|  _| | |_) |\033[0m"
	@sleep 1
	@echo "\033[31m 	 | |___|  _  | |__| |___| . \| |___|  _ < \033[0m"
	@sleep 1
	@echo "\033[31m 	  \____|_| |_|_____\____|_|\_\_____|_| \_\\033[0m"
	@sleep 1
	@echo "\033[35m  =====================================================\033[0m"
	@echo "  checker........................................\033[32m[DONE]\033[0m\n"

clean:
	@echo "  Cleaning objects...............................\033[32m[DONE]\033[0m"
	@make -C $(LIBFT_PATH) clean $(SILENCE)
	@$(RM) $(PS_OBJS) $(CH_OBJS)

fclean:		clean
	@echo "  Deleting Application...........................\033[32m[DONE]\033[0m\n"
	@$(RM) $(NAME) $(BONUS)
	@make -C $(LIBFT_PATH) fclean $(SILENCE)

re:			fclean all

rebonus:	re bonus

.PHONY:		all clean fclean re bonus rebonus
