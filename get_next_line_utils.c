/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihiro <akihiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 03:59:54 by akihiro           #+#    #+#             */
/*   Updated: 2026/05/30 22:17:53 by akihiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	check_newline(char *buffer)
{
	int	i;

	if (!buffer)
		return (-1);
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*make_res(char *stash)
{
	char	*res;
	int		len;
	int		i;

	if (!stash || !stash[0])
		return (NULL);
	len = check_newline(stash);
	if (len == -1)
		len = ft_strlen(stash);
	else
		len++;
	i = 0;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = stash[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*copy_to_stash(char *stash, char *buffer)
{
	char	*new_stash;
	int		len_s;
	int		len_b;
	int		i;

	len_s = ft_strlen(stash);
	len_b = ft_strlen(buffer);
	new_stash = malloc(sizeof(char) * (len_s + len_b + 1));
	if (!new_stash)
		return (NULL);
	i = 0;
	while (i < len_s)
	{
		new_stash[i] = stash[i];
		i++;
	}
	while (i < len_s + len_b)
	{
		new_stash[i] = buffer[i - len_s];
		i++;
	}
	new_stash[i] = '\0';
	free(stash);
	return (new_stash);
}

char	*make_newstash(char *stash)
{
	char	*new_stash;
	int		start;
	int		i;

	start = check_newline(stash);
	if (start == -1)
		return (free(stash), NULL);
	start++;
	if (!stash[start])
		return (free(stash), NULL);
	new_stash = malloc(sizeof(char) * (ft_strlen(stash + start) + 1));
	if (!new_stash)
		return (NULL);
	i = 0;
	while (stash[start + i])
	{
		new_stash[i] = stash[start + i];
		i++;
	}
	new_stash[i] = '\0';
	free(stash);
	return (new_stash);
}
