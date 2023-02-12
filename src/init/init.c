/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:43:19 by adouay            #+#    #+#             */
/*   Updated: 2023/02/12 13:21:26 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	init_player_struct(t_game *game)
{
	game->player.map_x = 0;
	game->player.map_y = 0;
	game->player.px_x = 0;
	game->player.px_y = 0;
	game->player.angle = to_rad(FOV);
	game->player.dir_x = cos(game->player.angle) * TILE;
	game->player.dir_y = -sin(game->player.angle) * TILE;
}

static void	init_game_struct(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->map = NULL;
	game->sprite = NULL;
	game->fd = -1;
	game->file_content = NULL;
	game->move_up = FALSE;
	game->move_right = FALSE;
	game->move_down = FALSE;
	game->move_left = FALSE;
	game->move_dir_left = FALSE;
	game->move_dir_right = FALSE;

	game->ray.x = 0;
	game->ray.y = 0;
	game->ray.offset_x = 0;
	game->ray.offset_y = 0;
	game->ray.angle = 0;

	game->ray2.x = 0;
	game->ray2.y = 0;
	game->ray2.offset_x = 0;
	game->ray2.offset_y = 0;
	game->ray2.angle = 0;
}

void	init(t_game *game)
{
	init_game_struct(game);
	init_player_struct(game);
}
