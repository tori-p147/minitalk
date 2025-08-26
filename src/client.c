/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 17:29:45 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/26 14:25:20 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, unsigned char c)
{
	int	i;
	int	sig;
	int	ascii_code;

	i = 8;
	ascii_code = c;
	while (i--)
	{
		sig = ascii_code >> i & 1;
		if (sig == 1)
			kill(pid, SIGUSR1);
		else if (sig == 0)
			kill(pid, SIGUSR2);
		usleep(500);
	}
}

void	catch_client_response(char **argv)
{
	int		server_pid;
	char	*server_msg;
	int		msg_len;
	int		i;

	i = 0;
	server_pid = ft_atoi(argv[1]);
	server_msg = argv[2];
	msg_len = ft_strlen(server_msg);
	while (i < msg_len)
	{
		send_signal(server_pid, argv[2][i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		catch_client_response(argv);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}
