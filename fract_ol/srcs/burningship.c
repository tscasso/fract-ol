/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tscasso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:31:11 by tscasso           #+#    #+#             */
/*   Updated: 2023/09/13 11:31:12 by tscasso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	get_pixel_b(t_fractal *f)
{
	double	z_next;
	double	z_tmp;
	int		i;
	int		pixelcolorindex;

	f->coord_r = f->x / f->zoom + f->offset_x;
	f->coord_i = -(f->y / f->zoom + f->offset_y);
	f->z_r = 0.0;
	f->z_i = 0.0;
	i = 0;
	z_next = 0.0;
	while (z_next < 4 && i < f->maxiterations)
	{
		z_tmp = fabs(f->z_r);
		f->z_r = f->z_r * f->z_r - f->z_i * f->z_i + f->coord_r;
		f->z_i = fabs(2 * f->z_i * z_tmp - f->coord_i);
		z_next = f->z_r * f->z_r + f->z_i * f->z_i;
		i++;
	}
	if (i == f->maxiterations)
		pixelcolorindex = 0;
	else
		pixelcolorindex = calculatecolorindex(i, f->coloroffset);
	pixel_input(f, pixelcolorindex);
}

void	print_burningship(t_fractal *f)
{
	f->image = mlx_new_image(f->mlx, WINDOW_WIDTH, WINDOW_HEIGTH);
	f->adress = mlx_get_data_addr(f->image, &f->bitsperpixel,
			&f->line_len, &f->endian);
	f->x = 0;
	while (f->x < WINDOW_WIDTH)
	{
		f->y = 0;
		while (f->y < WINDOW_HEIGTH)
		{
			get_pixel_b(f);
			f->y++;
		}
		f->x++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->image, 0, 0);
	mlx_destroy_image(f->mlx, f->image);
}
