/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:10:26 by rahmoham          #+#    #+#             */
/*   Updated: 2025/02/20 16:03:27 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(char *error, t_game *game)
{
	ft_putstr_fd(error, 2);
	if (game->map)
		ft_cleanmap(game->map->map);
	free(game->map);
	if(game)
		free(game);
	exit (1);
}

void	ft_cleanmap(char **map)
{
	int	i;

	i = 0;
	if (!map || !*map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void    ft_cleangame(t_game *game)
{
	ft_cleanmap(game->map->map);
	free(game->map);
	free(game);
}