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

int rec_check(t_map *map)
{
	int	i;
	int j;
	int fd;

	i = 0;
	j = 0;
	while(map->map[i][j] = get_next_line(fd) > 0 )
	{
		i++;
	}
}

int	is_map_valid(t_map *map)
{
	
}