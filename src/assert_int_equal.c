/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_int_equal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:47:21 by mgalliou          #+#    #+#             */
/*   Updated: 2019/10/25 13:23:33 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/libftest.h"

void    assert_int_equal(int expected, int actually)
{
	if (expected != actually)
	{
		printf("teste suite : %s\n", get_test_mng()->current_suite);
		printf("test: %s: failed\n", get_test_mng()->current_test);
		printf("expected: \"%d\"\nactually: \"%d\".\n", expected, actually);
		set_cur_test_ret(EXIT_FAILURE);
	}
}
