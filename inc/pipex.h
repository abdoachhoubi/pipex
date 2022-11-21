/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:07:50 by aachhoub          #+#    #+#             */
/*   Updated: 2022/11/15 17:02:53 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/libft.h"

int		exit_with_error(void);
int		print_error(char *message);
char	*find_path(char *cmd, char **env);
int		ft_contains(char *s, char *sub);
void	child_process(char **av, char **env, int *fd, char **cmd);
void	parent_process(char **av, char **env, int *fd, char **cmd);
void	execute(char *av, char **env, char **cmd);

typedef struct s_var {
	int		infile;
	int		outfile;
	pid_t	pid;
	int		fd[2];
	char	**cmd;
}	t_var;

#endif
