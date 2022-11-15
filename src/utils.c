/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:34:21 by aachhoub          #+#    #+#             */
/*   Updated: 2022/11/15 20:34:23 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	ft_contains(char *s, char *sub)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] && sub[j] && s[i + j] == sub[j])
			j++;
		if (!sub[j])
			return (1);
		i++;
	}
	return (0);
}

char	*find_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_contains(env[i], "PATH"))
			return (env[i]);
		i++;
	}
	return (NULL);
}