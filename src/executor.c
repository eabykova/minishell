/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:36:29 by mmicheli          #+#    #+#             */
/*   Updated: 2022/05/30 16:53:58 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	executor()

void	infile_to_cmd1(void)
{
	int	fd;

	fd = open("in.txt", O_RDONLY);
	dup2(fd, STDIN_FILENO);
	close(fd);
	execlp("grep", "grep", "ru", NULL);
}

void	cmd1_to_cmd2(char **envp)
{
	char	ls[] = "/usr/bin/wc";
	char	grep[] = "/usr/bin/grep";
	int		fd[2];
	int		id1;
	int		id2;
	char	**cmd1;
	char	**cmd2;

	pipe(fd);
	id1 = fork();
	if (id1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		cmd1 = (char **)malloc(sizeof(char *) * 2);
		cmd1[0] = ft_strdup("wc");
		cmd1[1] = ft_strdup("-l");
		cmd1[2] = NULL;
		if (execve(ls, cmd1, envp))
			printf("Something going wrong in process number one\n");
	}
	id2 = fork();
	if (id2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		close(fd[0]);
		cmd2 = (char **) malloc(sizeof(char *) * 2);
		cmd1[0] = ft_strdup("grep");
		cmd1[1] = ft_strdup("ru");
		cmd1[2] = NULL;
		execve(grep, cmd2, envp);
		printf("Something going wrong in process number two\n");
	}
	if (id1 != 0)
	{
		close(fd[0]);
		close(fd[1]);
	}
	if (id2 != 0)
	{
		close(fd[0]);
		close(fd[1]);
	}
	waitpid(id1, NULL, 0);
	waitpid(id2, NULL, 0);
}

void	cmd2_to_out(void)
{
	int	fd;

	fd = open("out.txt", O_WRONLY | O_CREAT, 0777);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	execlp("ping", "ping", "-c", "3", "ya.ru", NULL);
}

void	executor_0(char *argv)
{
	int pipefd[2];
	pid_t cpid;
	char buf;

	if (pipe(pipefd) == -1) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	cpid = fork();
	if (cpid == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (cpid == 0) {    /* Потомок читает из канала */
		close(pipefd[1]);          /* Закрывает неиспользуемый конец для записи */
		while (read(pipefd[0], &buf, 1) > 0)
			write(STDOUT_FILENO, &buf, 1);
		write(STDOUT_FILENO, "\n", 1);
		close(pipefd[0]);
		_exit(EXIT_SUCCESS);
	}
	else
	{            /* Родитель пишет значение argv[1] в канал */
		close(pipefd[0]);          /* Закрывает неиспользуемый конец для чтения */
		write(pipefd[1], argv, ft_strlen(argv));
		close(pipefd[1]);          /* Читатель видит EOF */
		wait(NULL);                /* Ожидание потомка */
		exit(EXIT_SUCCESS);
	}
}
