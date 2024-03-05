/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:03:46 by jadyar            #+#    #+#             */
/*   Updated: 2024/03/05 11:04:19 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	char	*message;

	if (argc != 3)
	{
		printf("Usage: %s <server_pid> <string>\n", argv[0]);
		return (1);
	}
	server_pid = atoi(argv[1]);
	message = argv[2];
	// Send each character of the message to the server using SIGUSR1 and SIGUSR2 signals
	for (int i = 0; message[i] != '\0'; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((message[i] >> j) & 1)
			{
				kill(server_pid, SIGUSR1); // Send SIGUSR1 for 1
			}
			else
			{
				kill(server_pid, SIGUSR2); // Send SIGUSR2 for 0
			}
			usleep(100); // Adjust this delay as needed
		}
	}
	printf("Message sent to server\n");
	return (0);
}
