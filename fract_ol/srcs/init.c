/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tscasso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:29:24 by tscasso           #+#    #+#             */
/*   Updated: 2023/09/13 11:29:25 by tscasso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	init_mand(t_fractal *fractal)
{
	fractal->type = 0;
	fractal->maxiterations = 100;
	fractal->zoom = 500;
	fractal->offset_x = -2.5;
	fractal->offset_y = -2.0;
	fractal->coord_r = -0.5;
	fractal->coord_i = 0.5;
	fractal->coloroffset = 0;
}

void	init_julia(t_fractal *fractal)
{
	fractal->type = 1;
	fractal->maxiterations = 100;
	fractal->zoom = 300;
	fractal->offset_x = -2.5;
	fractal->offset_y = -2.0;
	fractal->coord_r = 0.3;
	fractal->coord_i = 0.7;
	fractal->coloroffset = 0;
}

static void	init_burning(t_fractal *fractal)
{
	fractal->type = 2;
	fractal->maxiterations = 100;
	fractal->zoom = 300;
	fractal->offset_x = -3.5;
	fractal->offset_y = -3.0;
	fractal->coord_r = 0.3;
	fractal->coord_i = 0.7;
	fractal->coloroffset = 0;
}

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->win = mlx_new_window(fractal->mlx,
			WINDOW_WIDTH, WINDOW_HEIGTH, "fractol");
}

void	init_fractal(t_fractal *fractal, char **av)
{
	if (!ft_strncmp(av[1], "mandelbrot", 11))
		init_mand(fractal);
	else if (!ft_strncmp(av[1], "julia", 6))
	{
		if (av[2] && av[3])
			preset_julia(fractal, atof(av[2]), atof(av[3]));
		else
			init_julia(fractal);
	}
	else if (!ft_strncmp(av[1], "burningship", 12))
		init_burning(fractal);
	else
	{
		ft_printf("Usage:\n\t");
		ft_printf("./fractol mandelbrot\n\t");
		ft_printf("./fractol julia\n\t");
		ft_printf("./fractol burningship\n");
		destroy(fractal);
	}
	print_fractal(fractal);
}
