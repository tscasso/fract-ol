/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tscasso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:24:36 by tscasso           #+#    #+#             */
/*   Updated: 2023/09/13 11:24:37 by tscasso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	destroy(t_fractal *f)
{
	mlx_clear_window(f->mlx, f->win);
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx);
	mlx_loop_end(f->mlx);
	free(f->mlx);
	free(f);
	exit(1);
	return (0);
}

int	main(int ac, char *av[])
{
	t_fractal	*fractal;

	fractal = (t_fractal *)malloc(sizeof(t_fractal));
	if (!fractal)
		return (-1);
	if (ac == 2 || ac == 4)
	{
		init_mlx(fractal);
		init_fractal(fractal, av);
		mlx_mouse_hook(fractal->win, mouse_interaction, fractal);
		mlx_hook(fractal->win, 17, 1L << 2, &destroy, fractal);
		mlx_key_hook(fractal->win, key_hook, fractal);
		mlx_loop(fractal->mlx);
	}
	free(fractal);
	return (0);
}
