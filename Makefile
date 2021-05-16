NAME = Wolf3D
FLAGS = -Wall -Wextra
SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./includes/
HDR = includes/wolf.h
LIBFT_DIR = ./libft/
INCLUDES	=	-I./frameworks/SDL2.framework/Versions/A/Headers \
				-F./frameworks/
				 FRAMEWORKS	=	-F./frameworks \
				-rpath ./frameworks \
				-framework OpenGL -framework AppKit -framework OpenCl \
				-framework SDL2 -framework SDL2_ttf -framework SDL2_image
SRC_FILES = main.c read.c rays.c ft_draw.c keys.c load_texture.c pixel.c check.c ray_insect.c messages.c
		OBJ_FILES = $(SRC_FILES:.c=.o)
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
LNK  = -L $(LIBFT_DIR) -lft  -framework OpenGL -framework AppKit
all: obj $(LIBFT)  $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(HDR)
	@gcc $(FLAGS)  $(INCLUDES) -I $(LIBFT_DIR) -I $(INC_DIR) -o $@ -c $<
	@printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

$(LIBFT):
	@make -C $(LIBFT_DIR)
$(NAME): $(OBJ)
	@gcc $(OBJ) $(FRAMEWORKS) $(LNK)  -lm -o $(NAME)
clean:
	@rm -Rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
re: fclean all
.PHONY: all clean fclean re


