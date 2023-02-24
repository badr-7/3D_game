/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_movment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:41:35 by mel-hous          #+#    #+#             */
/*   Updated: 2023/02/16 09:16:43 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	ft_move_left_ang(t_data **sd)
{
	(*sd)->p->angle += (*sd)->p->retation_speed;
	(*sd)->p->angle = fmod((*sd)->p->angle, 2 * M_PI);
	if ((*sd)->p->angle < 0)
		(*sd)->p->angle += (2 * M_PI);
}

void	ft_move_right_ang(t_data **sd)
{
	(*sd)->p->angle -= (*sd)->p->retation_speed;
	(*sd)->p->angle = fmod((*sd)->p->angle, 2 * M_PI);
	if ((*sd)->p->angle < 0)
		(*sd)->p->angle += (2 * M_PI);
}

void	ft_move(t_data *sd)
{
	if (sd->p->move_right == 1)
		ft_move_right(&sd);
	if (sd->p->move_right == -1)
		ft_move_left(&sd);
	if (sd->p->move_up == 1)
		ft_move_up(&sd);
	if (sd->p->move_up == -1)
		ft_move_down(&sd);
	if (sd->p->rotation == 1)
		ft_move_right_ang(&sd);
	if (sd->p->rotation == -1)
		ft_move_left_ang(&sd);
}

int	key_hook(int key, t_data **sd)
{
	if (key == 65307)
		ft_exit(sd);
	if (key == 100)
		(*sd)->p->move_right = 1;
	if (key == 97)
		(*sd)->p->move_right = -1;
	if (key == 115)
		(*sd)->p->move_up = 1;
	if (key == 119)
		(*sd)->p->move_up = -1;
	if (key == 65363)
		(*sd)->p->rotation = -1;
	if (key == 65361)
		(*sd)->p->rotation = 1;
	return (0);
}

int	key_rel(int key, t_data **sd)
{
	if (key == 65307)
		ft_exit(sd);
	if (key == 100)
		(*sd)->p->move_right = 0;
	if (key == 97)
		(*sd)->p->move_right = 0;
	if (key == 115)
		(*sd)->p->move_up = 0;
	if (key == 119)
		(*sd)->p->move_up = 0;
	if (key == 65363)
		(*sd)->p->rotation = 0;
	if (key == 65361)
		(*sd)->p->rotation = 0;
	return (0);
}
