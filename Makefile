# Variables

CC= cc
CFLAGS= -Wall -Wextra -Werror -Wpedantic -I./includes -O3 -march=native -ffast-math
LDFLAGS= -lXext -lX11 -lm -lz

BASE_FILES= \
		src/main.c \
		src/settings.c \
		src/utils/check.c \
		src/utils/start.c \
		src/utils/hooks.c \
		src/utils/panic.c \
		src/utils/add.c \
		src/utils/get_name.c \
		src/utils/img_pixel_put.c \
		src/math/matrix/mtx4_inverse.c \
		src/math/matrix/mtx4_utils.c \
		src/math/matrix/mtx4_det.c \
		src/math/matrix/mtx4_basic.c \
		src/math/ray/ray.c \
		src/math/vec4/vec4_init.c \
		src/math/vec4/vec4_multi_mtx4.c \
		src/math/vec4/vec4_complex.c \
		src/math/vec4/vec4_basics.c

SRC= \
		$(BASE_FILES) \
		src/mandatory/0_parsing/check_part.c \
		src/mandatory/0_parsing/check_element.c \
		src/mandatory/0_parsing/parse.c \
		src/mandatory/0_parsing/parse_shapes.c \
		src/mandatory/0_parsing/check_shapes.c \
		src/mandatory/1_run_rt/run_rt.c \
		src/mandatory/2_shapes_collision/plane.c \
		src/mandatory/2_shapes_collision/ray_collision.c \
		src/mandatory/2_shapes_collision/cylinder.c \
		src/mandatory/2_shapes_collision/sphere.c \
		src/mandatory/2_shapes_collision/disk.c \
		src/mandatory/3_phong/shadows.c \
		src/mandatory/3_phong/phong.c

SRC_BONUS= \
			$(BASE_FILES) \
			src/bonus/0_parsing_bonus/check_element_bonus.c \
			src/bonus/0_parsing_bonus/parse_shapes_bonus.c \
			src/bonus/0_parsing_bonus/parse_bonus.c \
			src/bonus/0_parsing_bonus/check_part_bonus.c \
			src/bonus/0_parsing_bonus/check_shapes_bonus.c \
			src/bonus/1_run_rt_bonus/run_rt_bonus.c \
			src/bonus/2_shapes_collision_bonus/disk_bonus.c \
			src/bonus/2_shapes_collision_bonus/ray_collision_bonus.c \
			src/bonus/2_shapes_collision_bonus/plane_bonus.c \
			src/bonus/2_shapes_collision_bonus/sphere_bonus.c \
			src/bonus/2_shapes_collision_bonus/cylinder_bonus.c \
			src/bonus/3_phong_bonus/shadows_bonus.c \
			src/bonus/3_phong_bonus/phong_bonus.c \
			src/bonus/3_phong_bonus/reflections_bonus.c \
			src/bonus/3_phong_bonus/patterns_bonus.c \
			src/bonus/3_phong_bonus/get_pattern_bonus.c

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
ifneq ($(filter bonus,$(MAKECMDGOALS)),)
    SRC := $(SRC_BONUS)
	NAME := miniRT_bonus
	CFLAGS += -I./includes_bonus
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

debug: CFLAGS += -g
debug: re
	@echo "⚠️  ${RED}Compilation mode:${RESET} debug"

clean:
	@echo "🧹 ${YELLOW}Cleaning: ${RESET}project objects"
	@rm -rf $(OBJ) $(OBJ_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "🧹 ${YELLOW}Cleaning: ${RESET}libft objects"
	@$(MAKE) -C $(MINILIBX_DIR) clean
	@echo "🧹 ${YELLOW}Cleaning: ${RESET}minilibx"

fclean: clean
	@echo "💣 ${YELLOW}Cleaning: ${RESET}everything"
	@rm -rf $(NAME) miniRT_bonus
	@$(MAKE) -C $(LIBFT_DIR) fclean

delete:
	@rm -rf $(MINILIBX_DIR)
	@echo "💣  ${RED}Deleting: ${RESET}minilibx folder"

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus debug
