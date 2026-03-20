# Variables

CC= cc
CFLAGS= -Wall -Wextra -Werror -g -march=native -ffast-math
LDFLAGS= -lXext -lX11 -lm -lz
COMMON_INCLUDES= -I./common_includes -I./minilibx-linux
INCLUDES= -I./includes $(COMMON_INCLUDES)
INCLUDES_BONUS= -I./includes_bonus $(COMMON_INCLUDES)


BASE_FILES= \
		src/utils/check.c \
		src/utils/start.c \
		src/utils/hooks.c \
		src/utils/add.c \
		src/utils/get_name.c \
		src/utils/rm_newline.c \
		src/utils/img_pixel_put.c \
		src/utils/camera_move.c \
		src/math/matrix/mtx4_inverse.c \
		src/math/matrix/mtx4_utils.c \
		src/math/matrix/mtx4_det.c \
		src/math/matrix/mtx4_rotations.c \
		src/math/matrix/mtx4_scaling.c \
		src/math/matrix/mtx4_translation.c \
		src/math/matrix/mtx4_basic.c \
		src/math/ray/ray.c \
		src/math/vec4/vec4_init.c \
		src/math/vec4/vec4_multi_mtx4.c \
		src/math/vec4/vec4_complex.c \
		src/math/vec4/vec4_basics.c \
		src/math/vec4/vec4_is_diff.c

SRC= \
		$(BASE_FILES) \
		src/main.c \
		src/settings.c \
		src/utils/panic.c \
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
			src/main_bonus.c \
			src/utils/panic_bonus.c \
			src/bonus/settings_bonus.c \
			src/utils/destroy_texture_bonus.c \
			src/bonus/0_parsing_bonus/check_element_bonus.c \
			src/bonus/0_parsing_bonus/parse_shapes_bonus.c \
			src/bonus/0_parsing_bonus/parse_other_shapes_bonus.c \
			src/bonus/0_parsing_bonus/parse_bonus.c \
			src/bonus/0_parsing_bonus/parse_material_bonus.c \
			src/bonus/0_parsing_bonus/check_part_bonus.c \
			src/bonus/0_parsing_bonus/check_shapes_bonus.c \
			src/bonus/0_parsing_bonus/check_other_shapes_bonus.c \
			src/bonus/0_parsing_bonus/fill_matrix_bonus.c \
			src/bonus/0_parsing_bonus/fill_other_matrix_bonus.c \
			src/bonus/0_parsing_bonus/rotation_calc_bonus.c \
			src/bonus/0_parsing_bonus/load_img_bonus.c \
			src/bonus/0_parsing_bonus/get_vars_bonus.c \
			src/bonus/1_run_rt_bonus/0_run_rt_bonus.c \
			src/bonus/1_run_rt_bonus/1_threads_bonus.c \
			src/bonus/1_run_rt_bonus/2_routine_bonus.c \
			src/bonus/2_shapes_collision_bonus/texture/get_texture_bonus.c \
			src/bonus/2_shapes_collision_bonus/texture/textures_bonus.c \
			src/bonus/2_shapes_collision_bonus/texture/uv_mapping_bonus.c \
			src/bonus/2_shapes_collision_bonus/texture/uv_other_mapping_bonus.c \
			src/bonus/2_shapes_collision_bonus/patterns/patterns_bonus.c \
			src/bonus/2_shapes_collision_bonus/patterns/get_pattern_bonus.c \
			src/bonus/2_shapes_collision_bonus/disk_bonus.c \
			src/bonus/2_shapes_collision_bonus/ray_collision_bonus.c \
			src/bonus/2_shapes_collision_bonus/plane_bonus.c \
			src/bonus/2_shapes_collision_bonus/sphere_bonus.c \
			src/bonus/2_shapes_collision_bonus/cylinder_bonus.c \
			src/bonus/2_shapes_collision_bonus/cone_bonus.c \
			src/bonus/2_shapes_collision_bonus/rectangle_bonus.c \
			src/bonus/2_shapes_collision_bonus/parallelepiped_bonus.c \
			src/bonus/3_phong_bonus/shadows_bonus.c \
			src/bonus/3_phong_bonus/phong_bonus.c \
			src/bonus/3_phong_bonus/reflections_bonus.c

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
	INCLUDES := $(INCLUDES_BONUS)
endif

# Rules
all: $(NAME)

$(LIBFT):
	@printf "📚 ${BLUE}Compiling:${RESET} libft\n"
	@$(MAKE) -C $(LIBFT_DIR) bonus

$(MINILIBX):
	@printf "📚 ${BLUE}Compiling:${RESET} minilibx\n"
	@tar -xf ./minilibx-linux.tgz
	@$(MAKE) -C $(MINILIBX_DIR) 

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ) 
	@printf "💻 ${GREEN}Building:${RESET} ${NAME}\n"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBX) $(LDFLAGS) -o $(NAME)

%.o: %.c
	@printf "🛠️  ${BLUE}Compiling:${RESET} $< to $@\n"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

debug: CFLAGS += -g
debug: re
	@printf "⚠️  ${RED}Compilation mode:${RESET} debug\n"

clean:
	@printf "🧹 ${YELLOW}Cleaning: ${RESET}project objects\n"
	@rm -rf $(OBJ) $(OBJ_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@printf "🧹 ${YELLOW}Cleaning: ${RESET}libft objects\n"
	@$(MAKE) -C $(MINILIBX_DIR) clean
	@printf "🧹 ${YELLOW}Cleaning: ${RESET}minilibx\n"

fclean: clean
	@printf "💣 ${YELLOW}Cleaning: ${RESET}everything\n"
	@rm -rf $(NAME) miniRT_bonus
	@$(MAKE) -C $(LIBFT_DIR) fclean

delete:
	@rm -rf $(MINILIBX_DIR)
	@printf "💣  ${RED}Deleting: ${RESET}minilibx folder\n"

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus debug arch
