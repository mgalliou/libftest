/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_not_null.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:29:27 by mgalliou          #+#    #+#             */
/*   Updated: 2019/05/15 14:25:59 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libftest.h"

void	assert_not_null(void *ptr)
{
	if (!ptr)
	{
		printf("test: %s: failed\n", get_test_mng()->current_test);
		printf("expected: %s\nactually: %s\n", "not null", "null");
		set_cur_test_ret(EXIT_FAILURE);
	}
}

