/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_ptr_equal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:57:08 by mgalliou          #+#    #+#             */
/*   Updated: 2019/05/10 17:58:14 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftest.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int 	assert_ptr_equal(void *expected, void *actually)
{
	if (!strcmp(actually, expected))
	{
		exit(EXIT_SUCCESS);
	}
	dprintf(2, "test: %s: failed\n", get_test_mng()->current_test);
	dprintf(2, "expected: \"%p\"\nactually: \"%p\".\n", expected, actually);
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}
