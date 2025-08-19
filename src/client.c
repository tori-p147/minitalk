/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 17:29:45 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/19 22:07:00 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, unsigned char c)
{
	int	i;
	int sig;
	int is_success;

	i = 7;
	ft_printf("c = %c\n", c);
	while (i-- > 0)
	{
		sig = ((int)c >> i) & 1;
		ft_printf("sig %d\n", sig);
		if (sig == 1)
			is_success = kill(pid, SIGUSR1);
		else if (sig == 0)
			is_success = kill(pid, SIGUSR2);
		if (is_success == -1)
			exit(EXIT_FAILURE);
		usleep(50);
	}
}

int	catch_client_response(char **argv)
{
	int		server_pid;
	char	*server_msg;
	int		msg_len;
	int		i;

	i = 0;
	server_pid = ft_atoi(argv[1]);
	ft_printf("PID %d\n", server_pid);
	server_msg = argv[2];
	msg_len = ft_strlen(server_msg);
	ft_printf("LEN %d\n", msg_len);
	while (i < msg_len)
	{
		send_signal(server_pid, argv[2][i]);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_printf("OK \n");
		catch_client_response(argv);
		exit(EXIT_SUCCESS);
	}
	ft_printf("Args error\n");
	return (1);
}
