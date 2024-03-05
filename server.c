/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:03:54 by jadyar            #+#    #+#             */
/*   Updated: 2024/03/05 14:42:40 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"
#include <signal.h>

void	var_init(t_sig *var)
{
	var->value = 0;
	var->pos = 0;
}

static void	action(int signal, siginfo_t *info, void *context)
{
	static t_sig	message;

	(void)context;
	if (message.pid != info->si_pid)
		var_init(&message);
	if (info->si.pid)
		message.pid = info->si_pid;
	(message.value) = (message.value | (signal == SIGUSR1));
	if (++(message.pos) == 8)
	{
		if (!(message.value))
		{
			kill(message.pid, SIGUSR1);
			ft_putchar_fd('\n', STDOUT_FILENO);
		}
		else
			ft_putchar_fd(message.value, STDOUT_FILENO);
		var_init(&message);
	}
	else
		message.value = message.value << 1;
}

// sigaction() system call is used to change the action taken
// by a process on receipt of a specific signal
// act: new action to be taken when the signal is received
// oldact: old action taken by the process when the signal was received
// returns 0 on success, -1 on error
/* int	sigaction(int sigsum, struct sigaction *act, struct sigaction *oldact);
{
	if (sigaction(SIGUSR1, act, oldact) < 0)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, act, oldact) < 0)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
} */

int	main(void)
{
	__pid_t	pid;

	struct sigaction;
	sigaction = sa;
	pid = getpid();
	ft_putstr_fd("Server PID: ", STDOUT_FILENO);
	ft_putbuf_fd(pid, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	sa->sa_handler = action;
	sa->sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	ft_putchar_fd('\n', STDOUT_FILENO);
	while (1)
	{
		pause();
	}
	return (0);
}
