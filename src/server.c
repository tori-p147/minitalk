/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 17:29:47 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/19 18:52:43 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void to_char(char c[])
{
	unsigned char ch;
	int i;

	i = 7;
	while (i-- < 0)
	{
		ch += c[i] << i;
	}
	ft_printf("Server get char: %c\n", ch);
}

extern void	handler(int signo)
{
	char c[8];
	if (signo == SIGUSR1)
	{
		ft_printf("1 was handle");
	}
	else if (signo == SIGUSR2)
	{
		ft_printf("0 was handle");
	}
	if (c[8] != NULL)
		to_char(signo);
}

int	start_server(void)
{
	struct sigaction	act;
	int					catch_sig;
	int					wait_signal;
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
		catch_sig = sigaction(SIGUSR1, &act, NULL);
		if (catch_sig == -1)
			exit(EXIT_FAILURE);
		catch_sig = sigaction(SIGUSR2, &act, NULL);
		if (catch_sig == -1)
			exit(EXIT_FAILURE);
		wait_signal = pause();
		if (wait_signal == -1)
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
