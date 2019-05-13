/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:22:35 by mgalliou          #+#    #+#             */
/*   Updated: 2019/05/13 10:37:32 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftest.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void	record_ret(int status)
{
	t_test_mng *test_mng;
	
	test_mng = get_test_mng();
	if (WIFEXITED(status))
	{
		if (EXIT_FAILURE == WEXITSTATUS(status))
		{
			++test_mng->failed;
		}
		else
		{
			++test_mng->passed;
		}
	}
	else if (WIFSIGNALED(status))
	{
		++test_mng->failed;
		ft_putstr("signal ");
		ft_putnbr(WTERMSIG(status));
		ft_putchar('\n');
	}
	++test_mng->asserted;
}

static void	log_running_test(const char *test_name)
{
	if (1)
	{
		ft_putstr("running test: ");
		ft_putendl(test_name);
	}
}

void    run_test(void test(), const char *test_name)
{
	t_test_mng *test_mng;
	int pid;
	int status;

	test_mng = get_test_mng();
	test_mng->current_test = test_name;
	log_running_test(test_name);
	pid = fork();
	status = -1;
	if (0 == pid)
	{
		test();
		exit(0);
	}
	else
	{
		wait(&status);
	}
	record_ret(WEXITSTATUS(status));
}

