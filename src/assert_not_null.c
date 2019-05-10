/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_not_null.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:29:27 by mgalliou          #+#    #+#             */
/*   Updated: 2019/05/10 15:36:43 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libftest.h"

int		assert_not_null(void *ptr)
{
	if (ptr)
	{
		exit(EXIT_SUCCESS);
	}
	dprintf(2, "test: %s: failed\n", get_test_mng()->current_test);
	dprintf(2, "expected: %s\nactually: %s\n", "not null", "null");
	exit(EXIT_FAILURE);
}

