/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 22:07:57 by rahmoham          #+#    #+#             */
/*   Updated: 2025/02/14 23:17:08 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill(t_map *map, int y, int x, char **temp)
{
	if (x < 0 || x >= map->columns || y < 0 || y >= map->lines
		|| map->map[y][x] == '1' || temp[y][x] == 'x')
		return ;
	temp[y][x] = 'x';
	flood_fill(map, y + 1, x, temp);
	flood_fill(map, y - 1, x, temp);
	flood_fill(map, y, x + 1, temp);
	flood_fill(map, y, x - 1, temp);
}

char	**create_tmp(t_map *map)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char *) * (map->lines + 1));
	while (i < map->lines)
	{
		tmp[i] = malloc(sizeof(char) * (map->columns + 1));
		ft_strncpy(tmp[i], map->map[i], map->columns);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}


int flood_map(t_map *map)
{
    char    **tmp_map;
    int (x), (y);

    y = 0;
    while(y < map->lines)
    {
        x = 0;
        while (x < map->columns && !(map->map[y][x] == 'P'))
            x++;
        if (map->map[y][x] == 'P')
        break ;
        y++;
    }
    tmp_map = create_tmp(map);
    flood_fill(map, y, x, tmp_map);
}
