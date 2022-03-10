#include "fdf.h"

int main(int argc, char **argv)
{
	t_map 	*map;
	
	if (argc == 2)
	{
		map = (t_map *)malloc(sizeof(t_map));
		if (ft_check_map(argv[1]))
		  	ft_parse_color(argv[1], map);
		else
			ft_parse_white(argv[1], map);
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