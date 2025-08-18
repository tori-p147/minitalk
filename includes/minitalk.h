/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 18:49:59 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/18 18:56:32 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define SIGUSR1 1
# define SIGUSR2 2

# include "ft_printf.h"
# include "libft.h"
# include <signal.h>
# include <unistd.h>


typedef struct s_client
{
	char	*server_pid;
	char	*msg;
}			t_client;

int			start_server(void);
int			catch_client_response(char **argv);
void		send_signal(int pid, unsigned char c);

#endif