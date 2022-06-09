# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 17:48:26 by lhumbert          #+#    #+#              #
#    Updated: 2022/06/09 18:57:54 by loichu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     Config                                   #
################################################################################

NAME		= fractol
AUTHOR		= loichu
DATE		= 06/04/2022

SRCS		= mlx_utils.c draw_utils.c julia.c mandlebrot.c \
			  atoc.c fractal.c events.c
			  
MAIN		= main.c

################################################################################
#                                    Compile                                   #
################################################################################

OS			= $(shell uname)
ifeq ($(OS),Linux)
	MLX=mlx_linux
	MACROS=-DKEY_ESC=0xff1b \
		   -DKEY_UP=0xff52 \
		   -DKEY_LEFT=0xff51 \
		   -DKEY_RIGHT=0xff53 \
		   -DKEY_DOWN=0xff54
else
	MLX=mlx
	MACROS=-DKEY_ESC=0x35 \
		   -DKEY_UP=0x7b \
		   -DKEY_LEFT=0x7e \
		   -DKEY_RIGHT=0x7d \
		   -DKEY_DOWN=0x7c
endif

SRCS_DIR	=	src
OBJS_DIR	=	obj
OBJS		=	$(addprefix $(OBJS_DIR)/, ${SRCS:.c=.o})
MAIN_OBJ	=	$(addprefix $(OBJS_DIR)/, ${MAIN:.c=.o})

LIBFT		=	libft.a
LIBFT_DIR	=	libft

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I. -I$(SRCS_DIR) -I$(LIBFT_DIR) -I$(MLX)
DEV_FLAGS	=	-Wall -Wextra -I. -I$(SRCS_DIR) -I$(LIBFT_DIR) -I$(MLX)
DBG_FLAGS	=	-g -fsanitize=address

################################################################################
#                                     Colors                                   #
################################################################################

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

################################################################################
#                                      Rules                                   #
################################################################################

all:		header $(NAME)

header:
			@printf "%b" "$(OK_COLOR)"
			@echo "$$(cat logo.ascii)"
			@echo
			@printf "%b" "$(OBJ_COLOR)Author:	$(WARN_COLOR)$(AUTHOR)\n"
			@printf "%b" "$(OBJ_COLOR)Date: 	$(WARN_COLOR)$(DATE)\n\033[m"
			@printf "%b" "$(OBJ_COLOR)CC: 	$(WARN_COLOR)$(CC)\n\033[m"
			@printf "%b" "$(OBJ_COLOR)Flags: 	$(WARN_COLOR)$(CFLAGS)\n\033[m"
			@printf "%b" "$(OBJ_COLOR)Macros:	$(WARN_COLOR)$(MACROS)\n\033[m"
			@echo

$(NAME):		$(OBJS) $(MAIN_OBJ)
ifeq ($(OS),Linux)
					$(CC) $(OBJS) $(MAIN_OBJ) -Lmlx_linux -lmlx_Linux \
					   	-L/usr/lib -lXext -lX11 -lm -lz $(LIBFT_DIR)/$(LIBFT) \
						-o $(NAME)
else
					$(CC) $(OBJS) $(MAIN_OBJ) -Lmlx -lmlx -framework OpenGL \
						-framework AppKit $(LIBFT_DIR)/$(LIBFT) -o $(NAME)
endif

obj/%.o:		$(SRCS_DIR)/%.c $(LIBFT_DIR)/$(LIBFT)
				@mkdir -p $(dir $@)
ifeq ($(OS),Linux)
					$(CC) $(CFLAGS) $(MACROS) -I/usr/include -O3 -c $< -o $@
else
					$(CC) $(CFLAGS) $(MACROS) -c $< -o $@
endif

debug:			$(OBJS) $(MOCK_OBJS)
				$(CC) $(OBJS) $(MAIN_OBJ) $(CFLAGS) $(DBG_FLAGS) \
					$(LIBFT_DIR)/$(LIBFT) -o $(NAME)

clean:
				rm -rf $(OBJS) $(MAIN_OBJ)

fclean:			clean
				rm -rf $(NAME)
				@$(MAKE) -C $(LIBFT_DIR) fclean

norminette:
				norminette src

$(LIBFT_DIR)/$(LIBFT):
				@echo "Compiling libft with bonuses"
				@$(MAKE) -s -C $(LIBFT_DIR) bonus
				@echo "Libft done compiling"

re:				fclean all

.PHONY:			all clean fclean re header
