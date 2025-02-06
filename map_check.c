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

int	filename_check(char *file)
{
	if (ft_strlen(file) < 5
		||file[0] == '.'
		|| ft_strncmp(&file[(ft_strlen(file) - 4)], ".ber", (size_t)4))
	{
		ft_putstr_fd("filename is not valid!\n", 1);
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
		return;
	i = 0;
	rect = 1;
	ref_len = ft_strlen(map->map[0])
	map->columns = ref_len;
	while (map->map[i])
	{
		len = (int)ft_strlen(map->map[i]);
		if (len != ref_len)
			rect = 0;
		i++;
	}
	map->lines = i;
	return(rect);
}

void	fill_map(t_map *map, int fd)
{
	char	*full_line;
	char	*line;
	char	*tmp_line;

	full_line = NULL;
	line = get_next_line(fd);
	while (line)
	{
		tmp_line = full_line;
		full_line = ft_strjoin(full_line, line);
		free(line);
		free(tmp_line);
		line = get_next_line(fd);
	}
	if (!full_line)
		return ;
	map->map = ft_split(full_line, '\n');
	free(full_line);
}

int	is_map_valid(t_map *map)
{
	int		fd;

	fd = open(map->name, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return 0;
	}
	map->map = fill_map(map, fd);
	close(fd);
	if (!map->map)
		return 0;
	return 1;
}
