/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:51:38 by alpascua          #+#    #+#             */
/*   Updated: 2025/05/12 11:31:48 by alpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	exit_fractal(t_vars *vars, int ex)
{
	if (vars->mlx)
	{
		if (vars->img)
			mlx_destroy_image(vars->mlx, vars->img);
		if (vars->win)
			mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	if (vars->type)
		free(vars->type);
	if (vars)
		free(vars);
	exit(ex);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	float	scale;

	scale = vars->scale;
	if (keycode == ESC)
		exit_fractal(vars, 0);
	else if (keycode == UP)
		vars->yoff += 0.5 * scale;
	else if (keycode == DOWN)
		vars->yoff -= 0.5 * scale;
	else if (keycode == RIGHT)
		vars->xoff += 0.5 * scale;
	else if (keycode == LEFT)
		vars->xoff -= 0.5 * scale;
	else if (keycode == MORE)
		vars->iter += 10;
	else if (keycode == LESS)
		vars->iter = 0 + (vars->iter - 10) * (vars->iter > 10);
	paint_fractal(vars, vars->scale);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}

int	mouse_hook(int code, int x, int y, t_vars *vars)
{
	float		scale;

	x = x + 0;
	y = y + 0;
	if (code == 4 || code == 5)
	{
		scale = vars->scale;
		scale = scale * (0.8 * (code == 4) + 1 / 0.8 * (code == 5));
		if (scale > 1.0)
			scale = 1.0;
		vars->scale = scale;
		paint_fractal(vars, scale);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	}
	return (0);
}
