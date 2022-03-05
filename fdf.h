#ifndef FDF_H
#define FDF_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

# define FILE_ERROR 1
# define IN 1 
# define OUT 0

typedef struct s_rgb
{
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;
}	t_rgb;

typedef struct s_map
{
	int		line_count;
	int		word_count;
	int		**map_values;
	char	**map_colors;
}	t_map;

typedef struct s_img
{
	void *img_ptr;
	char *addr;
	int bpp;
	int line_len;
	int endian;
}	t_img;

typedef struct s_fdf
{
	void *mlx_ptr;
	void *win_ptr;
	t_img *img;
} 	t_fdf;


void	ft_parse_values(int fd, char *path, t_map *map);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
int		word_count(char	*s, char c);
int		ft_atoi(const char *str);
int		ft_strchr(char *str, int c);
int		ft_check_map(int fd);
int 	count_lines(int fd, int *a);
void	ft_free_double(char *str, char **str1, int c);
void	ft_copy_value(int *ar, char **tmp, int c);
void	ft_parse_color(int fd, char *path, t_map *map);

// X11 Events
// these are only the supported events by Minilibx
// and their callback function prototypes
#define ON_KEYDOWN 2   // int (*f)(int keycode, void *param)
#define ON_KEYUP 3       // int (*f)(int keycode, void *param)
#define ON_MOUSEDOWN 4 // int (*f)(int button, int x, int y, void *param)
#define ON_MOUSEUP 5   // int (*f)(int button, int x, int y, void *param)
#define ON_MOUSEMOVE 6 // int (*f)(int x, int y, void *param)
#define ON_EXPOSE 12   // int (*f)(void *param)
#define ON_DESTROY 17  // int (*f)(void *param)

#define ON_SCROLL_UP 4
#define ON_SCROLL_DOWN 5
// X11 Masks
#define NoEventMask 0L
// Minilibx doesn’t support X11 mask : the docs says
#define X_MASK_DEFAULT NoEventMask

#define ESC_KEY 53
#define ARROWLEFT_KEY 123
#define ARROWRIGHT_KEY 124
#define ARROWDOWN_KEY 125
#define ARROWUP_KEY 126

#define S_KEY 49
#define White 0x00FFFFFF
#define Silver 0x00C0C0C0
#define Gray 0x00808080
#define Black 0x00000000
#define Red 0x00FF0000
#define Maroon 0x00800000
#define Yellow 0x00FFFF00
#define Olive 0x00808000
#define Lime 0x0000FF00
#define Green 0x00008000
#define Aqua 0x0000FFFF
#define Teal 0x00008080
#define Blue 0x000000FF
#define Navy 0x00000080
#define Fuchsia 0x00FF00FF
#define Purple 0x00800080

# define MLX_ERROR	1
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 800

#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define WHITE_PIXEL 0xFFFFFF

#endif