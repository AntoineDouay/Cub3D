/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:57:44 by ilandols          #+#    #+#             */
/*   Updated: 2023/03/11 23:03:52 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	put_star_indicator(t_game *game)
{
	static int	tmp;

	if (tmp >= 12)
		tmp = 0;
	if (tmp < 3)
		put_image(&game->render, &game->star[0], WIDTH / 2, HEIGHT / 2);
	else if (tmp >= 3 && tmp < 6)
		put_image(&game->render, &game->star[1], WIDTH / 2, HEIGHT / 2);
	else if (tmp >= 6 && tmp < 9)
		put_image(&game->render, &game->star[2], WIDTH / 2, HEIGHT / 2);
	else if (tmp >= 9)
		put_image(&game->render, &game->star[1], WIDTH / 2, HEIGHT / 2);
	tmp++;
}

void	put_render(t_game *game)
{
	if (game->image_sky)
		put_sky_image(game);
	else
		put_sky_color(game);
	put_environnement(game);
	if (game->stars_apparead)
		put_multiple_stars(game);
	put_minimap(game);
	near_door(game);
	if (game->is_door)
		put_star_indicator(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->render.img, 0, 0);
}
