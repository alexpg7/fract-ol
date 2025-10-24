/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:59:13 by alpascua          #+#    #+#             */
/*   Updated: 2025/05/08 18:47:05 by alpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static int	print_ret(char *str, int ret)
{
	ft_printf(str);
	return (ret);
}

static int	ft_display(int opt)
{
	if (opt == 0)
	{
		ft_printf("\nNo fractal selected.\n");
		ft_printf("\n- Available parameters:\n");
		ft_printf("\n\t- Fractals: [Mandelbrot, Julia x y]\n");
		ft_printf("\t\t(\'x\' and \'y\' are the initial values ");
		ft_printf("of Julia set)\n");
		ft_printf("\t- X-window resolution (pixels)\n");
		ft_printf("\t- Y-window resolution (pixels)\n");
		return (-1);
	}
	if (opt == 1)
	{
		ft_printf("███████╗██████╗  █████╗  ██████╗████████╗    ██████╗ ██╗\n");
		ft_printf("██╔════╝██╔══██╗██╔══██╗██╔════╝╚══██╔══╝   ██╔═══██╗██║\n");
		ft_printf("█████╗  ██████╔╝███████║██║        ██║█████╗██║   ██║██║\n");
		ft_printf("██╔══╝  ██╔══██╗██╔══██║██║        ██║╚════╝██║   ██║██║\n");
		ft_printf("██║     ██║  ██║██║  ██║╚██████╗ ");
		ft_printf("  ██║      ╚██████╔╝███████╗\n");
		ft_printf("╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝  ");
		ft_printf(" ╚═╝       ╚═════╝ ╚══════╝\n");
		return (0);
	}
	return (-1);
}

static int	checking2(char **argv, t_vars *vars)
{
	int	e;

	e = vars->mode * 2;
	if (ft_atoi(argv[2 + e]) <= 0 || ft_atoi(argv[3 + e]) <= 0)
	{
		ft_printf("Window resolution must be at least 1 pixel per side.\n");
		return (-1);
	}
	if (ft_atoi(argv[2 + e]) > 3840 || ft_atoi(argv[3 + e]) > 2160)
	{
		ft_printf("Window resolution must be at most 3840x2160.\n");
		return (-1);
	}
	if (e != 0)
	{
		vars->jx = ft_atof(argv[2]);
		vars->jy = ft_atof(argv[3]);
	}
	vars->x = ft_atoi(argv[2 + e]);
	vars->y = ft_atoi(argv[3 + e]);
	return (0);
}

static int	checking(int narg, char **argv, t_vars *vars)
{
	int	e;

	e = 2 * vars->mode;
	if (narg < 4 && e == 2)
		return (print_ret("Introduce initial values for Julia set.\n", -1));
	if (narg == 2 + e)
	{
		vars->x = 1920;
		vars->y = 1080;
		if (narg >= 4)
		{
			vars->jx = ft_atof(argv[2]);
			vars->jy = ft_atof(argv[3]);
		}
		return (print_ret("\nResolution set by default to 1920x1080.\n\n", 0));
	}
	else if (narg == 3 + e)
		return (print_ret("Y-resolution (pixels) needed.\n", -1));
	return (checking2(argv, vars));
}

int	ft_readinput(int narg, char **argv, t_vars *vars)
{
	if (narg < 2)
		return (ft_display(0));
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
		vars->mode = 0;
	else if (ft_strncmp(argv[1], "Julia", 5) == 0)
		vars->mode = 1;
	else
		return (ft_display(0));
	if (checking(narg, argv, vars) != 0)
		return (-1);
	ft_display(1);
	ft_controls();
	return (0);
}
