/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:36:29 by mmicheli          #+#    #+#             */
/*   Updated: 2022/05/30 18:18:40 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	executor(void)
{
	int	pid;

	ft_printf("Into executor\n");
	pid = fork();
	if (pid == -1)
		ft_kraft_error("Error in fork\n", EXIT_FAILURE);
	if (pid == 0)
	{
		ft_printf("Into child proc, pid = %d\n", pid);
	}
	else
	{
		ft_printf("Into parent proc, pid = %d\n", pid);
	}
}
