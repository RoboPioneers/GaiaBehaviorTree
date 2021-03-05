#include "Condition.hpp"

namespace Gaia::BehaviorTree::Decorators
{
	/// Conditionally perform the decorated action.
	Result Condition::Execute()
	{
		if (IsConditionSatisfied() && DecoratedAction)
		{
			return DecoratedAction->Execute();
		}
		return SubstitutionResult;
	}
}
