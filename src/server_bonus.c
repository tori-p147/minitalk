/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 17:29:47 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/26 14:36:21 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_with_info(int signo, siginfo_t *info, void *context)
{
	static unsigned char	c = '\0';
	static int				bit_count = 0;

	(void)context;
	c <<= 1;
	if (signo == SIGUSR1)
		c |= 1;
	else if (signo == SIGUSR2)
		c |= 0;
	bit_count++;
	if (bit_count == 8)
	{
		ft_printf("%c", c);
		bit_count = 0;
		c = '\0';
	}
	if (signo == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (signo == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}

void	set_sig_handler_with_client_info(void)
{
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = handler_with_info;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

int	start_server(void)
{
	set_sig_handler_with_client_info();
	ft_printf("PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	if (start_server())
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}
