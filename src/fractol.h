/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexp <alexp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:03:17 by alpascua          #+#    #+#             */
/*   Updated: 2026/10/24 13:37:51 by alexp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define FRACTOL_H
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../lib/Libft/libft.h"
# include "../lib/ft_printf/libftprintf.h"
# include "../mlx_linux/mlx.h"

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307
# define ITER 25
# define MORE 'm'
# define LESS 'n'

typedef struct cnum
{
	float	re;
	float	im;
}	t_complex;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	float	xres;
	float	yres;
	float	xoff;
	float	yoff;
	float	minres;
	float	scale;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		mode;
	float	jx;
	float	jy;
	int		iter;
	char	*type;
}	t_vars;

char	*get_next_line(int fd);

int		ft_readinput(int narg, char **argv, t_vars *vars);

void	paint_mandel(t_vars *s, float scale);

void	paint_julia(t_vars *s, float scale);

void	paint_fractal(t_vars *s, float scale);

void	pixel_put(t_vars *vars, int x, int y, int color);

void	ft_controls(void);

int		exit_fractal(t_vars *vars, int ex);

int		key_hook(int keycode, t_vars *vars);

int		mouse_hook(int code, int x, int y, t_vars *vars);
