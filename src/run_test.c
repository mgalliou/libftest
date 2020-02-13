/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:22:35 by mgalliou          #+#    #+#             */
/*   Updated: 2020/02/13 06:23:35 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftest.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

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


static void run_suite_after_test()
{
	if (get_test_mng()->current_suite.after_test)
	{
		get_test_mng()->current_suite.after_test();
	}
}

static void run_suite_before_test()
{
	if (get_test_mng()->current_suite.before_test)
	{
		get_test_mng()->current_suite.before_test();
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
		run_suite_before_test();
		test();
		run_suite_after_test();
		exit(get_test_mng()->current_test_ret);
	}
	else
	{
		wait(&status);
	}
	record_ret(status);
}

