#include "Select.hpp"

namespace Gaia::BehaviorTree::Containers
{
	/// Perform all the actions.
	Result Select::Execute()
	{
		for (const auto& action : Actions)
		{
			if (action->Execute() == Result::Failure)
			{
				return Result::Failure;
			}
		}

		return Result::Success;
	}
}