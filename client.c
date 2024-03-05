/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:03:46 by jadyar            #+#    #+#             */
/*   Updated: 2024/03/05 13:49:33 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "mini_talk.h"


static	void	ft_exit_failure(void)
{
	ft_putstr_fd("%s\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static void	action(int signal)
{
	static int	bytes_got;

	bytes_got = 0;
	if (signal == SIGUSR1)
	{
		bytes_got++;
	}
	else if (signal == SIGUSR2)
	{
		bytes_got++;
		bytes_got = bytes_got << 1;
	}


}

static void	send_signal(__pid_t pid, char *message)
{
	int	i;
	int	j;

	i = 0;
	while (message[i] != '\0')
	{
		j = 0;
		while (j < 8)
		{
			if ((message[i] >> j) & 1)
			{
				kill(pid, SIGUSR1);
			}
			else
			{
				kill(pid, SIGUSR2);
			}
			usleep(100);
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		server_pid;
	char	*message;

	if (argc != 3)
		ft_exit_failure();
	server_pid = atoi(argv[1]);
	message = argv[2];
	if (!server_pid || !message)
		ft_exit_failure();
	ft_putstr_fd("Server PID: ", STDOUT_FILENO);
	ft_putnbr_fd(server_pid, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	ft_putstr_fd("Message recieved: ", STDOUT_FILENO);
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	send_signal(ft_atoi(argv[1]), argv[2]);
	while (1)
	{
		pause();
	}
	return (0);
}
