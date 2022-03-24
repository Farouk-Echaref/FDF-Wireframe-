/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 03:09:17 by fech-cha          #+#    #+#             */
/*   Updated: 2022/03/24 03:17:50 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	menu_extension(void)
{
	ft_printf("\t\t | --> Zoom In: Z            ");
	ft_printf("                                   |\n");
	ft_printf("\t\t | --> Zoom Out: X          ");
	ft_printf("                                    |\n");
	ft_printf("\t\t | --> Elevate Up: E          ");
	ft_printf("                                  |\n");
	ft_printf("\t\t | --> Elevate Down: R           ");
	ft_printf("                               |\n");
	ft_printf("\t\t | --> Rotate Up: W            ");
	ft_printf("                                 |\n");
	ft_printf("\t\t | --> Rotate Down: S           ");
	ft_printf("                                |\n");
	ft_printf("\t\t | --> Rotate Right: D          ");
	ft_printf("                                |\n");
	ft_printf("\t\t | --> Rotate Left: A           ");
	ft_printf("                                |\n");
	ft_printf("\t\t  - - - - - - - - - - - - - - - - ");
	ft_printf("- - - - - - - - - - - - - - - \n");
}

void	menu(void)
{
	ft_printf("\t\t  -------------------> Wire");
	ft_printf("frame Model V1.0 <-------------------\n");
	ft_printf("\t\t |\t--> Manipulate your map ");
	ft_printf("with these options: <--         |\n");
	ft_printf("\t\t  - - - - - - - - - - - - - ");
	ft_printf("- - - - - - - - - - - - - - - - - - \n");
	ft_printf("\t\t | --> P: Parallel Projection");
	ft_printf(".                                  |\n");
	ft_printf("\t\t | --> I: Isometric Projection.");
	ft_printf("                                 |\n");
	ft_printf("\t\t | --> Arrow Up: Translate Map Up.");
	ft_printf("                              |\n");
	ft_printf("\t\t | --> Arrow Down: Translate Map Down.");
	ft_printf("                          |\n");
	ft_printf("\t\t | --> Arrow Right: Translate Map Right.");
	ft_printf("                        |\n");
	ft_printf("\t\t | --> Arrow Left: Translate Map ");
	ft_printf("Left.                          |\n");
	menu_extension();
}
