/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:03:54 by jadyar            #+#    #+#             */
/*   Updated: 2024/03/05 11:04:46 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	sighandler(int signum)
{
	// Signal handler to handle signals sent by clients
	if (signum == SIGUSR1 || signum == SIGUSR2)
	{
		printf("Received signal from client\n");
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("Server PID: %d\n", pid);
	// Set signal handler
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	while (1)
	{
		pause(); // Wait for signals indefinitely
	}
	return (0);
}
