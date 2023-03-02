/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:15:56 by adouay            #+#    #+#             */
/*   Updated: 2023/02/28 22:04:25 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	close_door(t_game *game, t_pos old_pos_map)
{
	if (old_pos_map.x != game->player.map.x
		|| old_pos_map.y != game->player.map.y)
	{
		if (game->map[old_pos_map.y][old_pos_map.x] == '3')
		{
			system("cvlc sounds/close_bar.wav &");
			game->map[old_pos_map.y][old_pos_map.x] = '2';
		}
	}
}

void	near_door(t_game *game)
{
	t_pos	map_ray3;
	float	distance;

	map_ray3.y = game->ray3.px.y;
	map_ray3.x = game->ray3.px.x;
	if (game->ray3.up && game->ray3.wall_h)
		map_ray3.y -= TILE;
	if (game->ray3.left && game->ray3.wall_v)
		map_ray3.x -= TILE;
	distance = hypotenus(game->player.px, game->ray3.px);
	map_ray3.x /= TILE;
	map_ray3.y /= TILE;
	if (distance < 2 * TILE && game->map[map_ray3.y][map_ray3.x] == '2'
		&& game->is_door == FALSE)
	{
		system("cvlc sounds/navi.wav &");	
		game->is_door = TRUE;
	}
	else if (!(distance < 2 * TILE && game->map[map_ray3.y][map_ray3.x] == '2')
		&& game->is_door == TRUE)
		game->is_door = FALSE;
}

void	open_door(t_game *game)
{
	t_pos	map_ray3;
	float	distance;

	map_ray3.y = game->ray3.px.y;
	map_ray3.x = game->ray3.px.x;
	if (game->ray3.up && game->ray3.wall_h)
		map_ray3.y -= TILE;
	if (game->ray3.left && game->ray3.wall_v)
		map_ray3.x -= TILE;
	distance = hypotenus(game->player.px, game->ray3.px);
	map_ray3.x /= TILE;
	map_ray3.y /= TILE;
	if (distance < 2 * TILE && game->map[map_ray3.y][map_ray3.x] == '2')
	{
		game->star_state = 0;
		game->stars_apparead = TRUE;
		system("cvlc sounds/open_bar.wav &");
		game->map[map_ray3.y][map_ray3.x] = '3';
	}
}
