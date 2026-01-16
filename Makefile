# Variables

CC= cc
CFLAGS= -Wall -Wextra -Werror -Wpedantic -Iincludes
LDFLAGS= -lXext -lX11 -lm -lz
SRC= \
		src/main.c
SRC_BONUS= \
		src/main.c
OBJ= $(SRC:.c=.o)
OBJ_BONUS= $(SRC_BONUS:.c=.o)
NAME= miniRT
LIBFT_DIR= libft
LIBFT= $(LIBFT_DIR)/libft.a
MINILIBX_DIR= minilibx-linux
MINILIBX= $(MINILIBX_DIR)/libmlx.a

# Makeflags
MAKEFLAGS += --no-print-directory

# Colors
RED := \033[31m
GREEN := \033[32m
YELLOW := \033[33m
BLUE := \033[34m
RESET := \033[0m

# Bonus setting
ifeq ($(findstring bonus, $MAKECMDGOALS), bonus)
	SRC = $(SRC_BONUS)
endif

# Rules
all: $(NAME)

$(LIBFT):
	@echo "📚 ${BLUE}Compiling:${RESET} libft"
	@$(MAKE) -C $(LIBFT_DIR) bonus

$(MINILIBX):
	@echo "📚 ${BLUE}Compiling:${RESET} minilibx"
	@$(MAKE) -C $(MINILIBX_DIR)

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX)
	@echo "💻 ${GREEN}Building:${RESET} ${NAME}"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBX) $(LDFLAGS) -o $(NAME)

%.o: %.c
	@echo "🛠️  ${BLUE}Compiling:${RESET} $< to $@"
	@$(CC) $(CFLAGS) -c $< -o $@

debug: CFLAGS += -g -o0
debug: re
	@echo "⚠️  ${RED}Compilation mode:${RESET} debug"

clean:
	@echo "🧹 ${YELLOW}Cleaning: ${RESET}project objects"
	@rm -rf $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "🧹 ${YELLOW}Cleaning: ${RESET}libft objects"

fclean: clean
	@echo "💣 ${YELLOW}Cleaning: ${RESET}everything"
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MINILIBX_DIR) clean
	@echo "🧹 ${YELLOW}Cleaning: ${RESET}minilibx"

re: fclean all

.PHONY: all clean fclean re bonus debug
