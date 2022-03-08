#include "fdf.h"

int hex2int(char *hex) 
{
    int val = 0;
	while(*hex != 'x')
		hex++;
	hex++;
    while (*hex) {
        // get current character then increment
        int byte = *hex++; 
        // transform hex character to the 4bit equivalent number, using the ascii table indexes
        if (byte >= '0' && byte <= '9') byte = byte - '0';
        else if (byte >= 'a' && byte <='f') byte = byte - 'a' + 10;
        else if (byte >= 'A' && byte <='F') byte = byte - 'A' + 10;    
        // shift 4 to make space for new digit, and add the 4 bits of the new digit 
        val = (val << 4) | (byte);
    }
    return val;
}

void ft_copy_hex(int *ar, char **tmp, int c)
{
	int i;

	i = 0;
	while (i < c)
	{
		ar[i] = hex2int(*tmp);
		tmp++;
		i++;
	}
}

void	ft_parse_color(int fd, char *path, t_map *map)
{
	int		i;
	char	*line;
	char	**tmp;

	i = 0;
	map -> line_count = count_lines(fd, &map->word_count);
	map->map_values = (int **)malloc(map->line_count * sizeof(int *));
	while (i < map->line_count)
		map->map_values[i++] = (int *)malloc(map->word_count * sizeof(int));
	i = 0;
	map->map_colors = (int **)malloc(map->line_count * sizeof(int *));
	while (i < map->line_count)
		map->map_colors[i++] = (int *)malloc(map->word_count * sizeof(int));
	i = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line && i < map->line_count)
	{
		tmp = ft_split(line , ' ');
		ft_copy_value(map->map_values[i], tmp, map->word_count);
		ft_copy_hex(map->map_colors[i++], tmp, map->word_count);
		
		ft_free_double(line, tmp, map->word_count);
		line = get_next_line(fd);
	}
	close(fd);
}

