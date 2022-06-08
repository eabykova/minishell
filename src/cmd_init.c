/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:15:39 by mmicheli          #+#    #+#             */
/*   Updated: 2022/06/08 19:16:47 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	env_init(t_ppx *pipex, char **envp)
{
	while (ft_strncmp(*envp, "PATH", 4))
		envp++;
	pipex->path = ft_split(*envp, ':');
	if (pipex->path == NULL)
		perror_exit(SPLIT_ERROR);
}
