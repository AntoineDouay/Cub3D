/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:36:12 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/16 18:01:23 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	init_mlx_addr(t_game *game)
{
	game->render.addr = mlx_get_data_addr(game->render.img,
			&game->render.bpp, &game->render.line, &game->render.end);
	verify_alloc(game, game->render.addr);
	game->minimap.addr = mlx_get_data_addr(game->minimap.img,
			&game->minimap.bpp, &game->minimap.line, &game->minimap.end);
	verify_alloc(game, game->minimap.addr);
	game->environnement.addr = mlx_get_data_addr(game->environnement.img,
			&game->environnement.bpp, &game->environnement.line, &game->environnement.end);
	verify_alloc(game, game->environnement.addr);
	game->new_minimap.addr = mlx_get_data_addr(game->new_minimap.img,
			&game->new_minimap.bpp, &game->new_minimap.line, &game->new_minimap.end);
	verify_alloc(game, game->new_minimap.addr);
}

static void	init_mlx_img(t_game *game)
{
	game->render.img = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	verify_alloc(game, game->render.img);
	game->render.width = WIDTH;
	game->render.height = HEIGHT;
	game->minimap.img = mlx_new_image(game->mlx_ptr, game->size_map.x, game->size_map.y);
	verify_alloc(game, game->minimap.img);
	game->minimap.width = game->size_map.x;
	game->minimap.height = game->size_map.y;
	game->environnement.img = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	verify_alloc(game, game->environnement.img);
	game->environnement.width = WIDTH;
	game->environnement.height = HEIGHT;
	game->new_minimap.img = mlx_new_image(game->mlx_ptr, MINIMAP,  MINIMAP);
	verify_alloc(game, game->new_minimap.img);
	game->new_minimap.width = MINIMAP;
	game->new_minimap.height = MINIMAP;

}

void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	verify_alloc(game, game->mlx_ptr);
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	verify_alloc(game, game->win_ptr);
	init_mlx_img(game);
	init_mlx_addr(game);
	mlx_hook(game->win_ptr, 2, 1L << 0, key_press, game);
	mlx_hook(game->win_ptr, 3, 1L << 1, key_release, game);
	draw_minimap(game);
	mlx_hook(game->win_ptr, 17, 0, mlx_loop_end, game->mlx_ptr);
	mlx_loop_hook(game->mlx_ptr, run, game);
	mlx_loop(game->mlx_ptr);
}
