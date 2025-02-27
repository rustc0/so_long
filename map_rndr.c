/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rndr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:13:47 by rahmoham          #+#    #+#             */
/*   Updated: 2025/02/24 13:58:12 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error("Error :\nmlx server conexion failed", game);
	mlx_get_screen_size(game->mlx, &game->map->screen_w, &game->map->screen_l);
	if (game->map->columns * 64 > game->map->screen_w
		|| game->map->lines * 64 > game->map->screen_l)
	{
		ft_error("Error :\nMap is too big for the screen!\n", game);
	}
	game->win = mlx_new_window(game->mlx, game->map->columns * 64,
			game->map->lines * 64, "so_long");
	if (!game->win)
	{
		ft_error("Error :\nmlx window creation failed", game);
	}
}

void	load_imgs(t_game *game)
{
	int	x;

	x = 64;
	game->imgs = malloc(sizeof(t_imgs));
	if (!game->imgs)
		ft_error("imgs allocation failed", game);
	*game->imgs = (t_imgs){0, 0, 0, 0};
	game->imgs->player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &x, &x);
	game->imgs->wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &x, &x);
	game->imgs->collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &x, &x);
	game->imgs->exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &x, &x);
	if (!game->imgs->player || !game->imgs->wall
		|| !game->imgs->collectible || !game->imgs->exit)
		ft_error("Error :\none or more textures are missing!\n", game);
}

void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * 64, y * 64);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map->map[x])
	{
		y = 0;
		while (game->map->map[x][y])
		{
			if (game->map->map[x][y] == '1')
				put_image(game, game->imgs->wall, y, x);
			else if (game->map->map[x][y] == 'P')
				put_image(game, game->imgs->player, y, x);
			else if (game->map->map[x][y] == 'C')
				put_image(game, game->imgs->collectible, y, x);
			else if (game->map->map[x][y] == 'E'
				&& game->c_count == game->collectibles)
				put_image(game, game->imgs->exit, y, x);
			y++;
		}
		x++;
	}
}
