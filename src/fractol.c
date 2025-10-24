/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:34:02 by alpascua          #+#    #+#             */
/*   Updated: 2025/05/12 11:32:07 by alpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	ft_screendef(t_vars *screen)
{
	float	x;
	float	y;

	screen->xres = (float)screen->x;
	screen->yres = (float)screen->y;
	x = screen->xres;
	y = screen->yres;
	screen->xoff = 0;
	screen->yoff = 0;
	screen->minres = (x > y) * y + (x <= y) * x;
	screen->scale = 1;
	if (screen->mode == 0)
		screen->type = ft_strjoin("fract-ol: ", "Mandelbrot");
	else if (screen->mode == 1)
		screen->type = ft_strjoin("fract-ol: ", "Julia");
	if (!(screen->type))
	{
		free(screen);
		perror("malloc");
		exit(1);
	}
	screen->iter = 25;
}

int	main3(t_vars *vars)
{
	paint_fractal(vars, 1);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, 17, 0L, exit_fractal, vars);
	mlx_loop(vars->mlx);
	return (0);
}

/*void	print_details(t_vars *vars)
{
	if (vars->addr)
		printf("address: %s\n", vars->addr);
	if (vars->bits_per_pixel)
		printf("bits: %i\n", vars->bits_per_pixel);
	if (vars->line_length)
		printf("length: %i\n", vars->line_length);
	if (vars->endian)
		printf("endian: %i\n", vars->endian);
}*/

int	main2(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!(vars->mlx))
	{
		perror("mlx init");
		exit_fractal(vars, 1);
	}
	vars->win = mlx_new_window(vars->mlx, vars->x, vars->y, vars->type);
	vars->img = mlx_new_image(vars->mlx, vars->x, vars->y);
	if (!(vars->win) || !(vars->img))
	{
		perror("mlx error");
		exit_fractal(vars, 1);
	}
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	if (!(vars->addr) || !(vars->bits_per_pixel) || !(vars->line_length))
	{
		perror("mlx address get");
		exit_fractal(vars, 1);
	}
	return (main3(vars));
}

int	main(int narg, char **argv)
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	if (!vars)
	{
		perror("malloc");
		return (1);
	}
	if (ft_readinput(narg, argv, vars) == -1)
		return (1);
	ft_screendef(vars);
	return (main2(vars));
}
