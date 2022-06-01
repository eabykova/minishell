/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:36:29 by mmicheli          #+#    #+#             */
/*   Updated: 2022/06/01 18:32:42 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	child_proc(t_ppx *pipex, char *cmd_1)
{
	printf("Into child proc\n");
	printf("pipex->in_fil = %d\n", pipex->in_fil);
	printf("cmd_1 = %s\n", cmd_1);
	dup2(STDIN_FILENO, pipex->end[0]);
	close(pipex->end[0]);
}

static void	parent_proc(t_ppx *pipex, char *cmd_2)
{
	int	status;

	waitpid(-1, &status, 0);
	printf("Into parent proc\n");
	printf("pipex->out_fil = %d\n", pipex->out_fil);
	printf("cmd_2 = %s\n", cmd_2);
//	dup2();
}

void	executor(t_ppx *pipex)
{
	char	cmd_1[5] = "ls -a";
	char	cmd_2[5] = "wc -l";

	printf("Into executor\n");
	if (pipe(pipex->end) < 0)
		perror_exit(PIPE_ERROR);
	pipex->pid_1 = fork();
	if (pipex->pid_1 == -1)
		perror_exit(FORK_ERROR);
	if (pipex->pid_1 == 0)
		child_proc(pipex, cmd_1);
	else
		parent_proc(pipex, cmd_2);
}
