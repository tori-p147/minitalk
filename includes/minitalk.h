/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 18:49:59 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/26 15:06:10 by vmatsuda         ###   ########.fr       */
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

volatile sig_atomic_t	g_is_signal_received = 0;

void					set_sig_handler_with_client_info(void);
void					handler(int signo);
void					handler_with_info(int signo, siginfo_t *info,
							void *context);
int						start_server(void);
void					set_sig_handler(void);
void					catch_client_response(char **argv);
void					send_signal(int pid, unsigned char c);

#endif