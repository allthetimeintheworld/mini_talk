/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:03:46 by jadyar            #+#    #+#             */
/*   Updated: 2024/03/07 12:07:18 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_exit_failure(void)
{
	ft_putstr_fd("Use case: \"./client SERVER_PID MESSAGE\" \n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	action(int signal)
{
	static int	bytes_got;

	bytes_got = 0;
	if (signal == SIGUSR1)
		bytes_got++;
	else
	{
		ft_putnbr_fd(bytes_got, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
}

void	send_signal(pid_t pid, char *message)
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
	int		message;

	if (argc != 3)
		ft_exit_failure();
	message = ft_strlen(argv[2]);
	if (!message || !ft_atoi(argv[1]))
		ft_exit_failure();
	ft_putstr_fd("Server PID: ", STDOUT_FILENO);
	ft_putnbr_fd(message, STDOUT_FILENO);
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
