/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_not_null.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:29:27 by mgalliou          #+#    #+#             */
/*   Updated: 2019/05/13 12:41:29 by mgalliou         ###   ########.fr       */
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
	printf("test: %s: failed\n", get_test_mng()->current_test);
	printf("expected: %s\nactually: %s\n", "not null", "null");
	exit(EXIT_FAILURE);
}

