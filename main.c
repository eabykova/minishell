/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:50:05 by mmicheli          #+#    #+#             */
/*   Updated: 2022/06/01 14:54:02 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	int	in_fil;
	int	out_fil;

	if (argc == 5)
	{
		printf("Hello, I'm minishell!\n");
		in_fil = open(argv[1], O_RDONLY);
		if (in_fil < 0)
			ft_kraft_error("Error in in_fil opening.\n", 1);
		out_fil = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (out_fil < 0)
			ft_kraft_error("Error in out_fil opening.\n", 1);
		cmd_init();
		executor();
	}
	else
	{
		if (argc < 5)
			printf("Too few arguments. Try again.\n");
		else
			printf ("Too much arguments. Try again.\n");
	}
}
