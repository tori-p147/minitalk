/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 17:29:47 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/17 22:12:39 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	server_handler(int sig_num)
{
	if (sig_num == 1)
	{
		ft_printf("sig1 was handle");
	}
	else if (sig_num == 2)
	{
		ft_printf("sig1 was handle");
	}
}

void	init_server(t_server *server)
{
	server->pid = "12345\n";
}

int	start_server(void)
{
	t_server			server;
	struct sigaction	sa;
	int					server_up;

	sa.sa_handler = server_handler;
	init_server(&server);
	ft_printf("%s", server.pid);
	while (1)
	{
		server_up = sigaction(1, &sa, NULL);
		if (-1)
		{
			ft_printf("Error\n");
			return (1);
		}
		server_up = sigaction(2, &sa, NULL);
		if (-1)
		{
			ft_printf("Error\n");
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	start_server();
	return (0);
}
