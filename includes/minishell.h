/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:45:46 by mmicheli          #+#    #+#             */
/*   Updated: 2022/06/08 20:40:03 by mmicheli         ###   ########.fr       */
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
# define SPLIT_ERROR "Error in ft_split.\n"

typedef struct s_ppx
{
	int		in_fil;
	int		out_fil;
	int		end[2];
	pid_t	pid_1;
	pid_t	pid_2;
	char	**path;
	char	**cmd_args;
	char	*cmd;
}				t_ppx;

typedef struct s_env
{
	char			*key;
	void			*value;
	struct s_env	*next;
}			t_env;

typedef struct s_command
{
	char				*token;
	struct s_command	*next;
}			t_command;

typedef struct s_pipe
{
	t_command		*command;
	struct s_pipe	*next;
}			t_pipe;

typedef struct s_redir
{
	char	*in;
	char	*out;
	char	*heredoc;
	char	*another_one;
}			t_redir;

typedef struct s_data
{
	t_env	*env;
	t_pipe	*pipe;
	t_redir	*redir;
}			t_data;

void	executor(t_ppx *pipex,	char **argv, char **envp);
void	env_init(t_ppx *pipex, char **envp);
//void	cmd_init(t_ppx *pipex, char *cmd);

void	perror_exit(char *error);

#endif