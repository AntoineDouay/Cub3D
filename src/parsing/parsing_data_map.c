/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_data_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:53:26 by ilandols          #+#    #+#             */
/*   Updated: 2023/02/24 21:12:25 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	check_array_sprite_content(t_game *game)
{
	int	i;

	i = 0;
	while (game->sprite[i])
		i++;
	if (i != 6)
		free_all_and_exit(game, "Missing informations\n");
}

void	check_sprite(t_game *game, char **file_content)
{
	int	i;
	int	tmp;
	int	index;

	i = 0;
	game->sprite = ft_calloc(sizeof(char *), (6 + 1));
	verify_alloc(game, game->sprite);
	index = enum_check(file_content[i]);
	while (file_content[i] && (index != ERROR || file_content[i][0] == '\n'))
	{
		index = enum_check(file_content[i]);
		if (index != ERROR)
		{
			if (!game->sprite[index])
			{
				
				game->sprite[index] = ft_strcut_right(file_content[i], ' ');
				tmp = 0;
				while (game->sprite[index][tmp] != '\n')
					tmp++;
				game->sprite[index][tmp] = '\0';
				verify_alloc(game, game->sprite[index]);
			}
			else
				free_all_and_exit(game, "Doublon\n");
		}
		i++;
	}
	check_array_sprite_content(game);
}

static void	assign_rgb_value(t_game *game, char **values, int trgt[3])
{
	int	i;
	int	value;

	i = 0;
	while (i < 3)
	{
		value = ft_atoi(values[i]);
		if (ft_str_isdigit(values[i]) && value >= 0 && value <= 255)
			trgt[i] = value;
		else
		{
			ft_free_array(values);
			free_all_and_exit(game, "RGB value is invalid\n");
		}
		i++;
	}
}

int	get_color_to_rgb(t_game *game, char *rgb_code, t_bool color_sky)
{
	char	**values;
	int		rgb[3];
	int		result;

	values = ft_split(rgb_code, ", CF\n");
	verify_alloc(game, values);
	if (ft_get_size_array(values) != 3)
	{
		ft_free_array(values);
		values = NULL;
		if (!color_sky)
			free_all_and_exit(game, "RGB value is invalid 1\n");
		else
			game->image_sky = TRUE;
	}
	if (values)
	{
		assign_rgb_value(game, values, rgb);
		ft_free_array(values);
	}
	result = rgb[0] * 65536 + rgb[1] * 256 + rgb[2];
	return (result);
}
