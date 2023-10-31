/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tscasso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:29:34 by tscasso           #+#    #+#             */
/*   Updated: 2023/09/13 11:29:35 by tscasso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	pixel_input(t_fractal *f, int colorHex)
{
	char			*dest;
	unsigned int	mlxcolor;

	dest = f->adress + (f->y * f->line_len + f->x * (f->bitsperpixel / 8));
	mlxcolor = mlx_get_color_value(f->mlx, colorHex);
	*(unsigned int *)dest = mlxcolor;
}

void	print_fractal(t_fractal *fractal)
{
	if (fractal->type == 0)
		print_mand(fractal);
	else if (fractal->type == 1)
		print_julia(fractal);
	else if (fractal->type == 2)
		print_burningship(fractal);
	else
	{
		ft_printf("Can't print fractal\n");
		destroy(fractal);
	}
}

void	zoom_in(int x, int y, t_fractal *f)
{
	f->offset_x = (x / f->zoom + f->offset_x) - (x / (f->zoom * 1.5));
	f->offset_y = (y / f->zoom + f->offset_y) - (y / (f->zoom * 1.5));
	f->zoom *= 1.5;
}

void	zoom_out(int x, int y, t_fractal *f)
{
	f->offset_x = (x / f->zoom + f->offset_x) - (x / (f->zoom / 1.5));
	f->offset_y = (y / f->zoom + f->offset_y) - (y / (f->zoom / 1.5));
	f->zoom /= 1.5;
}
