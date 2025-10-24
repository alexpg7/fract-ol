/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:45:57 by alpascua          #+#    #+#             */
/*   Updated: 2025/05/08 18:41:30 by alpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static float	mod2(t_complex z)
{
	return (z.re * z.re + z.im * z.im);
}

static int long long	ft_mandel_conv(float x, float y, int iter)
{
	t_complex	c;
	t_complex	z;
	t_complex	znew;
	int			n;

	c.re = x;
	c.im = y;
	z.re = 0;
	z.im = 0;
	n = 0;
	while (n <= iter)
	{
		znew.re = z.re * z.re - z.im * z.im + c.re;
		znew.im = 2 * z.re * z.im + c.im;
		z = znew;
		if (mod2(z) > 4)
			return ((int)(255 * n / 50) << 16);
		n++;
	}
	return (0xFF0000);
}

void	paint_mandel(t_vars *s, float scale)
{
	float			ymax;
	float			xmax;
	float			xdim;
	float			ydim;
	int long long	conv;

	ymax = s->yres;
	xmax = s->xres;
	while (s->xres >= 0)
	{
		s->yres = ymax;
		while (s->yres >= 0)
		{
			xdim = -2 + 3 * (s->xres + (s->minres - xmax) / 2) / s->minres;
			ydim = 1.5 - 3 * (s->yres + (s->minres - ymax) / 2) / s->minres;
			conv = ft_mandel_conv(scale * xdim + s->xoff,
					scale * ydim - s->yoff, s->iter);
			pixel_put(s, s->xres, ymax - s->yres, conv);
			s->yres--;
		}
		s->xres--;
	}
	s->yres = ymax;
	s->xres = xmax;
}
