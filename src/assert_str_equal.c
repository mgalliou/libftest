/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_str_equal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:27:31 by mgalliou          #+#    #+#             */
/*   Updated: 2020/02/12 18:58:30 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftest.h"
#include <string.h>
#include <stdio.h>

void 	assert_str_equal(char *expected, char *actually)
{
	char *null = "(null)";

	if ((!expected && actually) ||
			(expected && !actually) ||
			(expected && actually && strcmp(expected, actually)))
	{
		if (!expected)
		{
			expected = null;
		}
		if (!actually)
		{
			actually = null;
		}
		print_test_failed_in_suite();
		dprintf(2, "test: %s: failed\n", get_test_mng()->current_test);
		dprintf(2, "expected: \"%s\"\nactually: \"%s\".\n", expected, actually);
		set_cur_test_ret(EXIT_FAILURE);
	}
}

