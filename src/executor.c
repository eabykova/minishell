/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:36:29 by mmicheli          #+#    #+#             */
/*   Updated: 2022/06/02 19:10:32 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	first_child(t_ppx *pipex, char *cmd_1, char **envp)
{
	char	*fl[2];

	printf("Into first_child proc\n");
	fl[0] = malloc(4);
	fl[0] = "cat\0";
	fl[1] = NULL;
	dup2(pipex->end[1], STDOUT_FILENO);
	close(pipex->end[0]);
	dup2(pipex->in_fil, STDIN_FILENO);
	close(pipex->in_fil);
	execve("/bin/cat", fl, envp);
	printf("Will not see in terminal\n");
}

static void	second_child(t_ppx *pipex, char *cmd_1, char **envp)
{
	char	*fl[3];

	printf("Into second_child proc\n");
	fl[0] = malloc(3);
	fl[0] = "ls\0";
	fl[1] = malloc(4);
	fl[1] = "-la\0";
	fl[2] = NULL;
	dup2(pipex->end[0], STDIN_FILENO);
	close(pipex->end[1]);
	dup2(pipex->out_fil, STDOUT_FILENO);
	execve("/bin/ls", fl, envp);
}

static void	parent_proc(t_ppx *pipex, char *cmd_2)
{
	int	status;

	waitpid(-1, &status, 0);
	printf("Into parent proc\n");
//	dup2();
}

void	executor(t_ppx *pipex, char **envp)
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
		first_child(pipex, cmd_1, envp);
	pipex->pid_2 = fork();
	if (pipex->pid_2 == -1)
		perror_exit(FORK_ERROR);
	if (pipex->pid_2 == 0)
		second_child(pipex, cmd_1, envp);
	else
		parent_proc(pipex, cmd_2);
}
