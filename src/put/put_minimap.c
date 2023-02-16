/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:55:20 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/16 03:43:22 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	put_player(t_game *game)
{
	int	x;
	int	y;

	x = game->player.px.x - (PLAYER_MINIMAP / 2);
	while (x < game->player.px.x + (PLAYER_MINIMAP / 2))
	{
		y = game->player.px.y - (PLAYER_MINIMAP / 2);
		while (y < game->player.px.y + (PLAYER_MINIMAP / 2))
		{
			put_pixel(&game->minimap, x, y, PURPLE);
			y++;
		}
		x++;
	}
}

static void	put_image_tile(t_game *game, int color, int x, int y)
{
	int	x_tile;
	int	y_tile;

	x = x * TILE;
	y = y * TILE;
	y_tile = 0;
	while (y_tile < TILE)
	{
		x_tile = 0;
		while (x_tile < TILE)
		{
			if (x_tile < 1 || x_tile > TILE - 1
				|| y_tile < 1 || y_tile > TILE - 1
				|| x + x_tile == W_MINIMAP - 1 || y + y_tile == H_MINIMAP - 1)
				put_pixel(&game->minimap, x + x_tile, y + y_tile, BLACK);
			else
				put_pixel(&game->minimap, x + x_tile, y + y_tile, color);
			x_tile++;
		}
		y_tile++;
	}
}

void	put_minimap(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '0' || check_player_carac(game->map[y][x]))
				put_image_tile(game, GREEN, x, y);
			else
				put_image_tile(game, BROWN, x, y);
			x++;
		}
		y++;
	}
}
