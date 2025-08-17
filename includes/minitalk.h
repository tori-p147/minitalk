/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 18:49:59 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/17 22:09:02 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define SIGUSR1 1
# define SIGUSR2 2

# include "libft.h"
# include "printf.h"
# include <signal.h>

typedef struct s_server
{
	char	*pid;
}			t_server;

typedef struct s_client
{
	char	*server_pid;
	char	*msg;
}			t_client;

int			start_server(void);
void		init_server(t_server *server);
void		server_handler(int sig_num);
int			catch_client_response(char **argv);

#endif