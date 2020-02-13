/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_not_null.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:29:27 by mgalliou          #+#    #+#             */
/*   Updated: 2020/02/12 18:58:12 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/libftest.h"

void	assert_not_null(void *ptr)
{
	if (!ptr)
	{
		print_test_failed_in_suite();
		dprintf(2, "test: %s: failed\n", get_test_mng()->current_test);
		dprintf(2, "expected: %s\nactually: %s\n", "not null", "null");
		set_cur_test_ret(EXIT_FAILURE);
	}
}

