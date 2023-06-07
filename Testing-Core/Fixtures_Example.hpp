// This file is an example of a fixtures header you may want to create to separate out each set of fixtures.
// Fixtures are objects that can be used in multiple tests. They may represent a scenario or state, or can be a mocked object.

#include "Test.hpp"

// The syntax for the fixture macro is as followed:
// DEFINE_FIXTURE( [type], [name], [dependant fixtures]... )

// Here is a fixture called "example_simple_fixture0". It's type is int.
DEFINE_FIXTURE( int, example_simple_fixture0 )
{
	return 1;
}

// Here is a slightly more complicated fixture that returns a special object.
struct ExampleFixtureType { int a = 2; };
DEFINE_FIXTURE( ExampleFixtureType, example_simple_fixture1 )
{
	ExampleFixtureType Result;
	Result.a = 100;
	return Result;
}

// Here is a complicated fixture that has two dependencies.
DEFINE_FIXTURE( int, example_complex_fixture0, 
	example_simple_fixture0, 
	example_simple_fixture1 )
{
	// To get the value out of the injected fixtures, use the deref operator.
	int Result = *example_simple_fixture0 + ( *example_simple_fixture1 ).a;
	return Result;
}