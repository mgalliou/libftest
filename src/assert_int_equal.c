/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_int_equal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:47:21 by mgalliou          #+#    #+#             */
/*   Updated: 2020/02/12 18:58:09 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftest.h"
#include <stdio.h>

void    assert_int_equal(int expected, int actually)
{
	if (expected != actually)
	{
		print_test_failed_in_suite();
		dprintf(2, "test: %s: failed\n", get_test_mng()->current_test);
		dprintf(2, "expected: \"%d\"\nactually: \"%d\".\n", expected, actually);
		set_cur_test_ret(EXIT_FAILURE);
	}
}
