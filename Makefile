# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 09:58:28 by jesmunoz          #+#    #+#              #
#    Updated: 2024/04/01 09:21:53 by jesmunoz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#------------------------------------COLORS------------------------------------#
#------------------------------------------------------------------------------#
ITALIC 		=	\033[3m
BOLD 		=	\033[1m
DEF_COLOR 	=	\033[0;39m
RED 		=	\033[0;91m
GREEN 		=	\033[0;92m
YELLOW 		=	\033[0;93m
BLUE 		=	\033[0;94m
MAGENTA 	=	\033[0;95m
CYAN 		=	\033[0;96m
WHITE 		=	\033[0;97m
BROWN 		=	\033[38;2;184;143;29m

#------------------------------------------------------------------------------#
#-----------------------------------PROGRAM------------------------------------#
#------------------------------------------------------------------------------#
NAME 		= 	so_long

#------------------------------------------------------------------------------#
#---------------------------------INSTRUCTIONS---------------------------------#
#------------------------------------------------------------------------------#
CC			= 	gcc -I ${INCLUDE} -I ${LIBFT_SRC} -I ${MLX_SRC}/include -Wall -Wextra -Werror -MMD -g
RM			= 	rm -rf
USER		=	jesmunoz
#------------------------------------------------------------------------------#
#------------------------------------INIT--------------------------------------#
#------------------------------------------------------------------------------#
SRC_DIR  			= 	src

OBJ_DIR				= 	obj
LIBS 				= 	./libs/
INCLUDE 			=   ./include/
#------------------------------------------------------------------------------#
#-----------------------------------FILES--------------------------------------#
#------------------------------------------------------------------------------#


SRC_CONTROL_FILES 	=	${SRC_DIR}/control/core_checker.c ${SRC_DIR}/control/map_validator.c \
						${SRC_DIR}/control/map_validator_2.c ${SRC_DIR}/control/error_handler.c \
						${SRC_DIR}/control/move_validator.c \

SRC_LOADER_FILES	=	${SRC_DIR}/game/loader/load_init.c ${SRC_DIR}/game/loader/image_generic_loader.c \
						${SRC_DIR}/game/loader/load_texture_images.c ${SRC_DIR}/game/loader/load_texture_images_2.c

SRC_MOVES_FILES		=	${SRC_DIR}/game/moves/moves.c

SRC_RENDER_FILES 	= 	${SRC_DIR}/game/render/render_background.c

SRC_GAME_FILES		=	${SRC_DIR}/game/run_game.c \
						${SRC_LOADER_FILES} \
						${SRC_MOVES_FILES} \
						${SRC_RENDER_FILES}


# SRC_TEST_FILES		=	${SRC_DIR}/tests/test_init_cunit.c ${SRC_DIR}/tests/Unit/test_parse_map.c

SRC_UTILS_FILES		= 	${SRC_DIR}/utils/rand.c ${SRC_DIR}/utils/flood_fill.c ${SRC_DIR}/utils/free_map.c ${SRC_DIR}/utils/map_tools.c

SRC_FILES   		= 	${SRC_DIR}/main.c \
						${SRC_CONTROL_FILES} \
						${SRC_GAME_FILES} \
						${SRC_UTILS_FILES} \
						${SRC_TEST_FILES}

OBJ					=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
DEP					= 	$(addsuffix .d, $(basename $(SRC_FILES)))

#------------------------------------------------------------------------------#
#---------------------------------DEPENDENCIES---------------------------------#
#------------------------------------------------------------------------------#
# CUnit library for testing
# CUNIT_LNK	=	-L/Users/jesmunoz/.brew/Cellar/cunit/2.1-3/lib -lcunit
# CUNIT_LNK	=	-L/usr/include/CUnit -lcunit
LIBFT_SRC	=	${LIBS}/LIBFT
MLX_SRC		=	${LIBS}/MLX42
FT_LNK		= 	-L$(LIBFT_SRC) -lft
MLX_LNK	= 	-L$(MLX_SRC) -lmlx42 -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
# MLX_LNK	= 	-L$(MLX_SRC) -lmlx42 -Iinclude -ldl -lglfw -pthread -lm
#------------------------------------------------------------------------------#
#-----------------------------------RULES--------------------------------------#
#------------------------------------------------------------------------------#

all: 
	@$(MAKE) -C $(LIBFT_SRC)
	@$(MAKE) -C $(MLX_SRC)
	@$(MAKE) $(NAME)

$(OBJ_DIR)/%.o: %.c Makefile
	@mkdir -p $(dir $@)
	@echo  "${WHITE}+---------------------------------------+${DEF_COLOR}"
	@echo  "${WHITE}|${BLUE} File Name: ${BROWN}$(notdir $<)"
	@echo  "${WHITE}|${CYAN} Path:      ${YELLOW}$(dir $<)"
	@echo  "${WHITE}+---------------------------------------+${DEF_COLOR}"
	@$(CC) -c $< -o $@

-include $(DEP)

$(NAME):	$(OBJ)
	@echo
	@echo "${ITALIC}${BOLD}${MAGENTA}+---------------------------------------------+${DEF_COLOR}"
	@echo "${ITALIC}${BOLD}${MAGENTA}|${BLUE} Compiling ${NAME}...${MAGENTA}                        |${DEF_COLOR}"
	@echo "${ITALIC}${BOLD}${MAGENTA}+---------------------------------------------+${DEF_COLOR}"
	@$(CC) $(OBJ) $(CUNIT_LNK) $(FT_LNK) $(MLX_LNK) -o $(NAME) 
	@echo "\n${BLUE} ◎ $(GREEN)$(NAME) compiled successfully ${BLUE}◎$(DEF_COLOR)\n"

tests: all
	@echo
	@echo "${ITALIC}${BOLD}${MAGENTA}+---------------------------------------------+${DEF_COLOR}"
	@echo "${ITALIC}${BOLD}${MAGENTA}|${BLUE} Running tests...${MAGENTA}                            |${DEF_COLOR}"
	@echo "${ITALIC}${BOLD}${MAGENTA}+---------------------------------------------+${DEF_COLOR}"
	@./$(NAME) tests
	@echo "\n${BLUE} ◎ $(GREEN)Tests ran successfully ${BLUE}◎$(DEF_COLOR)\n"
	

clean:
	@${RM} ${OBJ} ${DEP}
	@$(RM) ./$(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_SRC) clean
	@$(MAKE) -C $(MLX_SRC) clean
	@echo "\n${BLUE} ◎ $(RED)All objects cleaned successfully ${BLUE}◎$(DEF_COLOR)\n"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_SRC) fclean
	@$(MAKE) -C $(MLX_SRC) fclean
	@echo "\n${BLUE} ◎ $(RED)All objects and executable cleaned successfully${BLUE} ◎$(DEF_COLOR)\n"


re: fclean all

.PHONY: all clean fclean re