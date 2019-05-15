/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_ptr_equal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:57:08 by mgalliou          #+#    #+#             */
/*   Updated: 2019/05/15 14:29:02 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftest.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void 	assert_ptr_equal(void *expected, void *actually)
{
	if (actually != expected)
	{
		dprintf(2, "test: %s: failed\n", get_test_mng()->current_test);
		dprintf(2, "expected: \"%p\"\nactually: \"%p\".\n", expected, actually);
		set_cur_test_ret(EXIT_FAILURE);
	}
}
