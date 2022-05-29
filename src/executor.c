/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:36:29 by mmicheli          #+#    #+#             */
/*   Updated: 2022/05/29 20:51:00 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	executor(void)
{
	int	fd;

	ft_printf("Into executor\n");
	fd = open("func_pipex.txt", O_RDONLY);

}
