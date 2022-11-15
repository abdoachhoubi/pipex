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

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_var	var;

	if (ac != 5)
		return (print_error("\033[1;31mError:\033[0m Wrong number of arguments"));
	else
	{
		var.outfile = open(av[ac - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
		if (var.outfile == -1)
			return (print_error("\033[1;31mError:\033[0m Couldn't open outfile"));
		if (pipe(var.fd) == -1)
			return (print_error("\033[1;31mError:\033[0m Couldn't create pipe"));
		var.paths = find_path(env);
		ft_printf("%s\n", var.paths);
		var.cmd_paths = ft_split(var.paths, ':');
		var.pid1 = fork();
		if (var.pid1 == 0)
			first_child(var, av, env);
		var.pid2 = fork();
		if (var.pid2 == 0)
			second_child(var, av, env);
		close_pipes(&pipex);
		waitpid(var.pid1, NULL, 0);
		waitpid(var.pid2, NULL, 0);
		free_var(&var);
		return (0);
	}
	system("leaks pipex");
}
