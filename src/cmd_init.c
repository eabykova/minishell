/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:15:39 by mmicheli          #+#    #+#             */
/*   Updated: 2022/06/08 17:41:56 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	env_init(t_ppx *pipex, char **envp)
{
	while (ft_strncmp(*envp, "PATH", 4))
		envp++;
//	printf("%s", *envp);
	pipex->path = ft_split(*envp, ':');
	if (pipex->path == NULL)
		perror_exit(SPLIT_ERROR);
//	while (*pipex->path != NULL)
//		printf("%s\n", *pipex->path++);
}
