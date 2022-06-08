/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:45:46 by mmicheli          #+#    #+#             */
/*   Updated: 2022/06/04 15:28:30 by lykalon          ###   ########.fr       */
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

void	executor(void);
void	cmd_init(t_list **list);

#endif