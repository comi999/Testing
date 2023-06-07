#include "OnStart.hpp"

OnStart::OnStart( const Action<>& a_Action )
{
	a_Action();
}

OnStart::OnStart( const Name& a_Name, const Action< OnStartActionType >& a_Action, std::initializer_list< Hash > a_Requirements )
{
	// Try to insert an OnStart node by the name given.
	Node& ThisNode = GetNodes()[ a_Name ];

	if ( !ThisNode.Registered )
	{
		ThisNode.Name = a_Name;
		ThisNode.Registered = true;
		ThisNode.Action = a_Action;
	}

	// Register all requirements if there are requirements. If none, register as a root.
	if ( a_Requirements.size() > 0 )
	{
		for ( Hash Requirement : a_Requirements )
		{
			Node& RequirementNode = GetNodes()[ Requirement ];
			ThisNode.Requirements.push_back( &RequirementNode );
			RequirementNode.Dependants.push_back( &ThisNode );
		}
	}
	else
	{
		GetRoots().push_back( &ThisNode );
	}

	// If auto trigger is enabled, then cascade a fire event downwards if all requirements have fired.
	if constexpr ( AutoTrigger )
	{
		ThisNode.TriggerStartup();
	}
}

void OnStart::Node::TriggerStartup()
{
	for ( auto Requirement : Requirements )
	{
		if ( !Requirement->Fired )
		{
			return;
		}
	}

	Action.Invoke( OnStartActionType_Startup );
	Fired = true;

	for ( auto Dependant : Dependants )
	{
		Dependant->TriggerStartup();
	}
}

void OnStart::Node::TriggerTeardown()
{
	// If this node has already been torn down, then return.
	if ( Fired )
	{
		return;
	}

	// If not, wait for all dependents to be torn down first.
	for ( auto Dependant : Dependants )
	{
		Dependant->TriggerTeardown();
	}

	// ...then trigger the teardown.
	Action.Invoke( OnStartActionType_Teardown );
	Fired = true;
}

void OnStart::Reset()
{
	for ( auto& Node : GetNodes() )
	{
		Node.second.Fired = false;
	}
}

void OnStart::Startup( bool a_ForceStartup )
{
	if ( !a_ForceStartup && IsReady() )
	{
		return;
	}

	if ( !HasReset() )
	{
		Teardown();
		Reset();
	}

	for ( auto Root : GetRoots() )
	{
		Root->TriggerStartup();
	}

	HasReset() = false;
}

void OnStart::Teardown( bool a_ForceTeardown )
{
	if ( !a_ForceTeardown && !IsReady() )
	{
		return;
	}

	Reset();

	for ( auto Root : GetRoots() )
	{
		Root->TriggerTeardown();
	}

	HasReset() = true;
}

bool OnStart::HasFired( Hash a_Name )
{
	auto Iter = GetNodes().find( a_Name );
	return Iter == GetNodes().end() ? false : Iter->second.Fired;
}

bool OnStart::IsReady()
{
	return !HasReset();
}