/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-01 20:08:55 by rahmoham          #+#    #+#             */
/*   Updated: 2025-02-01 20:08:55 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

int	filename_check(t_map *map, char *file)
{
	if (ft_strlen(file) < 5
		||file[0] == '.'
		|| ft_strncmp(&file[(ft_strlen(file) - 4)], ".ber", (size_t)4))
	{
		ft_putstr_fd("filename is not valid!\n", 1);
		return (0);
	}
	map->name = file;
	return (1);
}

int	get_dims(t_map *map)
{
	int	i;
	int	ref_len;
	int	len;
	int	rect;

	if (!map || !map->map)
	{
		printf("!\n!\n");
		return (0);
	}
		
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

int	fill_map(t_map *map, int fd)
{
	char	*full_line;
	char	*line;
	char	*tmp_line;

	full_line = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		tmp_line = full_line;
		full_line = ft_strjoin2((const char *)full_line, (const char *)line);
		free(line);
		if (tmp_line)
			free(tmp_line);
		line = get_next_line(fd);
	}
	if (!full_line)
		return (0);
	map->map = ft_split(full_line, '\n');
	free(full_line);
	return (1);
}

void	init_map(t_map *map, char *fn)
{
	if (!filename_check(map, fn))
		return ;
	if (!get_dims(map))
	{
		ft_putstr_fd("error initializing the map\n", 1);
		ft_putstr_fd("check if the dimensions are valid!", 1);
		return ;
	}
}

int	parse_map(t_map *map, char *fn)
{
	int	fd;
	//int	i;

	//i = 0;
	fd = open(fn, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("error opening file", 2);
		return (0);
	}
	fill_map(map, fd);
	// while(map->map[i])
	// {
	// 	printf("%s\n", map->map[i++]);
	// }
	init_map(map, fn);
	close(fd);
	if (!map->map)
		return (0);
	return (1);
}
