/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmatsuda <vmatsuda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 17:29:45 by vmatsuda          #+#    #+#             */
/*   Updated: 2025/08/17 22:07:45 by vmatsuda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	catch_client_response(char **argv)
{
	(void)argv;
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc == 2)
	{
		catch_client_response(argv);
		return (0);
	}
	return (1);
}
