# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/28 13:13:07 by mgalliou          #+#    #+#              #
#    Updated: 2020/02/12 18:22:48 by mgalliou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftest.a
INC_DIR			=	include
SRC_DIR			=	src
OBJ_DIR			=	obj
LIB_DIR			=	libft
RM				= 	rm -rf
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
CFLAGS_DEBUG	=	-g #-fsanitize=address
CPPFLAGS		=	$(foreach dir,$(INC_DIR),-I$(dir))
LDFLAGS			=
LDLIBS			=
ARFLAGS 		=	rc
RL				=	ranlib
RM				= 	rm -rf

ifeq ($(shell uname),Linux)
	CFLAGS += -fPIC
endif

INC_NAME		=	libftest.h
INC				=	$(addprefix $(INC_DIR)/,$(INC_NAME))

SRC_NAME	=	get_test_mng.c\
				parse_args.c\
				run_test_suite.c\
				run_test.c\
				assert_not_null.c\
				assert_null.c\
				assert_str_equal.c\
				assert_str_n_eq.c\
				assert_int_equal.c\
				assert_ptr_equal.c\
				assert_true.c\
				assert_false.c\
				print_test_results.c\
				set_cur_test_ret.c

SRC			=	$(addprefix $(SRC_DIR)/,$(SRC_NAME))

OBJ_NAME	=	$(SRC_NAME:.c=.o)
OBJ			=	$(addprefix $(OBJ_DIR)/,$(OBJ_NAME))

all : $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^
	$(RL) $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INC)
	@mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

debug: CFLAGS := $(CFLAGS) $(CFLAGS_DEBUG)
debug: all

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
