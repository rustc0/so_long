/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 08:44:55 by rahmoham          #+#    #+#             */
/*   Updated: 2025/02/18 15:20:29 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_cleanmap(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	elem_count(t_map *map)
{
	int (i), (j), (e), (c), (p);
	i = 0;
	e = 0;
	c = 0;
	p = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->columns)
		{
			if (map->map[i][j] == 'E')
				e++;
			else if (map->map[i][j] == 'C')
				c++;
			else if (map->map[i][j] == 'P')
				p++;
			j++;
		}
		i++;
	}
	return (e == 1 && c >= 1 && p == 1);
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
				ft_cleanmap(map->map);
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

int	check_map(t_map *map)
{
	if (!ismap_closed(map))
	{
		ft_putstr_fd("maps isnt enclosed with walls!", 2);
		return (0);
	}
	if (!elements_check(map) && !elem_count(map))
	{
		ft_putstr_fd("check ur map elements and try again!", 2);
		return (0);
	}
	return (1);
}
