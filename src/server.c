/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 17:29:47 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/24 21:59:59 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

extern void	handler(int signo)
{
	static unsigned char	c = '\0';
	static int				bit_count = 0;

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
}

int	start_server(void)
{
	struct sigaction	act;
	int					wait_signal;
	sigset_t			set;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	act.sa_mask = set;
	act.sa_handler = handler;
	act.sa_flags = 0;
	ft_printf("%d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		wait_signal = pause();
	}
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
