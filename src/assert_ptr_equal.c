/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_ptr_equal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:57:08 by mgalliou          #+#    #+#             */
/*   Updated: 2020/02/12 18:57:57 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftest.h"
#include <stdio.h>

void 	assert_ptr_equal(void *expected, void *actually)
{
	if (actually != expected)
	{
		print_test_failed_in_suite();
		dprintf(2, "test: %s: failed\n", get_test_mng()->current_test);
		dprintf(2, "expected: \"%p\"\nactually: \"%p\".\n", expected, actually);
		set_cur_test_ret(EXIT_FAILURE);
	}
}
