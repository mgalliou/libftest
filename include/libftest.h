/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:56:01 by mgalliou          #+#    #+#             */
/*   Updated: 2019/05/09 17:49:56 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

typedef struct	s_test_mng
{
	int			asserted;
	int			failed; 
	int			passed;
	const char 	*current_test;
}				t_test_mng;

# define TEST_SUITE(suite_name)          void suite_name(const char *suite_name)
# define RUN_TEST_SUITE(suite_name)      run_test_suite(suite_name, #suite_name)

# define TEST(test_name)                 void test_name()
# define RUN_TEST(test_name)             run_test(test_name, #test_name)

t_test_mng		*get_test_mng(void);
void            run_test_suite(void	test_suite(), const char *suite_name);
void			run_test(void test(const char *), const char *test_name);
int				assert_not_null(void *ptr);
int             assert_str_equal(char *expected, char *actually);
int				assert_int_equal(int expected, int actually);
void            print_test_results(void);

#endif
