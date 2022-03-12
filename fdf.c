#include "fdf.h"

int main(int argc, char **argv)
{
	t_fdf 	*fdf;
	
	if (argc == 2)
	{
		fdf = (t_fdf *)malloc(sizeof(t_fdf));
		if (!fdf)
			return (1);
		ft_parse(argv[1], fdf);
		// for (int i = 0; i < fdf->map->line_count; i++)
		// {
		// 	for (int j = 0; j < fdf->map->word_count ; j++)
		// 	{
		// 		if (fdf->map->map_values[i][j] < 9)
		// 			printf("%d  ",fdf->map->map_values[i][j]);
		// 		else
		// 			printf("%d ",fdf->map->map_values[i][j]);
		// 	}
		// 	printf("\n");
		//}
		//init_win(fdf);
	}
	else
		ft_printf("not enough arguments! \n");
	return (0);
}



// for (int i = 0; i < fdf->map->line_count; i++)
// 		{
// 			for (int j = 0; j < map ->word_count ; j++)
// 			{
// 				if (fdf->map->map_values[i][j] < 9)
// 					printf("%d  ",fdf->map->map_values[i][j]);
// 				else
// 					printf("%d ",fdf->map->map_values[i][j]);
// 			}
// 			printf("\n");
// 		}