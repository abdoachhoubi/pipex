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

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_contains(envp[i], "PATH") == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

void	execute(char *av, char **env, char **cmd)
{
	int 	i;
	char	*path;
	
	i = -1;
	cmd = ft_split(av, ' ');
	path = find_path(cmd[0], env);
	if (!path)	
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		exit_with_error(3);
	}
	if (execve(path, cmd, env) == -1)
		exit_with_error(4);
}
