/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tscasso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:29:24 by tscasso           #+#    #+#             */
/*   Updated: 2023/09/13 11:29:25 by tscasso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	calculatecolorindex(int iterations, int coloroffset)
{
	int	palettesize;
	int	colorindex;
	int	colorpalette[7];

	ft_memmove(colorpalette, (int []){0x00D96240, 0x001A9933, 0x002fa590,
		0x00f1f29a, 0x00d02c02, 0x007A39AA, 0x0057BAC6}, 7 * sizeof(int));
	palettesize = 7;
	colorindex = (iterations + coloroffset) % palettesize;
	if (colorindex < 0)
		colorindex += palettesize;
	return (colorpalette[colorindex]);
}
