/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:08:16 by rahmoham          #+#    #+#             */
/*   Updated: 2025/02/22 22:17:56 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	open_map(t_game *game, char *filename)
{
	if (ft_strlen(filename) < 5
		|| *(ft_strrchr(filename, '/') + 1) == '.'
		|| ft_strncmp(&filename[(ft_strlen(filename) - 4)], ".ber", (size_t)4))
	{
		ft_error("filename is not valid!\n", game);
	}
	game->map->fd = open(filename, O_RDONLY);
	if (game->map->fd < 0)
		ft_error("cant open the map file!\n", game);
}

void	get_dims(t_game *game)
{
	int	i;
	int	ref_len;
	int	len;
	int	rect;

	if (!game->map || !game->map->map)
		return ;
	i = 0;
	rect = 1;
	ref_len = ft_strlen(game->map->map[0]);
	game->map->columns = ref_len;
	while (game->map->map[i])
	{
		len = (int)ft_strlen(game->map->map[i]);
		if (len != ref_len)
			rect = 0;
		i++;
	}
	game->map->lines = i;
	if (!rect)
		ft_error("map is not in a playable shape!\n", game);
}

void	load_map(t_game *game, char *filename)
{
	char	(*full_line), (*line);

	game->map = malloc(sizeof(t_map));
	if (!game->map)
		return ;
	*game->map = (t_map){0, 0, 0, 0};
	open_map(game, filename);
	full_line = NULL;
	line = get_next_line(game->map->fd);
	if (!line)
		ft_error("map is empty!\n", game);
	while (line)
	{
		full_line = ft_strjoin(full_line, line);
		free(line);
		line = get_next_line(game->map->fd);
	}
	if (!full_line)
		return ;
	game->map->map = ft_split (full_line, '\n');
	free (full_line);
	close (game->map->fd);
	get_dims(game);
	check_map(game);
	flood_map(game);
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

