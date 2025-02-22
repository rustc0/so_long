/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:09:45 by rahmoham          #+#    #+#             */
/*   Updated: 2025/02/22 21:26:24 by rahmoham         ###   ########.fr       */
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
	char	**map; // done
	int		lines;
	int		columns;
}	t_map;

typedef struct s_imgs // done
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
	int		player_x;
	int		player_y;
	int		collectibles;
	int		c_count;
	int		moves;
	int		exit_x;
	int		exit_y;
	int		exit_count;
}	t_game;

void	load_map(t_game *game, char *filename);
void	cleanmap(char **map);
void	check_map(t_game *game);
void	flood_map(t_game *game);
void	ft_error(char *error, t_game *game);
// void    ft_cleangame(t_game *game);
void	init_window(t_game *game);
void	load_imgs(t_game *game);
void	render_map(t_game *game);
void	exit_game(t_game *game);
void	put_image(t_game *game, void *img, int x, int y);
int		key_interpreter(int key, t_game *game);
void    ft_cleangame(t_game *game);

#endif