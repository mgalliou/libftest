/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_str_n_eq.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:19:16 by mgalliou          #+#    #+#             */
/*   Updated: 2020/02/12 18:58:41 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftest.h"
#include <string.h>
#include <stdio.h>

void 	assert_str_n_eq(char *expected, char *actually, size_t n)
{
	if (strncmp(actually, expected, n))
	{
		print_test_failed_in_suite();
		dprintf(2, "test: %s: failed\n", get_test_mng()->current_test);
		dprintf(2, "expected: \"%s\"\nactually: \"%s\".\n", expected, actually);
		set_cur_test_ret(EXIT_FAILURE);
	}
}
