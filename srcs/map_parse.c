/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:08:16 by rahmoham          #+#    #+#             */
/*   Updated: 2025/02/18 21:22:36 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(char *error)
{
	ft_putstr_fd(error, 2);
	exit (1);
}

void	open_map(t_map *map, char *filename)
{
	if (ft_strlen(filename) < 5
		|| *(ft_strrchr(filename, '/') + 1) == '.'
		|| ft_strncmp(&filename[(ft_strlen(filename) - 4)], ".ber", (size_t)4))
	{
		ft_error("filename is not valid!\n");
	}
	map->fd = open(filename, O_RDONLY);
	if (map->fd < 0)
		ft_error("cant open the map file!\n");
}

void	get_dims(t_map *map)
{
	int	i;
	int	ref_len;
	int	len;
	int	rect;

	if (!map || !map->map)
		return ;
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
	if (!rect)
		ft_error("map is not rectangular!\n");
}

int	load_map(t_map *map, char *filename)
{
	char	*full_line;
	char	*line;

	open_map(map, filename);
	full_line = NULL;
	line = get_next_line(map->fd);
	if (!line)
		return (0);
	while (line)
	{
		full_line = ft_strjoin(full_line, line);
		free(line);
		line = get_next_line(map->fd);
	}
	if (!full_line)
		return (0);
	map->map = ft_split (full_line, '\n');
	free (full_line);
	close (map->fd);
	get_dims(map);
	return (1);
}

// int	parse_map(t_map *map, char *filename)
// {
// 	if (!open_map(map, filename))
// 		return (0);
// 	if (!load_map(map))
// 	{
// 		ft_putstr_fd("cant read the map file!\n", 2);
// 		return (0);
// 	}
// 	if (!get_dims(map))
// 	{
// 		ft_putstr_fd("map is not rectangular!\n", 2);
// 		return (0);
// 	}
// 	return (1);
// }

