#pragma once
#include <iostream>
#include <list>
#include <string>
#include <map>
#include <array>

#include "Hash.hpp"
#include "FunctionTraits.hpp"
#include "OnStart.hpp"
#include "MacroHelpers.hpp"
#include "Invoker.hpp"
#include "Delegate.hpp"

#define EXPAND_FIXTURE_BY_SEMICOLON_1(x) Fixture<#x##_H> x;
#define EXPAND_FIXTURE_BY_SEMICOLON_2(x, ...) EXPAND(EXPAND_FIXTURE_BY_SEMICOLON_1(__VA_ARGS__)) Fixture<#x##_H> x;
#define EXPAND_FIXTURE_BY_SEMICOLON_3(x, ...) EXPAND(EXPAND_FIXTURE_BY_SEMICOLON_2(__VA_ARGS__)) Fixture<#x##_H> x;
#define EXPAND_FIXTURE_BY_SEMICOLON_4(x, ...) EXPAND(EXPAND_FIXTURE_BY_SEMICOLON_3(__VA_ARGS__)) Fixture<#x##_H> x;
#define EXPAND_FIXTURE_BY_SEMICOLON_5(x, ...) EXPAND(EXPAND_FIXTURE_BY_SEMICOLON_4(__VA_ARGS__)) Fixture<#x##_H> x;
#define EXPAND_FIXTURE_BY_SEMICOLON_6(x, ...) EXPAND(EXPAND_FIXTURE_BY_SEMICOLON_5(__VA_ARGS__)) Fixture<#x##_H> x;
#define EXPAND_FIXTURE_BY_SEMICOLON_7(x, ...) EXPAND(EXPAND_FIXTURE_BY_SEMICOLON_6(__VA_ARGS__)) Fixture<#x##_H> x;
#define EXPAND_FIXTURE_BY_SEMICOLON_8(x, ...) EXPAND(EXPAND_FIXTURE_BY_SEMICOLON_7(__VA_ARGS__)) Fixture<#x##_H> x;
#define EXPAND_FIXTURE_BY_SEMICOLON_9(x, ...) EXPAND(EXPAND_FIXTURE_BY_SEMICOLON_8(__VA_ARGS__)) Fixture<#x##_H> x;
#define EXPAND_FIXTURE_BY_SEMICOLON(...) EXPAND(GET_MACRO_9(__VA_ARGS__, \
EXPAND_FIXTURE_BY_SEMICOLON_9, \
EXPAND_FIXTURE_BY_SEMICOLON_8, \
EXPAND_FIXTURE_BY_SEMICOLON_7, \
EXPAND_FIXTURE_BY_SEMICOLON_6, \
EXPAND_FIXTURE_BY_SEMICOLON_5, \
EXPAND_FIXTURE_BY_SEMICOLON_4, \
EXPAND_FIXTURE_BY_SEMICOLON_3, \
EXPAND_FIXTURE_BY_SEMICOLON_2, \
EXPAND_FIXTURE_BY_SEMICOLON_1  )(__VA_ARGS__))

#define DEFINE_FIXTURE_0(Type, Name)\
template <> struct Fixture<#Name##_H > {\
	Type Instance; \
	Fixture() : Instance(fixture_##Name()) {}\
	Type fixture_##Name(); \
	inline Type* operator->() { return &Instance; }\
	inline Type& operator* () { return Instance; } };\
Type Fixture<#Name##_H>::fixture_##Name()

#define DEFINE_FIXTURE_N(Type, Name, ...)\
template <> struct Fixture<#Name##_H > {\
	EXPAND_FIXTURE_BY_SEMICOLON(__VA_ARGS__)\
	Type Instance; \
	Fixture() : Instance(fixture_##Name()) {}\
	Type fixture_##Name(); \
	inline Type* operator->() { return &Instance; }\
	inline Type& operator* () { return Instance; } };\
Type Fixture<#Name##_H>::fixture_##Name()

#define DEFINE_FIXTURE(...) EXPAND(GET_MACRO_20(__VA_ARGS__, \
DEFINE_FIXTURE_N, \
DEFINE_FIXTURE_N, \
DEFINE_FIXTURE_N, \
DEFINE_FIXTURE_N, \
DEFINE_FIXTURE_N, \
DEFINE_FIXTURE_N, \
DEFINE_FIXTURE_N, \
DEFINE_FIXTURE_N, \
DEFINE_FIXTURE_N, \
DEFINE_FIXTURE_N, \
DEFINE_FIXTURE_N, \
DEFINE_FIXTURE_N, \
DEFINE_FIXTURE_N, \
DEFINE_FIXTURE_N, \
DEFINE_FIXTURE_N, \
DEFINE_FIXTURE_N, \
DEFINE_FIXTURE_N, \
DEFINE_FIXTURE_N, \
DEFINE_FIXTURE_0  )(__VA_ARGS__))

#define DEFINE_TEST_0(Name)\
template <> struct Test<#Name##_H> : public std::conditional_t< Testing::does_table_exist_v<#Name##_H>, Testing::ITest0<#Name##_H>, Testing::ITest1<#Name##_H> >{\
	inline static const char* GetName() { return #Name; }\
	inline static const char* GetFileName() { return __FILE__; }\
	static void Setup() { Testing::FileToTestsTable[ __FILE__ ].Tests[ #Name ] = RunTest<Test<#Name##_H>>; }\
	inline static OnStart s_Setup = OnStart( Setup );\
	void Impl();\
	void operator()() { if constexpr ( HasTable ) { Testing::RunTable<#Name##_H>( *this ); return; } Impl(); } };\
void Test<#Name##_H>::Impl()

#define DEFINE_TEST_N(Name, ...)\
template <> struct Test<#Name##_H> : public std::conditional_t< Testing::does_table_exist_v<#Name##_H>, Testing::ITest0<#Name##_H>, Testing::ITest1<#Name##_H> >{\
	EXPAND_FIXTURE_BY_SEMICOLON(__VA_ARGS__)\
	inline static const char* GetName() { return #Name; }\
	inline static const char* GetFileName() { return __FILE__; }\
	static void Setup() { Testing::FileToTestsTable[ __FILE__ ].Tests[ #Name ] = RunTest<Test<#Name##_H>>; }\
	inline static OnStart s_Setup = OnStart( Setup );\
	void Impl();\
	void operator()() { if constexpr ( HasTable ) { Testing::RunTable<#Name##_H>( *this ); return; } Impl(); } };\
void Test<#Name##_H>::Impl()

#define DEFINE_TEST(...) EXPAND(GET_MACRO_9(__VA_ARGS__, \
DEFINE_TEST_N, \
DEFINE_TEST_N, \
DEFINE_TEST_N, \
DEFINE_TEST_N, \
DEFINE_TEST_N, \
DEFINE_TEST_N, \
DEFINE_TEST_N, \
DEFINE_TEST_N, \
DEFINE_TEST_0  )(__VA_ARGS__))

#define EXPAND_ENTRY_FIELD_1(Table, x) decltype( std::get< 0 >( TestTable< #Table##_H >::Value[ 0 ] ) )& x;
#define EXPAND_ENTRY_FIELD_2(Table, x, ...) EXPAND(EXPAND_ENTRY_FIELD_1(Table, __VA_ARGS__)) decltype( std::get< 1 >( TestTable< #Table##_H >::Value[ 0 ] ) )& x; 
#define EXPAND_ENTRY_FIELD_3(Table, x, ...) EXPAND(EXPAND_ENTRY_FIELD_2(Table, __VA_ARGS__)) decltype( std::get< 2 >( TestTable< #Table##_H >::Value[ 0 ] ) )& x; 
#define EXPAND_ENTRY_FIELD_4(Table, x, ...) EXPAND(EXPAND_ENTRY_FIELD_3(Table, __VA_ARGS__)) decltype( std::get< 3 >( TestTable< #Table##_H >::Value[ 0 ] ) )& x; 
#define EXPAND_ENTRY_FIELD_5(Table, x, ...) EXPAND(EXPAND_ENTRY_FIELD_4(Table, __VA_ARGS__)) decltype( std::get< 4 >( TestTable< #Table##_H >::Value[ 0 ] ) )& x; 
#define EXPAND_ENTRY_FIELD_6(Table, x, ...) EXPAND(EXPAND_ENTRY_FIELD_5(Table, __VA_ARGS__)) decltype( std::get< 5 >( TestTable< #Table##_H >::Value[ 0 ] ) )& x; 
#define EXPAND_ENTRY_FIELD_7(Table, x, ...) EXPAND(EXPAND_ENTRY_FIELD_6(Table, __VA_ARGS__)) decltype( std::get< 6 >( TestTable< #Table##_H >::Value[ 0 ] ) )& x; 
#define EXPAND_ENTRY_FIELD_8(Table, x, ...) EXPAND(EXPAND_ENTRY_FIELD_7(Table, __VA_ARGS__)) decltype( std::get< 7 >( TestTable< #Table##_H >::Value[ 0 ] ) )& x; 
#define EXPAND_ENTRY_FIELD_9(Table, x, ...) EXPAND(EXPAND_ENTRY_FIELD_8(Table, __VA_ARGS__)) decltype( std::get< 8 >( TestTable< #Table##_H >::Value[ 0 ] ) )& x; 
#define EXPAND_ENTRY_FIELD(Table, ...) EXPAND(GET_MACRO_9(__VA_ARGS__, \
EXPAND_ENTRY_FIELD_9, \
EXPAND_ENTRY_FIELD_8, \
EXPAND_ENTRY_FIELD_7, \
EXPAND_ENTRY_FIELD_6, \
EXPAND_ENTRY_FIELD_5, \
EXPAND_ENTRY_FIELD_4, \
EXPAND_ENTRY_FIELD_3, \
EXPAND_ENTRY_FIELD_2, \
EXPAND_ENTRY_FIELD_1  )(Table, __VA_ARGS__))

#define EXPAND_ENTRY_INITIALIZER_1(x)      x(std::get<0>(a_Entry)) 
#define EXPAND_ENTRY_INITIALIZER_2(x, ...) EXPAND(EXPAND_ENTRY_INITIALIZER_1(__VA_ARGS__)), x(std::get<1>(a_Entry))
#define EXPAND_ENTRY_INITIALIZER_3(x, ...) EXPAND(EXPAND_ENTRY_INITIALIZER_2(__VA_ARGS__)), x(std::get<2>(a_Entry)) 
#define EXPAND_ENTRY_INITIALIZER_4(x, ...) EXPAND(EXPAND_ENTRY_INITIALIZER_3(__VA_ARGS__)), x(std::get<3>(a_Entry)) 
#define EXPAND_ENTRY_INITIALIZER_5(x, ...) EXPAND(EXPAND_ENTRY_INITIALIZER_4(__VA_ARGS__)), x(std::get<4>(a_Entry))
#define EXPAND_ENTRY_INITIALIZER_6(x, ...) EXPAND(EXPAND_ENTRY_INITIALIZER_5(__VA_ARGS__)), x(std::get<5>(a_Entry)) 
#define EXPAND_ENTRY_INITIALIZER_7(x, ...) EXPAND(EXPAND_ENTRY_INITIALIZER_6(__VA_ARGS__)), x(std::get<6>(a_Entry)) 
#define EXPAND_ENTRY_INITIALIZER_8(x, ...) EXPAND(EXPAND_ENTRY_INITIALIZER_7(__VA_ARGS__)), x(std::get<7>(a_Entry))
#define EXPAND_ENTRY_INITIALIZER_9(x, ...) EXPAND(EXPAND_ENTRY_INITIALIZER_8(__VA_ARGS__)), x(std::get<8>(a_Entry)) 
#define EXPAND_ENTRY_INITIALIZER(...) EXPAND(GET_MACRO_9(__VA_ARGS__, \
EXPAND_ENTRY_INITIALIZER_9, \
EXPAND_ENTRY_INITIALIZER_8, \
EXPAND_ENTRY_INITIALIZER_7, \
EXPAND_ENTRY_INITIALIZER_6, \
EXPAND_ENTRY_INITIALIZER_5, \
EXPAND_ENTRY_INITIALIZER_4, \
EXPAND_ENTRY_INITIALIZER_3, \
EXPAND_ENTRY_INITIALIZER_2, \
EXPAND_ENTRY_INITIALIZER_1  )(__VA_ARGS__))

#define TABLE_HEADER(...) __VA_ARGS__

#define TABLE_ENTRY(...) std::make_tuple(__VA_ARGS__)

#define DEFINE_TEST_TABLE(Name, Header, ...)\
	template <> struct TestTable<#Name##_H>{\
		inline static const decltype(EXPAND(GET_FIRST(__VA_ARGS__))) Value[]{__VA_ARGS__}; };\
	template <> struct TestTableEntry<#Name##_H>{\
		EXPAND(EXPAND_ENTRY_FIELD(Name, GET_REVERSED(Header)))\
		template<typename... Args> TestTableEntry(const std::tuple<Args...>& a_Entry) : EXPAND_ENTRY_INITIALIZER(GET_REVERSED(Header)) {}};

#define DECLARE_TEST_FILE(Name) \
template <> struct TestFile<EXPAND(__FILE__)##_H> {\
	static void Setup() {\
	Testing::NameToFileTable[ #Name ] = __FILE__;\
	Testing::FileToNameTable[ __FILE__ ] = #Name;\
	Testing::FileToTestsTable[ __FILE__ ].Na##me = #Name; }\
	inline static OnStart s_OnStart = OnStart(Setup); };

#define TEST_ASSERT( Value, Expected, Message, ... ) \
if ( !( ( Value ) == ( Expected ) ) ) {\
	Testing::TestErrorInfos[ Testing::TestFileCurrentlyRunning ][ Testing::TestCurrentlyRunning ].push_back( TestErrorInfo{} );\
	TestErrorInfo& Info = Testing::TestErrorInfos[ Testing::TestFileCurrentlyRunning ][ Testing::TestCurrentlyRunning ].back();\
	char Str[ 256 ];\
	sprintf_s( Str, 256, Message, __VA_ARGS__ );\
	Info.TestFile = Testing::TestFileCurrentlyRunning;\
	Info.TestFileName = Testing::FileToNameTable[ Info.TestFile ];\
	Info.TestName = Testing::TestCurrentlyRunning;\
	Info.Mes##sage = Str;\
	Info.V##alue = Testing::ToString( Value );\
	Info.E##xpected = Testing::ToString( Expected );\
	Info.ValueString = #Value;\
	Info.ExpectedString = #Expected;\
	Info.LineNumber = EXPAND( __LINE__ );\
	Info.TableEntry = Testing::TableEntry;\
	Testing::LastTestResult = false; }

template < Hash _Name >
struct Fixture {};

template < Hash _Name > 
struct Test {};

template < Hash _Name >
struct TestTable {};

template < Hash _Name >
struct TestTableEntry {};

template < Hash _File >
struct TestFile {};

struct TestFileInfo
{
	std::string Name;
	std::map< std::string, Action<> > Tests;
};

struct TestErrorInfo
{
	std::string TestFile;
	std::string TestFileName;
	std::string TestName;
	std::string Value;
	std::string Expected;
	std::string ValueString;
	std::string ExpectedString;
	std::string Message;
	int         LineNumber;
	int         TableEntry;
};

struct Testing
{
	inline static std::map< std::string, std::string > NameToFileTable;
	inline static std::map< std::string, std::string > FileToNameTable;
	inline static std::map< std::string, TestFileInfo > FileToTestsTable;
	inline static std::map< std::string, std::map< std::string, std::vector< TestErrorInfo > > > TestErrorInfos;
	inline static std::string TestFileCurrentlyRunning;
	inline static std::string TestCurrentlyRunning;
	inline static bool LastTestResult;
	inline static int TableEntry;
	static bool ParseArguments( int a_Count, const char** a_Arguments );
	static bool RunTests( int a_VerbosityLevel = 0 );
	static bool RunTests( const std::string& a_TestFileName, int a_VerbosityLevel = 0 );
	static bool RunTests( const std::string a_TestFileName, const std::string& a_TestName, int a_VerbosityLevel = 0 );
	static bool ExecuteTestFile( const TestFileInfo& a_TestFile, int a_VerbosityLevel = 0 );
	static bool ExecuteTestFile( const TestFileInfo& a_TestFile, const std::string& a_TestName, int a_VerbosityLevel = 0 );
	static void ShowErrors();

	template < typename T >
	static std::string ToString( T a_Value )
	{
		if constexpr ( std::is_same_v< T, bool > )
		{
			return a_Value ? "true" : "false";
		}

		if constexpr ( std::is_arithmetic_v< T > )
		{
			return std::to_string( a_Value );
		}

		if constexpr ( std::is_convertible_v< T, std::string > )
		{
			return a_Value;
		}

		if constexpr ( std::is_enum_v< T > )
		{
			return std::to_string( static_cast< std::underlying_type_t< T > >( a_Value ) );
		}

		return "";
	}

	template < Hash _Name >
	struct does_table_exist
	{
		template < Hash _T > static char test( decltype( TestTable< _T >::Value ) );
		template < Hash _T > static long test( ... );
		static constexpr bool value = sizeof( test< _Name >( 0 ) ) == sizeof( char );
	};

	template < Hash _Name >
	static constexpr bool does_table_exist_v = does_table_exist< _Name >::value;

	template < Hash _Name >
	struct ITest0
	{
		static constexpr bool HasTable = true;
		TestTableEntry<_Name> Entry{ TestTable<_Name>::Value[ 0 ] };
	};

	template < Hash _Name >
	struct ITest1
	{
		static constexpr bool HasTable = false;
	};

	template < Hash _Name >
	static void RunTable( Test< _Name >& a_Test )
	{
		for ( auto& TestCase : TestTable< _Name >::Value )
		{
			++Testing::TableEntry;
			new ( &a_Test.Entry ) TestTableEntry< _Name >{ TestCase };
			a_Test.Impl();
		}
	}
};

template < typename _Test >
void RunTest()
{
	Testing::TestFileCurrentlyRunning = _Test::GetFileName();
	Testing::TestCurrentlyRunning = _Test::GetName();
	Testing::LastTestResult = true;
	Testing::TableEntry = 0;
	_Test{}();
}

bool Testing::ParseArguments( int a_Count, const char** a_Arguments )
{
	// Check for verbosity level
	int Verbosity = 0;

	for ( int i = 0; i < a_Count; ++i )
	{
		std::string Argument( a_Arguments[ i ] );

		if ( Argument == "-v" )
		{
			Verbosity = 1;
			break;
		}
		else if ( Argument == "-vv" )
		{
			Verbosity = 2;
			break;
		}
	}

	// Check for if running specific test file only.
	bool SpecificFile = false;
	std::string SpecificFileName;

	for ( int i = 0; i < a_Count; ++i )
	{
		std::string Argument( a_Arguments[ i ] );

		if ( Argument == "-f" )
		{
			if ( !( i < a_Count - 1 ) )
			{
				std::cout << "Flag -f used, but no test file name specified after." << std::endl;
				return false;
			}

			SpecificFile = true;
			SpecificFileName = a_Arguments[ i + 1 ];
			break;
		}
	}

	// Check for if running a specific test in the specific test file.
	bool SpecificTest = false;
	std::string SpecificTestName;

	for ( int i = 0; i < a_Count; ++i )
	{
		std::string Argument( a_Arguments[ i ] );

		if ( Argument == "-t" )
		{
			if ( !( i < a_Count - 1 ) )
			{
				std::cout << "Flag -t used, but no test name specified after." << std::endl;
				return false;
			}

			if ( !SpecificFile )
			{
				std::cout << "Flag -t used, but no file name specified before." << std::endl;
				return false;
			}

			SpecificTest = true;
			SpecificTestName = a_Arguments[ i + 1 ];
			break;
		}
	}

	bool Success = false;

	if ( !SpecificFile )
	{
		Success = RunTests( Verbosity );
	}
	else if ( SpecificFile && !SpecificTest )
	{
		Success = RunTests( SpecificFileName, Verbosity );
	}
	else if ( SpecificFile && SpecificTest )
	{
		Success = RunTests( SpecificFileName, SpecificTestName, Verbosity );
	}

	if ( Success )
	{
		if ( Verbosity > 1 ) Testing::ShowErrors();
		return true;
	}

	return false;
}

bool Testing::RunTests( int a_VerbosityLevel )
{
	if ( NameToFileTable.empty() )
	{
		std::cout << "No tests found!" << std::endl;
		return false;
	}

	std::cout << "Running all tests!" << std::endl;

	for ( auto& TestFile : NameToFileTable )
	{
		auto Found = FileToTestsTable.find( TestFile.second );

		if ( Found == FileToTestsTable.end() )
		{
			continue;
		}

		ExecuteTestFile( Found->second, a_VerbosityLevel );
		std::cout << std::endl;
	}

	return true;
}

bool Testing::RunTests( const std::string& a_TestFileName, int a_VerbosityLevel )
{
	auto Found = NameToFileTable.find( a_TestFileName );

	if ( Found == NameToFileTable.end() )
	{
		std::cout << "Error: No test file called " << a_TestFileName << "!" << std::endl;
		return false;
	}

	auto Tests = FileToTestsTable.find( Found->second );

	if ( Tests == FileToTestsTable.end() || Tests->second.Tests.size() == 0 )
	{
		std::cout << "Test file called " << a_TestFileName << " is empty!" << std::endl;
		return true;
	}

	return ExecuteTestFile( Tests->second, a_VerbosityLevel );
}

bool Testing::RunTests( const std::string a_TestFileName, const std::string& a_TestName, int a_VerbosityLevel )
{
	auto Found = NameToFileTable.find( a_TestFileName );

	if ( Found == NameToFileTable.end() )
	{
		std::cout << "Error: No test file called " << a_TestFileName << "!" << std::endl;
		return false;
	}

	auto Tests = FileToTestsTable.find( Found->second );

	if ( Tests == FileToTestsTable.end() || Tests->second.Tests.size() == 0 )
	{
		std::cout << "Test file called " << a_TestFileName << " is empty!" << std::endl;
		return true;
	}

	return ExecuteTestFile( Tests->second, a_TestName, a_VerbosityLevel );
}

bool Testing::ExecuteTestFile( const TestFileInfo& a_TestFile, int a_VerbosityLevel )
{
	if ( a_VerbosityLevel < 1 )
	{
		std::cout << a_TestFile.Name << ": ";
	}
	else
	{
		std::cout << "Running test file: " << a_TestFile.Name << ": " << std::endl;
	}

	for ( auto& Test : a_TestFile.Tests )
	{
		Test.second();

		if ( a_VerbosityLevel < 1 )
		{
			std::cout << ( LastTestResult ? "*" : "F" );
		}
		else
		{
			std::cout << "\t" << Test.first << ": " << ( LastTestResult ? "[SUCCESS]" : "[FAIL]" ) << std::endl;
		}
	}

	return true;
}

bool Testing::ExecuteTestFile( const TestFileInfo& a_TestFile, const std::string& a_TestName, int a_VerbosityLevel )
{
	if ( a_VerbosityLevel < 1 )
	{
		std::cout << a_TestFile.Name << ": ";
	}
	else
	{
		std::cout << "Running test file: " << a_TestFile.Name << ": " << std::endl;
	}

	const Action<>* FoundTestFunction = nullptr;
	auto FoundTest = std::find_if( a_TestFile.Tests.begin(), a_TestFile.Tests.end(), [&]( const decltype( *a_TestFile.Tests.begin() )& a_Pair )
	{
		if ( a_Pair.first == a_TestName )
		{
			FoundTestFunction = &a_Pair.second;
			return true;
		}

		return false;
	} );

	if ( !FoundTestFunction )
	{
		std::cout << "No test with that name exists in " << a_TestFile.Name << std::endl;
		return false;
	}

	( *FoundTestFunction )();

	if ( a_VerbosityLevel < 1 )
	{
		std::cout << ( LastTestResult ? "*" : "F" );
	}
	else
	{
		std::cout << "\t" << a_TestName << ": " << ( LastTestResult ? "[SUCCESS]" : "[FAIL]" ) << std::endl;
	}

	return true;
}

void Testing::ShowErrors()
{
	for ( auto& TestFile : Testing::TestErrorInfos )
	{
		auto& TestFileName = Testing::FileToNameTable.find( TestFile.first )->second;
		std::cout << "==================================================================" << std::endl;
		std::cout << "Failure found in: " << TestFileName << std::endl;
		std::cout << "==================================================================" << std::endl;

		for ( auto& Error : TestFile.second )
		{
			for ( auto& Entry : Error.second )
			{
				std::cout << "Failure: " << Error.first << std::endl;
				std::cout << "\tWhere: (Line " << Entry.LineNumber << ") " << Entry.TestFile << std::endl;

				if ( Entry.TableEntry != 0 )
					std::cout << "\tTable Line: " << std::to_string(Entry.TableEntry).c_str() << std::endl;

				std::cout << "\tMessage: " << Entry.Message << std::endl;
				std::cout << "\tAssertion: " << Entry.ValueString << " == " << Entry.ExpectedString << std::endl;
				std::cout << "\tActual: " << Entry.Value << " == " << Entry.Expected << std::endl;
				std::cout << std::endl;
			}
		}
	}
}
