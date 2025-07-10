/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohtake <skohtake@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:49:18 by skohtake          #+#    #+#             */
/*   Updated: 2025/07/10 10:10:52 by skohtake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	handle_signals(int signum)
{
	static int	num_bit;
	static char	c;

	if (num_bit == 0)
	{
		num_bit = 8;
		c = 0;
	}
	if (signum == SIGUSR1)
	{
		--num_bit;
	}
	else if (signum == SIGUSR2)
	{
		c = c | (1 << --num_bit);
	}
	if (num_bit == 0)
	{
		write(1, &c, 1);
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = handle_signals;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr_fd("=== libft test ===", 1);
	printf("PID of this process is --- %d ---.\n", getpid());
	printf("Send signal...\n");
	printf("Just waiting...\n");
	while (1)
		;
	return (0);
}
