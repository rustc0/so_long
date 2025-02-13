/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 08:44:55 by rahmoham          #+#    #+#             */
/*   Updated: 2025/02/13 22:44:28 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

void	ft_cleanmap(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
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
				ft_putstr_fd("wrong element detected!", 2);
				ft_cleanmap(map);
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
	int j;

	j = 0;
	while(map->map[0][j])
	{
		if (map->map[0][j++] != '1')
			return (0);
	}
	j = 0;
	while(map->map[map->lines - 1][j])
	{
		if (map->map[0][j++] != '1')
			return (0);
	}
	j = 0;
	while(j < (map->lines - 1))
	{
		if (map->map[j][0] != '1' || map->map[j][map->columns - 1] != '1' )
		{
			ft_putstr_fd("map is not surrounded by walls!", 2);
			return (0);
		}
		j++;
	}
	return (1);
}
int check_map(t_map *map)
{
	return (ismap_closed(map) && elements_check(map));
}
