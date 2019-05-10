/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test_results.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:31:43 by mgalliou          #+#    #+#             */
/*   Updated: 2019/05/10 18:33:08 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftest.h"

void    print_test_results(void)
{
	t_test_mng *test_mng;

	test_mng = get_test_mng();
	printf("asserted: %d, passed: %d, failed: %d\n",
			test_mng->asserted,
			test_mng->passed,
			test_mng->failed);
}
