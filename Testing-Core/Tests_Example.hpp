// It's best to split out tests into different headers based on the thing being tested.

#pragma once
#include "Test.hpp"

// Each test file needs to be forward declared to be picked up by the testing framework.
DECLARE_TEST_FILE( example_tests );

// Include any fixture files you need.
#include "Fixtures_Example.hpp"

// Declaring simple tests can be done this way:
// DEFINE_TEST( [name], [fixtures]... ) 
// { TEST_ASSERT( [Actual], [Expected], [Message], [print args]... ); }

// Here is an example test:
DEFINE_TEST( example_test0 )
{
	int Value = 1;
	constexpr int Expected = 1;
	TEST_ASSERT( Value, Expected, "Value should be %i.", Expected );
}

// Here is a test relying on fixtures.
DEFINE_TEST( example_test1, example_simple_fixture1 )
{
	int Expected = 1;
	example_simple_fixture1->a = 1;
	int Value = example_simple_fixture1->a;
	TEST_ASSERT( Value, Expected, "Value should be %i. Was %i.", Value, Expected );
}

// We can also declare tests based on tables. This means we can run the same test for many entries in a table.
// Defining a test table with the same name as a test will enable an "Entry" input object that represents the table entry values.
DEFINE_TEST_TABLE(	example_test2,
	TABLE_HEADER(	Value,	Expected	),
	TABLE_ENTRY(	0,		0			),
	TABLE_ENTRY(	1,		2			));

DEFINE_TEST( example_test2 )
{
	int Value = Entry.Value;
	int Expected = Entry.Expected;
	TEST_ASSERT( Value, Expected, "" );
}