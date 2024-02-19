# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_Unix.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/26 21:36:38 by W2Wizard      #+  #+#    #+#              #
#    Updated: 2024/02/19 16:23:41 by jesmunoz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#//= Colors =//#
ITALIC 		:= \033[3m
DEF_COLOR 	:=	\033[0;39m
BOLD		:= \033[1m
BLACK		:= \033[30;1m
RED			:= \033[31;1m
GREEN		:= \033[32;1m
YELLOW		:= \033[33;1m
BLUE		:= \033[34;1m
MAGENTA		:= \033[35;1m
CYAN		:= \033[36;1m
WHITE		:= \033[37;1m
RESET		:= \033[0m

#//= Make Rules =//#
$(NAME): $(OBJS)
	@echo
	@echo "${ITALIC}${BOLD}${MAGENTA}+---------------------------------------------+${DEF_COLOR}"
	@echo "${ITALIC}${BOLD}${MAGENTA}|${BLUE} Compiling ${NAME}...${MAGENTA}                      |${DEF_COLOR}"
	@echo "${ITALIC}${BOLD}${MAGENTA}+---------------------------------------------+${DEF_COLOR}"
	@ar rc $@ $^
	@echo "\n${BLUE} ◎ $(GREEN)$(NAME) compiled successfully ${BLUE}◎$(DEF_COLOR)\n"

%.o: %.c $(HDRS)
	@echo  "${WHITE}+---------------------------------------+${DEF_COLOR}"
	@echo  "${WHITE}|${BLUE} File Name: ${BROWN}$(notdir $<)"
	@echo  "${WHITE}|${CYAN} Path:      ${YELLOW}$(dir $<)"
	@echo  "${WHITE}+---------------------------------------+${DEF_COLOR}"
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

# Convert shaders to .c files
$(SRC_DIR)/mlx_%_shader.c: $(SHADER_DIR)/default.%
	@echo "$(GREEN)$(BOLD)Shader to C: $< -> $@$(RESET)"
	@bash tools/compile_shader.sh $< > $@

clean:
	@echo "\n${MAGENTA} ◎ $(RED)All objects cleaned successfully${MAGENTA}◎$(DEF_COLOR)\n"
	@rm -f $(OBJS) $(SHDR)

fclean: clean
	@echo "\n${MAGENTA} ◎ $(RED)All objects and executable cleaned successfully${MAGENTA} ◎$(DEF_COLOR)\n"
	@rm -f $(NAME)
