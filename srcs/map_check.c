/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 08:44:55 by rahmoham          #+#    #+#             */
/*   Updated: 2025/02/23 14:15:42 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	elem_count(t_game *game)
{
	int (i), (j), (p);
	i = -1;
	p = 0;
	while (++i < game->map->lines)
	{
		j = -1;
		while (++j < game->map->columns)
		{
			if (game->map->map[i][j] == 'E')
			{
				game->exit_x = j;
				game->exit_y = i;
				game->exit_count++;
			}
			else if (game->map->map[i][j] == 'C')
				game->collectibles++;
			else if (game->map->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				p++;
			}
		}
	}
	return (game->exit_count == 1 && game->collectibles >= 1 && p == 1);
}

int	elements_check(t_map *map)
{
	int		i;
	int		j;
	char	c;

	j = 0;
	while (map->map[j])
	{
		i = 0;
		while (map->map[j][i])
		{
			c = map->map[j][i];
			if (c != '0' && c != '1' && c != 'P'
				&& c != 'C' && c != 'E')
			{
				return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}

int	ismap_closed(t_map *map)
{
	int	j;

	j = 0;
	while (map->map[0][j])
	{
		if (map->map[0][j++] != '1')
			return (0);
	}
	j = 0;
	while (map->map[map->lines - 1][j])
	{
		if (map->map[0][j++] != '1')
			return (0);
	}
	j = 0;
	while (j < (map->lines - 1))
	{
		if (map->map[j][0] != '1' || map->map[j][map->columns - 1] != '1' )
			return (0);
		j++;
	}
	return (1);
}

void	check_map(t_game *game)
{
	if (!ismap_closed(game->map))
		ft_error("Error :\nmap is not closed!\n", game);
	if (!elements_check(game->map) || !elem_count(game))
		ft_error("Error :\nelements are not valid!\n", game);
}
