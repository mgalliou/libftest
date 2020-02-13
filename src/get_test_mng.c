/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_test_mng.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:45:29 by mgalliou          #+#    #+#             */
/*   Updated: 2020/02/13 10:34:09 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftest.h"
#include "unistd.h"

t_test_mng *get_test_mng(void)
{
	static t_test_mng test_mng;
	static int        init = 0;

	if (0 == init)
	{
		test_mng.asserted = 0;
		test_mng.failed = 0;
		test_mng.passed = 0;
		test_mng.log = 0;
		init = 1;
	}
	return (&test_mng);
}
