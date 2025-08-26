/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 17:29:47 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/26 14:37:21 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signo)
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

	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	act.sa_handler = handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
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
