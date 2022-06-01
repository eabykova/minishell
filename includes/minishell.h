/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:45:46 by mmicheli          #+#    #+#             */
/*   Updated: 2022/06/01 18:39:39 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../lib/libft.h"

# define ERROR_INFILE "Error in infile opening.\n"
# define ERROR_OUTFILE "Error in outfile opening.\n"
# define TOO_FEW_ARGS "Too few arguments. Try again.\n"
# define TOO_MUCH_ARGS "Too much arguments. Try again.\n"
# define PIPE_ERROR "Error in pipe.\n"
# define FORK_ERROR "Error in fork.\n"

typedef struct s_ppx
{
	int		in_fil;
	int		out_fil;
	int		end[2];
	pid_t	pid_1;
	pid_t	pid_2;
}				t_ppx;

void	executor(t_ppx *pipex);
void	cmd_init(t_ppx *pipex, char **envp);

void	perror_exit(char *error);

#endif