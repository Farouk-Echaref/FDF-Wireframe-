# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 04:48:20 by fech-cha          #+#    #+#              #
#    Updated: 2022/03/24 04:48:32 by fech-cha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra 
MFLAGS = -lm -lmlx -framework OpenGL -framework Appkit
INCLUDE = -I./inc

FDF = inc/fdf.h 
FDF_BONUS = inc/fdf_bonus.h

FILES = ft_printf.o	\
	ft_printf_utils.o	\
	ft_printf_utils2.o	\
	draw_tools.o  \
	event_utils.o  \
	fdf.o \
	ft_atoi.o \
	get_next_line.o \
	get_next_line_utils.o \
	init_win.o \
	parse_utils.o \
	parsing.o \
	render.o \
	split.o

FILES_B = ft_printf.o	\
	ft_printf_utils.o	\
	ft_printf_utils2.o	\
	draw_tools.o  \
	event_utils.o  \
	fdf.o \
	ft_atoi.o \
	get_next_line.o \
	get_next_line_utils.o \
	init_win.o \
	parse_utils.o \
	parsing.o \
	redraw.o \
	render.o \
	split.o \
	menu.o

B_DIR = build

OBJ = $(addprefix $(B_DIR)/, $(FILES))
OBJ_B = $(addprefix $(B_DIR)/bonus/, $(FILES_B))

NAME = fdf

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(MFLAGS) $^ -o $@
	@echo "\033[30;1m---> \033[0mWireframe Model (FDF) V1.0 \033[32;1m [OK] \033[0m"
	

bonus : $(OBJ_B)
	$(CC) $(MFLAGS) $^ -o $(NAME)
	@echo "\033[30;1m---> \033[0mWireframe Model (FDF) V1.0 \033[32;1m [OK] \033[0m"

$(B_DIR)/bonus/%.o: src/bonus/%.c $(FDF_BONUS)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c  $<

$(B_DIR)/%.o: src/%.c $(FDF)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c  $<

clean :
	@echo "\033[30;1m---> \033[0mObject files clean\033[32;1m [DONE] \033[0m"
	rm -rf $(B_DIR)  

fclean : clean
	@echo "\033[30;1m---> \033[0mBinary files clean\033[32;1m [DONE] \033[0m"
	rm $(NAME) 

re : fclean all

.PHONY : all bonus clean fclean re 
