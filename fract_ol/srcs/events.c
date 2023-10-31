/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tscasso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:31:02 by tscasso           #+#    #+#             */
/*   Updated: 2023/09/13 11:31:03 by tscasso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_hook(int key, t_fractal *f)
{
	if (key == 65307)
		destroy(f);
	else if (key == 65362)
		f->offset_y -= 0.5;
	else if (key == 65364)
		f->offset_y += 0.5;
	else if (key == 65361)
		f->offset_x -= 0.5;
	else if (key == 65363)
		f->offset_x += 0.5;
	else if (key == 32)
		f->coloroffset += 1;
	print_fractal(f);
	return (0);
}

int	mouse_interaction(int button, int x, int y, t_fractal *f)
{
	if (button == 4)
		zoom_in(x, y, f);
	else if (button == 4)
		zoom_out(x, y, f);
	print_fractal(f);
	return (0);
}
