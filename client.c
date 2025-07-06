/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohtake <skohtake@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:49:15 by skohtake          #+#    #+#             */
/*   Updated: 2025/07/06 15:36:28 by skohtake         ###   ########.fr       */
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
	while (c)
	{
		while (num_bit--)
		{
			if (c & (1 << num_bit))
			{
				kill(atoi(argv[1]), SIGUSR2);
			}
			else
			{
				kill(atoi(argv[1]), SIGUSR1);
			}
			usleep(1000);
		}
		num_bit = 8;
		c = (char)argv[2][i++];
	}
	return (0);
}
