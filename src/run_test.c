/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:22:35 by mgalliou          #+#    #+#             */
/*   Updated: 2019/08/16 18:23:34 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include "libftest.h"

void	record_ret(int status)
{
	t_test_mng *test_mng;
	
	test_mng = get_test_mng();
	if (WIFEXITED(status))
	{
		if (status)
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
		printf("%s:\n failed with signal %d\n",
				get_test_mng()->current_test,
				WTERMSIG(status));
	}
	++test_mng->asserted;
}

static void	log_running_test(const char *test_name)
{
	if (get_test_mng()->log)
	{
		printf("running test: %s\n", test_name);
	}
}

void    run_test(void (test)(void), const char *test_name)
{
	int pid;
	int status;

	get_test_mng()->current_test = test_name;
	log_running_test(test_name);
	pid = fork();
	status = -1;
	if (0 == pid)
	{
		set_cur_test_ret(EXIT_SUCCESS);
		get_test_mng()->before_test();
		test();
		get_test_mng()->after_test();
		exit(get_test_mng()->current_test_ret);
	}
	else
	{
		wait(&status);
	}
	record_ret(status);
}

