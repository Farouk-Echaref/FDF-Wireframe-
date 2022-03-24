
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
	split.o

B_DIR = build

OBJ = $(addprefix $(B_DIR)/, $(FILES))
OBJ_B = $(addprefix $(B_DIR)/bonus/, $(FILES_B))

NAME = fdf

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(MFLAGS) $^ -o $@

bonus : $(OBJ_B)
	$(CC) $(MFLAGS) $^ -o $(NAME)

$(B_DIR)/bonus/%.o: src/bonus/%.c $(FDF_BONUS)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c  $<

$(B_DIR)/%.o: src/%.c $(FDF)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c  $<
	
clean :
	rm -rf $(B_DIR)  

fclean : clean
	rm $(NAME) 

re : fclean all

.PHONY : all bonus clean fclean re 
