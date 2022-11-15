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
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

int		print_error(char *message);
int		exit_with_error(char *message);
char	*find_path(char **env);

typedef struct s_var {
	int		infile;
	int		outfile;
	int		pid1;
	int		pid2;
	int		fd[2];
	char	*paths;
	char	**cmd_paths;
} t_var;

#endif
