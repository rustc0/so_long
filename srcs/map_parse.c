/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:08:16 by rahmoham          #+#    #+#             */
/*   Updated: 2025/02/14 23:16:54 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int open_map(t_map *map, char *filename)
{    
	if (ft_strlen(filename) < 5
		||filename[0] == '.'
		|| ft_strncmp(&filename[(ft_strlen(filename) - 4)], ".ber", (size_t)4))
	{
		ft_putstr_fd("filename is not valid!\n", 2);
		return (0);
	}
	map->name = filename;
	map->fd = open(filename, O_RDONLY);
	if (map->fd < 0)
	{
		ft_putstr_fd("Error opening file!\n", 2);
		return (0);
	}
	return (1);
}

int	load_map(t_map *map)
{
	char	*full_line;
	char	*line;
	char	*tmp_line;
	
	full_line = NULL;
	line = get_next_line(map->fd);
	if (!line)
		return (0);
	while (line)
	{
		tmp_line = full_line;
		full_line = ft_strjoin2(full_line, line);
		free(line);
		if (tmp_line)
			free(tmp_line);
		line = get_next_line(map->fd);
	}
	if (!full_line)
		return (0);
	map->map = ft_split(full_line, '\n');
	free(full_line);
	return (1);
}

int	parse_map(t_map *map, char *filename)
{
	if (!open_map(map, filename))
		return (0);
	if (!load_map(map))
	{
		return (0);
		ft_putstr_fd("Error reading the map!\n", 2);
	}
	if (!get_dims(map))
	{
		ft_putstr_fd("map is not rectangular!\n", 2);
		return (0);
	}
	return (1);
}
int	get_dims(t_map *map)
{
	int	i;
	int	ref_len;
	int	len;
	int	rect;

	if (!map || !map->map)
		return (0);
	i = 0;
	rect = 1;
	ref_len = ft_strlen(map->map[0]);
	map->columns = ref_len;
	while (map->map[i])
	{
		len = (int)ft_strlen(map->map[i]);
		if (len != ref_len)
			rect = 0;
		i++;
	}
	map->lines = i;
	return (rect);
}