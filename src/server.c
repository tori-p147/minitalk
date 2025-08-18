/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 17:29:47 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/18 18:12:11 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

extern void	handler(int signo)
{
	if (signo == SIGUSR1)
	{
		ft_printf("sig1 was handle");
	}
	else if (signo == SIGUSR2)
	{
		ft_printf("sig1 was handle");
	}
}

int	start_server(void)
{
	struct sigaction	act;
	int					server_up;
	int					is_sig_handle;
	sigset_t			set;
	pid_t				server_pid;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	act.sa_mask = set;
	act.sa_handler = handler;
	act.sa_flags = 0;
	while (1)
	{
		server_pid = getpid();
		ft_printf("%d\n", server_pid);
		server_up = sigaction(SIGUSR1, &act, NULL);
		if (server_up == -1)
		{
			ft_printf("Error\n");
			return (1);
		}
		server_up = sigaction(SIGUSR2, &act, NULL);
		if (server_up == -1)
		{
			ft_printf("Error\n");
			return (1);
		}
		is_sig_handle = pause();
		if (is_sig_handle == -1)
			exit(EXIT_FAILURE);
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
