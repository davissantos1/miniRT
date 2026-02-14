# Variables

CC= cc
CFLAGS= -Wall -Wextra -Werror -Wpedantic -I./includes -O3 -march=native -ffast-math
LDFLAGS= -lXext -lX11 -lm -lz

SRC= \
		src/main.c \
		src/settings.c \
		src/parsing/parse.c \
		src/parsing/parse_shapes.c \
		src/parsing/check_element.c \
		src/parsing/check_part.c \
		src/parsing/check_shapes.c \
		src/vec4/vec4_basics.c \
		src/vec4/vec4_complex.c \
		src/vec4/vec4_init.c \
		src/vec4/vec4_multi_mtx4.c \
		src/matrix/mtx4_basic.c \
		src/matrix/mtx4_det.c \
		src/matrix/mtx4_inverse.c \
		src/matrix/mtx4_utils.c \
		src/shapes_collision/plane.c \
		src/shapes_collision/cylinder.c \
		src/shapes_collision/sphere.c \
		src/shapes_collision/circle.c \
		src/ray/ray.c \
		src/run_rt/get_ray_dir.c \
		src/run_rt/run_rt.c \
		src/phong/phong.c \
		src/utils/img_pixel_put.c \
		src/utils/panic.c \
		src/utils/check.c \
		src/utils/add.c \
		src/utils/start.c

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
	@tar -xf ./minilibx-linux.tgz
	@$(MAKE) -C $(MINILIBX_DIR)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ) 
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
	@$(MAKE) -C $(MINILIBX_DIR) clean
	@echo "🧹 ${YELLOW}Cleaning: ${RESET}minilibx"

fclean: clean
	@echo "💣 ${YELLOW}Cleaning: ${RESET}everything"
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

delete:
	@rm -rf $(MINILIBX_DIR)
	@echo "💣  ${RED}Deleting: ${RESET}minilibx folder"

re: fclean all

.PHONY: all clean fclean re bonus debug
