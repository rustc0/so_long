/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-01 20:09:17 by rahmoham          #+#    #+#             */
/*   Updated: 2025-02-01 20:09:17 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(int keycode, void *param)
{
	printf("keycode : %d\n", keycode);
	if (keycode == 65307)
		mlx_loop_end(param);
	return (0);
}

int main(int ac, char *av[])
{
	if (ac == 2 && (filename_check(av[1])))
	{
		void *mlx;
		void *win;

		mlx = mlx_init();
		win = mlx_new_window(mlx, 1200, 700, "basic win");
		mlx_key_hook(win, close_window, mlx);

		mlx_loop(mlx);
	}
	return (0);
}
