/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:09:17 by rahmoham          #+#    #+#             */
/*   Updated: 2025/02/20 16:16:31 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char *av[])
{
	t_game	*game;
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	if (ac != 2)
		ft_error("Error : invalid format\n", game);
	load_map(game, av[1]);
	init_window(game);
	mlx_loop(game->mlx);
	ft_cleangame (game);
	return (0);
}
