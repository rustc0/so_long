/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:09:45 by rahmoham          #+#    #+#             */
/*   Updated: 2025/02/20 21:05:06 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <mlx.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

enum e_keys
{
	ESC = 65307,
	UP = 65362,
	DOWN = 65364,
	LEFT = 65361,
	RIGHT = 65363,
	W_KEY = 119,
	A_KEY = 97,
	S_KEY = 115,
	D_KEY = 100
};

typedef struct s_map
{
	int		fd;
	char	**map;
	int		lines;
	int		columns;
}	t_map;

typedef struct s_imgs
{
	void	*player;
	void	*wall;
	void	*collectible;
	void	*exit;
}	t_imgs;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_imgs	*imgs;
}	t_game;

void	open_map(t_game *game, char *filename);
void	load_map(t_game *game, char *filename);
void	get_dims(t_game *game);
void	ft_cleanmap(char **map);
int		elements_check(t_map *map);
int		ismap_closed(t_map *map);
int		check_map(t_map *map);
int		flood_map(t_map *map);
void	ft_error(char *error, t_game *game);
void    ft_cleangame(t_game *game);
void	init_window(t_game *game);


#endif