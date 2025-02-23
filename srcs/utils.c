/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:10:26 by rahmoham          #+#    #+#             */
/*   Updated: 2025/02/23 10:55:29 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	clean_imgs(t_game *game)
{
	if (game->imgs)
	{
		if (game->imgs->player)
			mlx_destroy_image(game->mlx, game->imgs->player);
		if (game->imgs->wall)
			mlx_destroy_image(game->mlx, game->imgs->wall);
		if (game->imgs->collectible)
			mlx_destroy_image(game->mlx, game->imgs->collectible);
		if (game->imgs->exit)
			mlx_destroy_image(game->mlx, game->imgs->exit);
		free (game->imgs);
	}
}

void	cleanmap(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

void	clean_mlx(t_game *game)
{
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		free(game->mlx);
}

void	ft_cleangame(t_game *game)
{
	if (game->map)
	{
		cleanmap(game->map->map);
		free(game->map);
	}
	clean_imgs(game);
	if (game->mlx)
		clean_mlx(game);
	if (game)
		free(game);
}

int	exit_game(t_game *game)
{
	ft_cleangame(game);
	exit(0);
	return (0);
}
