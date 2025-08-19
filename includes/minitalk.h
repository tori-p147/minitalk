/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 18:49:59 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/19 17:56:06 by vmatsuda         ###   ########.fr       */
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

int			start_server(void);
int			catch_client_response(char **argv);
void		send_signal(int pid, unsigned char c);

#endif