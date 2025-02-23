/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:09:17 by rahmoham          #+#    #+#             */
/*   Updated: 2025/02/23 14:17:10 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	run_game(t_game *game, char *filename)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		return ;
	*game->map = (t_map){0, 0, 0, 0};
	load_map(game, filename);
	init_window(game);
	load_imgs(game);
	render_map(game);
	mlx_key_hook(game->win, key_interpreter, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
}

int	main(int ac, char *av[])
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	*game = (t_game){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	if (ac != 2)
		ft_error("Error :\ninvalid format\n", game);
	run_game(game, av[1]);
	mlx_loop(game->mlx);
	ft_cleangame(game);
	return (0);
}
