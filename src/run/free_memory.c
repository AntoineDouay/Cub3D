/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:25:47 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/19 00:01:20 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	verify_alloc(t_game *game, void *ptr)
{
	if (!ptr)
		free_all_and_exit(game, ERROR_MALLOC);
}

void	free_all_elements(t_game *game)
{
	if (game->fd != -1)
		close(game->fd);
	if (game->sprite)
		ft_free_array_size(game->sprite, 7);
	if (game->file_content)
		ft_free_array(game->file_content);
	if (game->map)
		ft_free_array(game->map);
	if (game->minimap.img)
		mlx_destroy_image(game->mlx_ptr, game->minimap.img);
	if (game->environnement.img)
		mlx_destroy_image(game->mlx_ptr, game->environnement.img);
	if (game->render.img)
		mlx_destroy_image(game->mlx_ptr, game->render.img);
	if (game->trimmed_minimap.img)
		mlx_destroy_image(game->mlx_ptr, game->trimmed_minimap.img);
	if (game->north.img)
		mlx_destroy_image(game->mlx_ptr, game->north.img);
	if (game->south.img)
		mlx_destroy_image(game->mlx_ptr, game->south.img);
	if (game->east.img)
		mlx_destroy_image(game->mlx_ptr, game->east.img);
	if (game->west.img)
		mlx_destroy_image(game->mlx_ptr, game->west.img);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);

	if (game->north_a[0].img)
		mlx_destroy_image(game->mlx_ptr, game->north_a[0].img);
	if (game->north_a[1].img)
		mlx_destroy_image(game->mlx_ptr, game->north_a[1].img);
	if (game->north_a[2].img)
		mlx_destroy_image(game->mlx_ptr, game->north_a[2].img);
	if (game->north_a[2].img)
		mlx_destroy_image(game->mlx_ptr, game->north_a[3].img);


	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
}

void	free_all_and_exit(t_game *game, char *str_error)
{
	free_all_elements(game);
	if (str_error)
		perror(str_error);
	exit(EXIT_FAILURE);
}
