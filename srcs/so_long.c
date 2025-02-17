/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:09:17 by rahmoham          #+#    #+#             */
/*   Updated: 2025/02/17 13:53:55 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// int	close_window(int keycode, void *param)
// {
// 	printf("keycode : %d\n", keycode);
// 	if (keycode == ESC)
// 		mlx_loop_end(param);
// 	return (0);
// }

int	main(int ac, char *av[])
{
	// void	*mlx;
	// void	*win;
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (1);
	if (ac == 2 && parse_map(map, av[1]) && check_map(map))
	{
		if (!flood_map(map))
			return (1);
		printf("window :0\n");
		// mlx = mlx_init();
		// win = mlx_new_window(mlx, 1200, 700, "basic win");
		// mlx_key_hook(win, close_window, mlx);
		// mlx_loop(mlx);
	}
	// free (mlx);
	// free (win);
	ft_cleanmap (map->map);
	free (map);
	return (0);
}
