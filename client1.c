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

int	main(int argc, char **argv)
{
	(void)argc;
	kill(atoi(argv[1]), SIGUSR1);
	return (0);
}
