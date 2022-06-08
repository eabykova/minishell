/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:20:52 by lykalon           #+#    #+#             */
/*   Updated: 2022/06/08 20:23:48 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*ft_new_env(char **buff)
{
	t_env	*new;
	char	*temp;

	check_for_buff_lenght();
	new = malloc(sizeof(t_env));
	new->key = ft_strdup(buff[0]);
	new->value = ft_strdup(buff[1]);
//	if lenght > 2 -?;
//	temp = new->value;
//	new->value = ft_strjoin(temp, '=');
//	free(temp);
//	temp = new->value;
//	new->value = ft_strjoin(temp, buff[2]);
//	free(temp);
	new->next = NULL;
	return (new);
}

void	ft_env_pushback(t_env **first, t_env *item)
{
	t_env	*temp;

	temp = *first;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = item;
}
