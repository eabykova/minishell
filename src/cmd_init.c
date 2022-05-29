/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:15:39 by mmicheli          #+#    #+#             */
/*   Updated: 2022/05/29 15:59:34 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cmd_init(t_list **list)
{
	int		i;

	list = (t_list **) malloc(sizeof(t_list));
	printf("here\n");
	if (!list)
		ft_kraft_error("Malloc error in cmd_init. Exit.\n", 1);
	i = -1;
	while (++i < 10)
		ft_lstadd_back(list, ft_lstnew(ft_itoa(i)));
}
