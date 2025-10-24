/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpascua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:02:47 by alpascua          #+#    #+#             */
/*   Updated: 2025/05/08 18:51:44 by alpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + y * vars->line_length + x * vars->bits_per_pixel / 8;
	*(unsigned int *)dst = color;
}

void	paint_fractal(t_vars *s, float scale)
{
	if (s->mode == 0)
		paint_mandel(s, scale);
	if (s->mode == 1)
		paint_julia(s, scale);
}

void	ft_controls(void)
{
	ft_printf("\n\t- CONTROLS:\n\n");
	ft_printf("\tARROWS:\t\tmove\n");
	ft_printf("\tMOUSE SCROLL:\tzoom\n");
	ft_printf("\t\'ESC\':\t\texit program\n");
	ft_printf("\t\'M\':\t\tmore resolution\n");
	ft_printf("\t\'N\':\t\tless resolution\n");
}
