/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_true.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:20:37 by mgalliou          #+#    #+#             */
/*   Updated: 2019/05/10 17:22:46 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libftest.h"

int	assert_true(int actually)
{
	if (actually)
	{
		exit(EXIT_SUCCESS);
	}
	printf("test: %s: failed\n", get_test_mng()->current_test);
	printf("expected: \"%s\"\nactually: \"%s\".\n", "true", "false");
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}
