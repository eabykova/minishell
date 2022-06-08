/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:36:29 by mmicheli          #+#    #+#             */
/*   Updated: 2022/06/08 17:43:38 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	first_child(t_ppx *pipex, char *cmd, char **envp)
{
	printf("Into first_child proc\n");
	dup2(pipex->end[1], STDOUT_FILENO);
	close(pipex->end[0]);
	dup2(pipex->in_fil, STDIN_FILENO);
	close(pipex->in_fil);
	execve("/bin/ls", ft_split(cmd, ' '), envp);
	printf("Will not see it in terminal\n");
}

static void	second_child(t_ppx *pipex, char *cmd, char **envp)
{
	printf("Into second_child proc\n");
	dup2(pipex->end[0], STDIN_FILENO);
	close(pipex->end[1]);
	dup2(pipex->out_fil, STDOUT_FILENO);
	execve("/bin/ls", ft_split(cmd, ' '), envp);
}

static void	parent_proc(t_ppx *pipex, char *cmd_2)
{
	int	status;

	waitpid(-1, &status, 0);
	printf("Into parent proc\n");
//	dup2();
}

void	executor(t_ppx *pipex,	char **argv, char **envp)
{
	printf("Into executor\n");
	if (pipe(pipex->end) < 0)
		perror_exit(PIPE_ERROR);
	pipex->pid_1 = fork();
	if (pipex->pid_1 == -1)
		perror_exit(FORK_ERROR);
	if (pipex->pid_1 == 0)
		first_child(pipex, argv[1], envp);
	pipex->pid_2 = fork();
	if (pipex->pid_2 == -1)
		perror_exit(FORK_ERROR);
	if (pipex->pid_2 == 0)
		second_child(pipex, argv[2], envp);
//	else
//		parent_proc(pipex, cmd_2);
}
