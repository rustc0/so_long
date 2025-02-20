/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rndr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:13:47 by rahmoham          #+#    #+#             */
/*   Updated: 2025/02/20 21:26:59 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error("mlx server conexion failed", game);
	game->win = mlx_new_window(game->mlx, game->map->columns * 16,
			game->map->lines * 16, "so_long");
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
		free (game->mlx);
		ft_error("mlx window creation failed", game);
	}
}
void	load_imgs(t_game *game)
{
	game->imgs->player = mlx_xpm_file_to_image(game->mlx,
		 "textures/player.xpm", 16, 16);
	game->imgs->wall = mlx_xpm_file_to_image(game->mlx,
		 "textures/wall.xpm", 16, 16);
	game->imgs->collectible = mlx_xpm_file_to_image(game->mlx,
		 "textures/collectible.xpm", 16, 16);
	game->imgs->exit = mlx_xpm_file_to_image(game->mlx,
		 "textures/exit.xpm", 16, 16);
		 if (!game->imgs->player || !game->imgs->wall || 
			!game->imgs->collectible || !game->imgs->exit)
			ft_error("one or more textures are missing!\n", game);
}
