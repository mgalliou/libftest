/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_str_equal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:27:31 by mgalliou          #+#    #+#             */
/*   Updated: 2019/05/09 21:56:01 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftest.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int 	assert_str_equal(char *expected, char *actually)
{
	if (!strcmp(actually, expected))
	{
		exit(EXIT_SUCCESS);
	}
	dprintf(2, "test: %s: failed\n", get_test_mng()->current_test);
	dprintf(2, "expected: \"%s\"\nactually: \"%s\".\n", expected, actually);
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

