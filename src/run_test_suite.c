/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_test_suite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:40:52 by mgalliou          #+#    #+#             */
/*   Updated: 2019/05/09 20:22:00 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libftest.h"

void	run_test_suite(void	test_suite(), const char *suite_name)
{
	dprintf(1, "running test suite: %s\n", suite_name);
	test_suite();
}
