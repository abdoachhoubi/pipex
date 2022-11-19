/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:50:31 by aachhoub          #+#    #+#             */
/*   Updated: 2022/11/15 16:06:04 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	print_error(char *message)
{
	ft_putendl_fd(message, 2);
	return (1);
}

int	exit_with_error(int nb)
{
	ft_printf("Error found in: %d\n", nb);
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}
