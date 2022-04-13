/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:08:07 by romannbroque      #+#    #+#             */
/*   Updated: 2022/04/13 17:04:24 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <check.h> 

START_TEST(test_simple1)
{
	ck_assert_int_eq(add(1, 4), 5);
}
END_TEST

START_TEST(test_simple2)
{
	ck_assert_int_eq(add(1, -2), -1);
}
END_TEST

Suite	*add_suite(void)
{
	Suite	*s;
	TCase	*tc_core;

	s = suite_create("Add");
	tc_core = tcase_create("Result");

	tcase_add_test(tc_core, test_simple1);
	tcase_add_test(tc_core, test_simple2);
	suite_add_tcase(s, tc_core);

	return (s);
}

int	main(void)
{
	int		not_failed;
	Suite	*s;
	SRunner	*runner;

	not_failed = 0;
	s = add_suite();
	runner = srunner_create(s);
	
	srunner_run_all(runner, CK_NORMAL);
	not_failed = srunner_ntests_failed(runner);
	srunner_free(runner);
	return (not_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
