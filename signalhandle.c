/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signalhandle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohtake <skohtake@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:49:20 by skohtake          #+#    #+#             */
/*   Updated: 2025/07/05 19:02:17 by skohtake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handle_signals(int signum)
{
	if (signum == SIGUSR1)
	{
		printf("receiving the signal of --- %d (SIGUSR1) ---\n",signum);
	}
	else if (signum == SIGUSR2)
	{
		printf("receiving the signal of --- %d (SIGUSR2) ---\n",signum);
	}
	else
	{
		printf("receiving an unknown signal, whose signum is --- %d ---\n",signum);
	}
}

int main(void)
{
	struct sigaction sa;
	sa.sa_handler = handle_signals;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if(sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		perror("SIGUSR1 failed\n");
		return(1);
	}
	if(sigaction(SIGUSR2, &sa,NULL)==-1)
	{
		perror("SIGUSR2 failed\n");
		return(1);
	}
	printf("PID of this process is --- %d ---.\n", getpid());
	printf("Send signal...\n");
	printf("Just waiting...\n");
	while (1)
		;
	return (0);
}
