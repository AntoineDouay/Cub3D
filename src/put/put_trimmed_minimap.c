/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_trimmed_minimap.c                                  :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:11:34 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/16 17:46:09 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static	t_bool	is_outside_map(t_game *game, t_pos start, int x, int y)
{
	t_pos	target;

	target.x = start.x / TILE_MINIMAP;
	target.y = start.y / TILE_MINIMAP;
	if (start.y < 0 || start.y >= TILE_MINIMAP * game->size_map.y / TILE)
		return (TRUE);
	else if (start.x < 0 || target.x > ft_strlen(game->map[target.y]))
		return (TRUE);
	else if (!game->map[target.y][target.x] || game->map[target.y][target.x] == ' ')
	{
		if (start.x % TILE_MINIMAP == 0 && game->map[target.y][target.x - 1] == '1' && start.x < game->size_map.x)
			return (FALSE);
		else if (start.y % TILE_MINIMAP == 0 && target.y > 0 && game->map[target.y - 1][target.x] == '1')
			return (FALSE);
		return (TRUE);
	}
	return (FALSE);
}

void	put_trimmed_minimap(t_game *game)
{
	t_pos	start;
	t_pos	tmp;
	int	x;
	int	y;
	int	color;

	start.y = (TILE_MINIMAP * (game->player.px.y / TILE)) - TILE_MINIMAP * 2;
	y = 0;
	while (y < (TILE_MINIMAP * (game->player.px.y / TILE)) + TILE_MINIMAP * 2 + TILE_MINIMAP)
	{
		x = 0;
		start.x = (TILE_MINIMAP * (game->player.px.x / TILE)) - TILE_MINIMAP * 2;
		while (x < (TILE_MINIMAP * (game->player.px.x / TILE)) + TILE_MINIMAP * 2 + TILE_MINIMAP)
		{
			// printf("tx = %d | ty = %d\n", start.x, start.y);
			if (x == 0 || x == TMP_MAP - 1 || y == 0 || y == TMP_MAP - 1)
				put_pixel(&game->minimap, x, y, BLACK);
			else if (is_outside_map(game, start, x, y))
				put_pixel(&game->minimap, x, y, SKY);
			else
			{
				color = *(int *)(game->full_minimap.addr + start.y * game->full_minimap.line + start.x * 4);
				put_pixel(&game->minimap, x, y, color);
			}
			x++;
			start.x++;
		}
		y++;
		start.y++;
	}
	put_point(game, TMP_MAP / 2, TMP_MAP / 2, PURPLE);
	put_raycasting_minimap(game, game->player.angle + to_rad(FOV / 2), game->ray1.px);
	put_raycasting_minimap(game, game->player.angle - to_rad(FOV / 2), game->ray2.px);
	put_image(&game->render, &game->minimap, TILE_MINIMAP, TILE_MINIMAP);

}