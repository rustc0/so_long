/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:09:17 by rahmoham          #+#    #+#             */
/*   Updated: 2025/02/22 22:19:54 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	run_game(t_game *game, char *filename)
{
	load_map(game, filename);
	init_window(game);
	load_imgs(game);
	render_map(game);
	mlx_key_hook(game->win, key_interpreter, game);
}

int	main(int ac, char *av[])
{
	t_game	*game;
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	*game = (t_game){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	// game->moves = 0;
	if (ac != 2)
		ft_error("Error : invalid format\n", game);
	run_game(game, av[1]);
	mlx_loop(game->mlx);
	ft_cleangame(game);
	return (0);
}
