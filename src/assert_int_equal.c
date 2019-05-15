/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_int_equal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:47:21 by mgalliou          #+#    #+#             */
/*   Updated: 2019/05/15 14:09:55 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libftest.h"

int    assert_int_equal(int expected, int actually)
{
	if (expected == actually)
	{
		exit(EXIT_SUCCESS);
	}
	printf("test: %s: failed\n", get_test_mng()->current_test);
	printf("expected: \"%d\"\nactually: \"%d\".\n", expected, actually);
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}
