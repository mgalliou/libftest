/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_test_suite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:40:52 by mgalliou          #+#    #+#             */
/*   Updated: 2019/05/11 11:50:58 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libftest.h"
#include "libft.h"

static void	log_running_suite(const char *suite_name)
{
	if (1)
	{
		ft_putendl("====================");
		ft_putstr("running test suite: ");
		ft_putendl(suite_name);
		ft_putendl("====================");
	}
}

void	run_test_suite(void	test_suite(), const char *suite_name)
{
	log_running_suite(suite_name);
	test_suite();
}
