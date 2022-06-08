/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:23:00 by lykalon           #+#    #+#             */
/*   Updated: 2022/06/08 20:23:48 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*extract_env(char **envp)
{
	int		i;
	int		j;
	t_env	*env;
	t_env	*new;
	char	**buff;

	i = 0;
	env = NULL;
	while (envp[i])
	{
		j = 0;
		buff = ft_split(envp[i], '=');
		new = ft_env_new(buff);
		while (buff[j])
		{
			free(buff[j]);
			++j;
		}
		free(buff);
		ft_env_pushback(&env, new);
		++i;
	}
	return (env);
}

t_data	*parser(char *line, char **envp)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->env = extract_env(envp);
	data->redir = extract_redirects();
	data->pipe = extract_pipes();
	return (data);
}
