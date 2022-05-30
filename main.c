/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:50:05 by mmicheli          #+#    #+#             */
/*   Updated: 2022/05/30 16:48:13 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_list	**cmd_list;

	printf("Hello, I'm minishell!\n");
//	cmd_init(cmd_list);
//	while (cmd_list)
//	{
//		ft_printf("%d\n", (*cmd_list)->content);
//		cmd_list++;
//	}
//	infile_to_cmd1();
//	cmd1_to_cmd2(envp);
	cmd2_to_out();
}
