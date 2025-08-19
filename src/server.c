/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 17:29:47 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/19 21:32:26 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*to_char(int signo)
{
	ft_printf("Server get sig: %d\n", signo);
	return ("!\n");
}

extern void	handler(int signo)
{
	char	*c;
	int		counter;

	counter = 0;
	if (signo == SIGUSR1)
	{
		ft_printf("1 was handle");
		counter++;
	}
	else if (signo == SIGUSR2)
	{
		ft_printf("0 was handle");
		counter++;
	}
	c = to_char(signo);
	ft_printf("handle c in handler %c\n", c);

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
