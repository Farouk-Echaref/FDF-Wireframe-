#ifndef FDF_H
# define FDF_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <math.h>
#include <mlx.h>


# define FILE_ERROR 1
# define IN 1 
# define OUT 0
# define BUFFER_SIZE 1000
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define MLX_ERROR	1

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

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
	int		line_count;
	int		word_count;
	int		iso;
	int		elevation;
	int		zoom;
	int		posx;
	int		posy;
	int		**map_values;
	int		**map_colors;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
} 	t_fdf;

void	iso(int *x, int *y, int z);
void	zoom(t_fdf *fdf, int *x, int *y, int z, int lc, int wc);
void	shifting(t_fdf *fdf, int *x, int *y);
void	plot_point(t_point *p, int x, int y, int color);
int		draw(t_fdf *fdf);
int		encode_rgb(int apha, int r, int g, int b);
int		esc_press(int key, t_fdf *fdf);
int		draw_line(t_fdf *fdf, int l_index, int w_index, int beginX, int beginY, int endX, int endY,int z1, int z2, int color);
int		init_win(t_fdf *fdf);
int		render_map(t_fdf *fdf);
int		ft_printf(const char *, ...);
int		ft_putchar(char c);
int		ft_putnbr(int nb);
int		ft_putstr(char *str);
int		ft_print_unsigned(unsigned int n);
int		ft_print_lower_hexa(long unsigned int nb);
int		ft_print_upper_hexa(unsigned int nb);
int		ft_print_addrs(long unsigned int nb);
void	check_fd(int fd);
int		ft_parse(char *path, t_fdf *fdf);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
char	*ft_getline(char *str, int *i);
char	*ft_getrest(char *reminder, int *i);
char	*ft_read_all(char *str, int fd);
int		word_count(char	*s, char c);
int		ft_atoi(const char *str);
int		ft_strchr(char *s, int c);
char	*ft_strchr2(char *s, int c);
int 	count_lines(char *path, int *a);
void	ft_free_double_array(char **str, int c);
int		hex2int(char *hex); 
int		ft_strlen(char *str);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_free(char *str1, char *str2);
char	*ft_strjoin(char *str1, char *str2);

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

#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define WHITE_PIXEL 0xFFFFFF

#endif