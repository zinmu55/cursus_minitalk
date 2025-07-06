/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohtake <skohtake@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:49:15 by skohtake          #+#    #+#             */
/*   Updated: 2025/07/06 13:16:06 by skohtake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	char	c;
	int		num_bit;

	(void)argc;
	i = 0;
	c = (char)argv[2][i++];
	num_bit = 8;
	// '0' is 48 in digits, 00001100 in binary of char.
	// 'a' is 97 in digits, 01100001 in binary of char.
	while (c)
	{
		while (num_bit--)
		{
			if (c & (1 << num_bit)) //binary 1
			{
				kill(atoi(argv[1]), SIGUSR2);
			}
			else //binary 0
			{
				kill(atoi(argv[1]), SIGUSR1);
			}
			usleep(1000);
		}
		num_bit = 8;
		c = (char)argv[2][i++];
	}
	// while(c)
	// {
	// 	if(c == '0')
	// 	{
	// 		kill(atoi(argv[1]), SIGUSR1);
	// 	}
	// 	else if(c == '1')
	// 	{
	// 		kill(atoi(argv[1]), SIGUSR2);
	// 	}
	// 	else
	// 	{
	// 		kill(atoi(argv[1]), SIGSEGV);
	// 	}
	// 	c = (char)argv[2][++i];
	// 	usleep(1000);
	// }
	// return (0);
}
