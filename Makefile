# 🛠️ Variables de compilación
CC          = cc -g
CFLAGS      = -Wall -Wextra -Werror -Iinc -Ilib/libft/includes -Ilib/mlx_linux

# 📂 Rutas y nombres
LIB_FT_DIR  = lib/libft
LIB_MLX_DIR = lib/mlx_linux
LIB_FT      = $(LIB_FT_DIR)/libft.a
LIB_MLX     = $(LIB_MLX_DIR)/libmlx.a

# 🚩 Banderas para MiniLibX y Linux
LIB_FLAGS   = -L$(LIB_MLX_DIR) -lmlx -L$(LIB_FT_DIR) -lft -lXext -lX11 -lm -lbsd

NAME        = so_long
SRC_DIR     = src
SRC         = $(SRC_DIR)/main.c $(SRC_DIR)/map_reader.c $(SRC_DIR)/map_validation.c \
				$(SRC_DIR)/game_start.c $(SRC_DIR)/render_map.c 
OBJ_DIR     = objs
OBJ         = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
UTILS_DIR	= utils
UTILS_SRC	= $(UTILS_DIR)/map_utils.c  $(SRC_DIR)/draw_utils.c $(UTILS_DIR)/img_utils.c
UTILS_OBJ	= $(addprefix $(OBJ_DIR)/, $(notdir $(UTILS_SRC:.c=.o)))
# 📜 Reglas

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ) $(UTILS_OBJ) $(LIB_FT) $(LIB_MLX)
	$(CC) $(OBJ) $(UTILS_OBJ) $(LIB_FT) $(LIB_MLX) $(LIB_FLAGS) -o $(NAME)
	@echo "✨ Voilà! so_long está listo."

$(LIB_FT):
	@echo "🔨 Construyendo libft..."
	@make -C $(LIB_FT_DIR)

$(LIB_MLX):
	@echo "🎨 Construyendo MLX..."
	@make -C $(LIB_MLX_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "🧹 Limpiando objetos..."
	@rm -f $(OBJ) $(UTILS_OBJ)
	@make -C $(LIB_FT_DIR) clean
	@make -C $(LIB_MLX_DIR) clean

fclean: clean
	@echo "🗑️ Eliminando ejecutable..."
	@rm -f $(NAME)
	@make -C $(LIB_FT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re