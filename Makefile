################################################################################
#                                     CONFIG                                   #
################################################################################

NAME     := so_long
CC       := gcc
CFLAGS   := -Wall -Wextra -Werror

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRC_FILES :=	free.c hooks.c load_assets.c load_map.c main.c map_generation.c \
				move_players.c	verify_map.c init.c verify_path.c \
				check_map_content.c valid_road.c valid_road_utils.c
SRCS      := $(addprefix src/, $(SRC_FILES))
OBJS      := $(SRCS:.c=.o)

LIBFT     := libft/libft.a
LIBMLX    := mlx/libmlx.a

################################################################################
#                                  Compilation                                 #
################################################################################

CLR_RMV  := \033[0m
RED      := \033[1;31m
GREEN    := \033[1;32m
YELLOW   := \033[1;33m
BLUE     := \033[1;34m
CYAN     := \033[1;36m
RM       := rm -f

# Main target
$(NAME): $(LIBFT) $(LIBMLX) $(OBJS)
	@echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME) $(CLR_RMV)..."
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibft -lft -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
	@echo "$(GREEN)$(NAME) created $(CLR_RMV) ✔️"

# Compile libft
$(LIBFT):
	@echo "$(GREEN)Compiling Libft $(CLR_RMV)"
	@$(MAKE) -C libft >/dev/null 2>&1

# Compile mlx
$(LIBMLX):
	@echo "$(GREEN)Compiling mlx $(CLR_RMV)"
	@$(MAKE) -C mlx >/dev/null 2>&1

# Pattern rule for object files
%.o: %.c
	$(CC) $(CFLAGS) -Ilibft -Imlx -c $< -o $@

# Phony targets
all: $(NAME)

clean:
	@$(MAKE) -C libft clean >/dev/null 2>&1
	@$(MAKE) -C mlx clean >/dev/null 2>&1
	@$(RM) $(OBJS)
	@rm -rf $(NAME).dSYM >/dev/null 2>&1
	@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean: clean
	@$(MAKE) -C libft fclean >/dev/null 2>&1
	@$(MAKE) -C mlx clean >/dev/null 2>&1
	@$(RM) $(NAME) >/dev/null 2>&1
	@echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re: fclean all

.PHONY: all clean fclean re
