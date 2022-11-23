/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:49:38 by aachhoub          #+#    #+#             */
/*   Updated: 2022/11/21 16:49:39 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	child_process(char *av, char **env, char **cmd)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		exit_with_error();
	pid = fork();
	if (pid == -1)
		exit_with_error();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(av, env, cmd);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	here_doc(char *limiter, int ac)
{
	pid_t	reader;
	int		fd[2];
	char	*line;

	if (ac < 6)
		exit_with_error();
	if (pipe(fd) == -1)
		exit_with_error();
	reader = fork();
	if (reader == 0)
	{
		close(fd[0]);
		while (get_next_line(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

int	main(int ac, char **av, char **env)
{
	t_var   var;

	if (ac < 5)
	{
		return (print_error("\033[1;31mError: Bad arguments!\033[0m"));
	}
    else
    {
        if (ft_contains(av[1], "here_doc"))
		{
			var.args = 3;
			var.outfile = open_file(av[ac - 1], 0);
			here_doc(av[2], ac);
		}
		else
		{
			var.args = 2;
			var.outfile = open_file(av[ac - 1], 1);
			var.infile = open_file(av[1], 2);
			dup2(var.infile, STDIN_FILENO);
		}
		while (var.args < ac - 2)
			child_process(av[(var.args)++], env, var.cmd);
		dup2(var.outfile, STDOUT_FILENO);
		execute(av[ac - 2], env, var.cmd);
    }
}
