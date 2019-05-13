# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/28 13:13:07 by mgalliou          #+#    #+#              #
#    Updated: 2019/05/13 12:42:47 by mgalliou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#    COLOR CODES                                                               #
# **************************************************************************** #

ESC			=	\033
CBLACK		=	$(ESC)[30;1m
CRED		=	$(ESC)[31;1m
CGREEN		=	$(ESC)[32;1m
CYELLOW		=	$(ESC)[33;1m
CBLUE		=	$(ESC)[34;1m
CMAGENTA	=	$(ESC)[35;1m
CCYAN		=	$(ESC)[36;1m
CWHITE		=	$(ESC)[37;1m
CRESET		=	$(ESC)[m

# **************************************************************************** #

# **************************************************************************** #
#	NAME / UTILITY / FLAGS / LIBS
# **************************************************************************** #

NAME			=	libftest.a
INC_DIR			=	include libft/include
SRC_DIR			=	src
OBJ_DIR			=	obj
LIB_DIR			=	libft
RM				= 	rm -rf
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -fPIC
CFLAGS_DEBUG	=	-g -fsanitize=address
CPPFLAGS		=	$(foreach dir,$(INC_DIR),-I$(dir))
LDFLAGS			=	-L$(LIB_DIR)
LDLIBS			=	-lft
AR				=	ar rc
RL				=	ranlib
RM				= 	rm -rf

# **************************************************************************** #
#	INCLUDES                                                                   #
# **************************************************************************** #

INC_NAME		=	libft.h libftest.h
INC				=	$(addprefix $(INC_DIR)/,$(INC_NAME))

# **************************************************************************** #
#	SOURCES
# **************************************************************************** #

SRC_NAME	=	get_test_mng.c\
				run_test_suite.c\
				run_test.c\
				assert_not_null.c\
				assert_null.c\
				assert_str_equal.c\
				assert_int_equal.c\
				assert_ptr_equal.c\
				assert_true.c\
				print_test_results.c

SRC			=	$(addprefix $(SRC_DIR)/,$(SRC_NAME))

# **************************************************************************** #
#	OBJS
# **************************************************************************** #

OBJ_NAME	=	$(SRC_NAME:.c=.o)
OBJ			=	$(addprefix $(OBJ_DIR)/,$(OBJ_NAME))

# **************************************************************************** #
#	HEADER
# **************************************************************************** #

# **************************************************************************** #

all : $(NAME)

debug: CFLAGS := $(CFLAGS) $(CFLAGS_DEBUG)
debug: all

$(NAME): $(OBJ)
	$(AR) $@ $^ 
	$(RL) $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -c $< -o $@ $(LDLIBS)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
