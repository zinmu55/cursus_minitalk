/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohtake <skohtake@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:49:18 by skohtake          #+#    #+#             */
/*   Updated: 2025/07/06 14:53:58 by skohtake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (signum == SIGUSR1) //num_bit binary is 0.
	{
		// printf("receiving the signal of --- %d (SIGUSR1) ---\n", signum);
		--num_bit;
	}
	else if (signum == SIGUSR2) //num_bit binary is 1.
	{
		// printf("receiving the signal of --- %d (SIGUSR2) ---\n", signum);
		c = c | (1 << --num_bit);
	}
	// else
	// {
	// 	printf("receiving an unknown signal, whose signum is --- %d ---\n",
	// 			signum);
	// }
	if (num_bit == 0)
	{
		write(1, &c, 1);
		// printf("---just received char of '%c'---\n", c);
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
	// if (sigaction(SIGUSR1, &sa, NULL) == -1)
	// {
	// 	perror("SIGUSR1 failed\n");
	// 	return (1);
	// }
	// if (sigaction(SIGUSR2, &sa, NULL) == -1)
	// {
	// 	perror("SIGUSR2 failed\n");
	// 	return (1);
	// }
	printf("PID of this process is --- %d ---.\n", getpid());
	printf("Send signal...\n");
	printf("Just waiting...\n");
	while (1)
		;
	return (0);
}
