#pragma once
#include <vector>
#include <map>

#include "Invoker.hpp"
#include "Name.hpp"
#include "MacroHelpers.hpp"

#define DECLARE_ONSTART_0( Name ) \
struct On##Name : public OnStart \
{ \
    On##Name( Action< OnStartActionType > a_Action ) \
        : OnStart( #Name##_H, a_Action, {} ) \
    {} \
};

#define DECLARE_ONSTART_1( Name, Prerequisite ) \
struct On##Name : public OnStart \
{ \
    On##Name( Action< OnStartActionType > a_Action ) \
        : OnStart( #Name##_N, a_Action, { #Prerequisite##_H } ) \
    {} \
}

#define DECLARE_ONSTART(...) EXPAND(GET_MACRO_2(__VA_ARGS__, DECLARE_ONSTART_1, DECLARE_ONSTART_0)(__VA_ARGS__))

#define DEFINE_ONSTART( Name ) volatile On##Name s_On##Name = ( Action< OnStartActionType > )[]( OnStartActionType ActionType )

enum OnStartActionType
{
	OnStartActionType_Teardown,
	OnStartActionType_Startup
};

class OnStart
{
private:

	struct Node
	{
		Name Name;
		bool Fired = false;
		bool Registered = false;
		Action< OnStartActionType > Action;
		std::vector< Node* > Requirements;
		std::vector< Node* > Dependants;

		void TriggerStartup();
		void TriggerTeardown();
	};

public:

#ifdef ONSTART_AUTO_TRIGGER
	static constexpr bool AutoTrigger = true;
#else
	static constexpr bool AutoTrigger = false;
#endif

	OnStart( const Action<>& a_Action );
	OnStart( const Name& a_Name, const Action< OnStartActionType >& a_Action, std::initializer_list< Hash > a_Requirements = {} );

	/// <summary>
	/// Trigger a startup for all registered OnStart's. If a startup has already occured, this will do nothing.
	/// If you set ForceStartup to true and a startup has already occurred, a teardown will happen first.
	/// </summary>
	static void Startup( bool a_ForceStartup = false );

	/// <summary>
	/// Trigger a teardown for all registered OnStart's. If a a teardown has already occured, this will do nothing.
	/// If you set ForceTeardown to true, a teardown will occur regardless.
	/// </summary>
	static void Teardown( bool a_ForceTeardown = false );

	/// <summary>
	/// Check if an OnStart by the given name has just been fired.
	/// </summary>
	static bool HasFired( Hash a_Name );

	/// <summary>
	/// Check to see if a Startup has already occured as the last action.
	/// </summary>
	static bool IsReady();

private:

	static void Reset();
	static auto& HasReset() { static bool Value = !AutoTrigger; return Value; }
	static auto& GetRoots() { static std::vector< Node* > s_Roots; return s_Roots; }
	static auto& GetNodes() { static std::map< Hash, Node > s_Nodes; return s_Nodes; }
};