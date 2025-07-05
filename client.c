/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohtake <skohtake@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:49:15 by skohtake          #+#    #+#             */
/*   Updated: 2025/07/05 14:48:34 by skohtake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	(void)argc;
	int i = 0;
	char c = (char)argv[2][i];
	// int byte =8;

	while(c)
	{
		if(c == '0')
		{
			kill(atoi(argv[1]), SIGUSR1);
		}
		else if(c == '1')
		{
			kill(atoi(argv[1]), SIGUSR2);
		}
		else
		{
			kill(atoi(argv[1]), SIGSEGV);
		}
		c = (char)argv[2][++i];
		usleep(1000);
	}
	return (0);
}
