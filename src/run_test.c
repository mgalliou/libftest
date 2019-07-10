/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:22:35 by mgalliou          #+#    #+#             */
/*   Updated: 2019/07/10 11:15:25 by mgalliou         ###   ########.fr       */
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
		ft_putstr(get_test_mng()->current_test);
		ft_putstr(" failed with signal ");
		ft_putnbr(WTERMSIG(status));
		ft_putchar('\n');
	}
	++test_mng->asserted;
}

static void	log_running_test(const char *test_name)
{
	if (get_test_mng()->log)
	{
		ft_putstr("running test: ");
		ft_putendl(test_name);
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

