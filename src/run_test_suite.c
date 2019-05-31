/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_test_suite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:40:52 by mgalliou          #+#    #+#             */
/*   Updated: 2019/05/31 13:08:57 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libftest.h"
#include "libft.h"

static void	log_running_suite(void)
{
	if (0)
	{
		ft_putendl("====================");
		ft_putstr("running test suite: ");
		ft_putendl(get_test_mng()->current_suite);
		ft_putendl("====================");
	}
}

void	run_test_suite(void	test_suite(), const char *suite_name)
{
	get_test_mng()->current_suite = suite_name;
	log_running_suite();
	test_suite();
}
