SRCS = SRC/ft_printf.c	\
	SRC/ft_printf_utils.c	\
	SRC/ft_printf_utils2.c	\
	SRC/draw_tools.c  \
	SRC/event_utils.c  \
	SRC/fdf.c \
	SRC/ft_atoi.c \
	SRC/get_next_line.c \
	SRC/get_next_line_utils.c \
	SRC/init_win.c \
	SRC/parse_utils.c \
	SRC/parsing.c \
	SRC/render.c \
	SRC/split.c \

SRCS_BONUS = SRC_BONUS/ft_printf.c	\
	SRC_BONUS/ft_printf_utils.c	\
	SRC_BONUS/ft_printf_utils2.c	\
	SRC_BONUS/draw_tools.c  \
	SRC_BONUS/event_utils.c  \
	SRC_BONUS/fdf.c \
	SRC_BONUS/ft_atoi.c \
	SRC_BONUS/get_next_line.c \
	SRC_BONUS/get_next_line_utils.c \
	SRC_BONUS/init_win.c \
	SRC_BONUS/parse_utils.c \
	SRC_BONUS/parsing.c \
	SRC_BONUS/redraw.c \
	SRC_BONUS/render.c \
	SRC_BONUS/split.c \

NAME = fdf
FDF = /Include/fdf.h 
FDF_BONUS = /Include/fdf_bonus.h
CC = cc
CFLAGS = -Wall -Werror -Wextra 
MFLAGS = -lm -lmlx -framework OpenGL -framework Appkit
RM = rm -rf
OBJ = Objects/$(SRC:.c)=.o
OBJ_B = Objects_Bonus/$(SRC_B:.c)=.o



all : $(NAME)

$(NAME): $(OBJ) 
	$(CC)  $(CFLAGS) $(OBJ) -o $@ $(MFLAGS) 

Objects/%.o :$(SRC)/%.c .$(FDF)
	$(CC) $(CFLAGS) -o $@ -c  $< 


bonus : $(OBJ_B)
	cc $(FLAGS)  $(OBJ_B) -o $(NAME) $(MFLAGS)
	
Objects_Bonus/%.o: SRC_BONUS/%.c $(FDF_BONUS)
	cc $(FLAGS) -c $< -o $@ 

clean :
	$(RM) $(OBJ) $(OBJ_B)  

fclean : clean
	$(RM) $(NAME) $(OBJ) $(OBJ_B)  

re : fclean $(NAME) clean

.PHONY : all bonus clean fclean re 
