/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:50:05 by mmicheli          #+#    #+#             */
/*   Updated: 2022/06/02 19:10:32 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	perror_exit(char *error)
{
	perror(error);
	exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	t_ppx	pipex;

	if (argc == 5)
	{
		printf("Hello, I'm minishell!\n");
		pipex.in_fil = open(argv[1], O_RDONLY);
		if (pipex.in_fil < 0)
			perror_exit(ERROR_INFILE);
		pipex.out_fil = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (pipex.out_fil < 0)
			perror_exit(ERROR_OUTFILE);
		cmd_init(&pipex, envp);
		executor(&pipex, envp);
	}
	else
	{
		if (argc < 5)
			printf(TOO_FEW_ARGS);
		else
			printf (TOO_MUCH_ARGS);
	}
}

//int	main(int argc, char **argv, char **envp)
//{
//	char	*fl[3];
//
//	fl[0] = malloc(3);
//	fl[0] = "ls\0";
//	fl[1] = malloc(3);
//	fl[1] = "-a\0";
//	fl[2] = NULL;
//	execve("/bin/ls", fl, envp);
//}
