/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shintarokohtake <shintarokohtake@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:49:15 by skohtake          #+#    #+#             */
/*   Updated: 2025/07/11 08:14:47 by shintarokoh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void client_error_msg(void)
{
	ft_putstr_fd(" Error : Check how to use \"client\" program. ", 1);
	ft_putchar_fd('\n', 1);
}

int	main(int argc, char **argv)
{
	int		i;
	int 	kill_res;
	char	c;
	int		num_bit;

	if(argc != 3)
		return (client_error_msg(),EXIT_FAILURE);
	i = 0;
	c = (char)argv[2][i++];
	num_bit = 8;
	while (c)
	{
		while (num_bit--)
		{
			if (c & (1 << num_bit))
				kill_res = kill(ft_atoi(argv[1]), SIGUSR2);
			else
				kill_res = kill(ft_atoi(argv[1]), SIGUSR1);
			if(kill_res != 0)
				return(client_error_msg(),EXIT_FAILURE);
			usleep(100);
		}
		num_bit = 8;
		c = (char)argv[2][i++];
	}
	return (EXIT_SUCCESS);
}
