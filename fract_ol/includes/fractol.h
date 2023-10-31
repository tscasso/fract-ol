/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tscasso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:35:31 by tscasso           #+#    #+#             */
/*   Updated: 2023/09/13 11:35:32 by tscasso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <math.h>

# define WINDOW_WIDTH 2080
# define WINDOW_HEIGTH 2080

typedef struct s_fractal
{
	void		*mlx;
	void		*win;
	void		*image;
	void		*adress;
	int			type;
	int			maxiterations;
	int			bitsperpixel;
	int			line_len;
	int			endian;
	int			x;
	int			y;
	int			coloroffset;
	int			pixel_values;
	double		coord_r;
	double		coord_i;
	double		z_r;
	double		z_i;
	double		zoom;
	double		offset_x;
	double		offset_y;
	double		alpha;
	double		beta;
	double		gamma;
	double		min_value;
	double		max_value;
}			t_fractal;

/* init */

void	init_mlx(t_fractal *fractal);
void	init_fractal(t_fractal *fractal, char **av);
void	preset_julia(t_fractal *f, double real, double imaginary);
void	init_julia(t_fractal *fractal);

/* Draw */

void	print_fractal(t_fractal *fractal);
void	pixel_input(t_fractal *f, int color);
void	print_mand(t_fractal *f);
void	print_julia(t_fractal *f);
void	print_burningship(t_fractal *f);
int		calculatecolorindex(int iterations, int colorOffset);

/* Events*/

int		mouse_interaction(int button, int x, int y, t_fractal *f);
int		key_hook(int key, t_fractal *f);
void	zoom_in(int x, int y, t_fractal *f);
void	zoom_out(int x, int y, t_fractal *f);

/* Utils */

int		destroy(t_fractal *f);

#endif
