/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_str_equal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:27:31 by mgalliou          #+#    #+#             */
/*   Updated: 2019/05/15 14:32:19 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftest.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void 	assert_str_equal(char *expected, char *actually)
{
	if (strcmp(actually, expected))
	{
		dprintf(2, "test: %s: failed\n", get_test_mng()->current_test);
		dprintf(2, "expected: \"%s\"\nactually: \"%s\".\n", expected, actually);
		set_cur_test_ret(EXIT_FAILURE);
	}
}

