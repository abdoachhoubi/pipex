/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:07:25 by aachhoub          #+#    #+#             */
/*   Updated: 2022/11/15 17:07:21 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	child_process(char **av, char **env, int *fd, char **cmd)
{
	int	filein;

	filein = open(av[1], O_RDONLY);
	if (filein == -1)
		exit_with_error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	execute(av[2], env, cmd);
}

void	parent_process(char **av, char **env, int *fd, char **cmd)
{
	int	fileout;

	fileout = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		exit_with_error();
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	execute(av[3], env, cmd);
}

int	main(int ac, char **av, char **env)
{
	t_var	var;

	if (ac != 5)
		return (print_error("\033[1;31mError: Bad arguments!\033[0m"));
	else
	{
		if (pipe(var.fd) == -1)
			exit_with_error();
		var.pid = fork();
		if (var.pid == -1)
			exit_with_error();
		if (var.pid == 0)
			child_process(av, env, var.fd, var.cmd);
		else
			parent_process(av, env, var.fd, var.cmd);
	}
	sleep(100);
}
