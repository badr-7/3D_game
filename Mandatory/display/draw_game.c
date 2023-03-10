/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:21:03 by mel-hous          #+#    #+#             */
/*   Updated: 2023/02/17 09:40:15 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include  <mlx.h>

void	my_mlx_pixel_put(t_draw *data, int y, int x, int color)
{
	char	*dst;

	if (y >= 0 && y < WIN_HEIGHT && x < WIN_WIDTH && x >= 0)
	{
		dst = data->addr + (y * data->line_length
				+ x * (data->bits_per_pixel / 8));
		*(unsigned int *) dst = color;
	}
}

void	ft_clear_image(t_data *test)
{
	int	i;
	int	j;

	i = 0;
	while ((i < WIN_HEIGHT))
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			if (i < WIN_HEIGHT / 2)
				my_mlx_pixel_put(test->draw, i, j, test->cube->ceiling);
			else
				my_mlx_pixel_put(test->draw, i, j, test->cube->floor);
			j++;
		}
		i++;
	}
}

int	draw_2d_map(t_data **sd)
{
	mlx_clear_window((*sd)->win->mlx_ptr, (*sd)->win->window);
	ft_clear_image((*sd));
	ft_raycasting((*sd));
	ft_move((*sd));
	mlx_put_image_to_window((*sd)->win->mlx_ptr, (*sd)->win->window,
		(*sd)->draw->img, 0, 0);
	return (0);
}
