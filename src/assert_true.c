/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_true.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:20:37 by mgalliou          #+#    #+#             */
/*   Updated: 2020/02/12 19:00:01 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftest.h"
#include <stdio.h>

void	assert_true(int actually)
{
	if (!actually)
	{
		print_test_failed_in_suite();
		dprintf(2, "test: %s: failed\n", get_test_mng()->current_test);
		dprintf(2, "expected: \"%s\"\nactually: \"%s\".\n", "true", "false");
		set_cur_test_ret(EXIT_FAILURE);
	}
}
