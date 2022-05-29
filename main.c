/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:50:05 by mmicheli          #+#    #+#             */
/*   Updated: 2022/05/29 15:59:34 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	main(void)
{
	t_list	**cmd_list;

	printf("Hello, I'm minishell!\n");
	cmd_init(cmd_list);
	while (cmd_list)
	{
		ft_printf("%d\n", (*cmd_list)->content);
		cmd_list++;
	}
	executor();
}
