#include "fdf.h"

int main(int argc, char **argv)
{
	int		fd;
	int		check;
	t_map 	*map;
	
	if (argc == 2)
	{
		fd = open(argv[1],O_RDONLY);
		if (fd < 0)
		{
			printf("Error opening the file, %s\n", strerror(errno));
			exit(FILE_ERROR);
		}
		map = (t_map *)malloc(sizeof(t_map));
		check = ft_check_map(fd,argv[1]);
		printf("check = %d\n", check);
		if (check)
			ft_parse_color(fd, argv[1], map);
		else
			ft_parse_values(fd, argv[1], map);
		close(fd);
	}
	else
		printf("not enough arguments! \n");
	return (0);
}



// for (int i = 0; i < map->line_count; i++)
// 		{
// 			for (int j = 0; j < map ->word_count ; j++)
// 			{
// 				if (map->map_values[i][j] < 9)
// 					printf("%d  ",map->map_values[i][j]);
// 				else
// 					printf("%d ",map->map_values[i][j]);
// 			}
// 			printf("\n");
// 		}