##
## EPITECH PROJECT, 2022
## MAKEFILE
## File description:
## cesaretti.enzo
##

CYAN		:=	\e[96m
REDBOLD		:=	\033[0;31;1m
GREENBOLD	:=	\033[0;32;1m
BOLD		:=	\033[1m
NORMAL		:=	\033[0m

BUILD_DIR	:=	build
SRC_DIR		:=	src
LIB_DIR		:=	lib

SRC			:=	$(shell find $(SRC_DIR) -name "*.c" -type f) \
				$(shell find $(LIB_DIR) -name "*.c" -type f)

OBJ 		:= 	$(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC))

NAME		:=	42sh

INCLUDES	:=	-I./include

CC			:=	gcc

CFLAGS		:=	-Wall -Wextra $(INCLUDES)

all:	$(NAME)

$(NAME): $(OBJ)
	@ $(CC) -o $(NAME) $(OBJ)
	@ echo -e "${GREENBOLD}[Done] Compilation end successfully${NORMAL}"

$(BUILD_DIR)/%.o: %.c
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ echo -e "${CYAN}[Done] '$<'${NORMAL}"

clean:
	@ $(RM) -rf $(BUILD_DIR)

fclean: clean
	@ $(RM) -rf $(NAME)

re:	fclean all
