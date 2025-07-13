/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohtake <skohtake@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:49:15 by skohtake          #+#    #+#             */
/*   Updated: 2025/07/13 16:31:00 by skohtake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	client_error_msg(void)
{
	ft_putendl_fd(" Error : Check how to use \"client\" program ", 1);
}

void	kill_error_msg(void)
{
	ft_putendl_fd(" Error : kill failed (Please check PID) ", 1);
}

int	send_char(pid_t pid, char c)
{
	int	num_bit;
	int	kill_res;

	num_bit = 8;
	while (num_bit--)
	{
		if (c & (1 << num_bit))
			kill_res = kill(pid, SIGUSR2);
		else
			kill_res = kill(pid, SIGUSR1);
		if (kill_res != 0)
		{
			kill_error_msg();
			exit(EXIT_FAILURE);
		}
		usleep(100);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	int		i;
	char	c;

	if (argc != 3)
		return (client_error_msg(), EXIT_FAILURE);
	i = 0;
	c = (char)argv[2][i++];
	while (c)
	{
		send_char(ft_atoi(argv[1]), c);
		c = (char)argv[2][i++];
	}
	return (EXIT_SUCCESS);
}
