/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_test_suite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:40:52 by mgalliou          #+#    #+#             */
/*   Updated: 2019/10/25 13:34:28 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftest.h"
#include "libft.h"
#include <string.h>
#include <stdio.h>

static void	log_running_suite(void)
{
	if (get_test_mng()->log)
	{
		puts("====================\n");
		puts("running test suite:\n");
		printf("%s", get_test_mng()->current_suite);
		puts("====================\n");
	}
}

void	run_test_suite(void	test_suite(), const char *suite_name)
{
	get_test_mng()->current_suite = suite_name;
	log_running_suite();
	test_suite();
}
