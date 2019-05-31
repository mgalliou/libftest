/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_int_equal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:47:21 by mgalliou          #+#    #+#             */
/*   Updated: 2019/05/31 13:06:42 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libftest.h"

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
