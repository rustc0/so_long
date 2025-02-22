/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:32:30 by rahmoham          #+#    #+#             */
/*   Updated: 2025/02/22 21:28:15 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    move_right(t_game *game)
{
	char	target;

	target = game->map->map[game->player_y][game->player_x + 1];
	if (target == '1')
		return;
	if (target == 'C')
		game->c_count++;
	if (target == 'E' && game->collectibles == game->c_count)
		exit_game(game);
	game->player_x++;
	game->moves++;
	if (game->player_y == game->exit_y
		&& game->player_x - 1 == game->exit_x)
		game->map->map[game->player_y][game->player_x - 1] = 'E';
	else
		game->map->map[game->player_y][game->player_x - 1] = '0';
	game->map->map[game->player_y][game->player_x] = 'P';
	mlx_clear_window(game->mlx, game->win);
	render_map(game);
}

void    move_left(t_game *game)
{
	char	target;

	target = game->map->map[game->player_y][game->player_x - 1];
	if (target == '1')
		return;
	if (target == 'C')
		game->c_count++;
	if (target == 'E' && game->collectibles == game->c_count)
		exit_game(game);
	game->player_x--;
	game->moves++;
	if (game->player_y == game->exit_y
		&& game->player_x + 1 == game->exit_x)
		game->map->map[game->player_y][game->player_x + 1] = 'E';
	else
		game->map->map[game->player_y][game->player_x + 1] = '0';
	game->map->map[game->player_y][game->player_x] = 'P';
	mlx_clear_window(game->mlx, game->win);
	render_map(game);
}

void    move_down(t_game *game)
{
	char	target;

	target = game->map->map[game->player_y + 1][game->player_x];
	if (target == '1')
		return;
	if (target == 'C')
		game->c_count++;
	if (target == 'E' && game->collectibles == game->c_count)
		exit_game(game);
	game->player_y++;
	game->moves++;
	if (game->player_y - 1 == game->exit_y
		&& game->player_x == game->exit_x)
		game->map->map[game->player_y - 1][game->player_x] = 'E';
	else
		game->map->map[game->player_y - 1][game->player_x] = '0';
	game->map->map[game->player_y][game->player_x] = 'P';
	mlx_clear_window(game->mlx, game->win);
	render_map(game);
}
void	move_up(t_game *game)
{
	char	target;

	target = game->map->map[game->player_y - 1][game->player_x];
	if (target == '1')
		return;
	if (target == 'C')
		game->c_count++;
	if (target == 'E' && game->collectibles == game->c_count)
		exit_game(game);
	game->player_y--;
	game->moves++;
	if (game->player_y + 1 == game->exit_y
		&& game->player_x == game->exit_x)
		game->map->map[game->player_y + 1][game->player_x] = 'E';
	else
		game->map->map[game->player_y + 1][game->player_x] = '0';
	game->map->map[game->player_y][game->player_x] = 'P';
	mlx_clear_window(game->mlx, game->win);
	render_map(game);
}

int	key_interpreter(int key, t_game *game)
{
	if (key == ESC)
		exit(0);
	if (key == D_KEY || key == RIGHT)
		move_right(game);
	if (key == A_KEY || key == LEFT)
		move_left(game);
	if (key == S_KEY || key == DOWN)
		move_down(game);
	if (key == W_KEY || key == UP)
		move_up(game);
	return 0;
}