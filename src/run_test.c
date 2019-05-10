/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:22:35 by mgalliou          #+#    #+#             */
/*   Updated: 2019/05/10 17:25:40 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftest.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void	record_ret(int status)
{
	t_test_mng *test_mng;
	
	test_mng = get_test_mng();
	if (WIFSIGNALED(status))
	{
		++test_mng->failed;
		printf("signal\n");
	}
	else if (WIFEXITED(status))
	{
		if (EXIT_FAILURE == status)
		{
			++test_mng->failed;
		}
		else
		{
			++test_mng->passed;
		}
	}
	++test_mng->asserted;
}


void    run_test(void test(), const char *test_name)
{
	t_test_mng *test_mng;
	int pid;
	int status;

	test_mng = get_test_mng();
	test_mng->current_test = test_name;
	pid = fork();
	status = -1;
	if (0 == pid)
	{
		dprintf(2, "running test: %s\n", test_name);
		test();
		exit(0);
	}
	else
	{
		wait(&status);
	}
	record_ret(WEXITSTATUS(status));
}

