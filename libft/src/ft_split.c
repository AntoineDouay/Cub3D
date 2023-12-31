/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:44:13 by ilandols          #+#    #+#             */
/*   Updated: 2023/03/12 17:20:21 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static int	get_size_word(char const *s, char *charset, int index)
{
	int	result;

	result = 0;
	while (s[index] && is_charset(s[index], charset))
		index++;
	while (s[index] && !is_charset(s[index], charset))
	{
		result++;
		index++;
	}
	return (result);
}

static char	*get_word(char const *s, char *charset, int *index, int size_word)
{
	int		j;
	char	*result;

	j = 0;
	result = malloc((size_word + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (s[*index] && is_charset(s[*index], charset))
		*index += 1;
	while (s[*index] && !is_charset(s[*index], charset))
	{
		result[j] = s[*index];
		j++;
		*index += 1;
	}
	result[j] = '\0';
	return (result);
}

static int	count_words(char const *s, char *charset)
{
	int	result;
	int	i;

	if (!s || !s[0])
		return (0);
	if (!charset)
		return (1);
	result = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] && !is_charset(s[i], charset) && is_charset(s[i + 1], charset))
			result++;
		i++;
	}
	if (!is_charset(s[i - 1], charset))
		result++;
	return (result);
}

char	**ft_split(char const *s, char *charset)
{
	char	**array;
	int		words;
	int		i;
	int		j;
	int		size_word;

	words = count_words(s, charset);
	array = malloc((words + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	j = 0;
	while (i < words)
	{
		size_word = get_size_word(s, charset, j);
		array[i] = get_word(s, charset, &j, size_word);
		if (!array[i])
		{
			ft_free_array(array);
			return (NULL);
		}
		i++;
	}
	array[words] = NULL;
	return (array);
}
