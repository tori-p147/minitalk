/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 17:29:45 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/19 19:01:48 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, unsigned char c)
{
	int	i;
	int bit;
	int sig;
	int is_success;

	i = 0;
	while (i-- > 0)
	{
		sig = (c >> i) & 1;
		if (sig == 1)
			is_success = kill(pid, SIGUSR1);
		else if (sig == 0)
			is_success = kill(pid, SIGUSR2);
		if (is_success == -1)
			exit(EXIT_FAILURE);
		usleep(50);
		i++;
	}
}

int	catch_client_response(char **argv)
{
	int		server_pid;
	char	*server_msg;
	int		msg_len;
	int		i;

	i = 0;
	server_pid = argv[0];
	server_msg = argv[1];
	msg_len = ft_strlen(server_msg);
	while (i < msg_len)
	{
		send_signal(server_pid, argv[1][i]);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		catch_client_response(argv);
		return (0);
	}
	return (1);
}
