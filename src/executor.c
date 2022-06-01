/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:36:29 by mmicheli          #+#    #+#             */
/*   Updated: 2022/06/01 14:39:19 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	child_proc(void)
{
	ft_printf("Into child proc\n");
}

static void	parent_proc(void)
{
	ft_printf("Into parent proc\n");
}

void	executor(void)
{
	pid_t	pid;
	int		end[2];

	ft_printf("Into executor\n");
	pipe(end);
	pid = fork();
	if (pid == -1)
		ft_kraft_error("Error in fork\n", EXIT_FAILURE);
	if (pid == 0)
		child_proc();
	else
		parent_proc();
}
