#include "Sequence.hpp"

namespace Gaia::BehaviorTree::Containers
{
	/// Perform all the actions.
	Result Sequence::Execute()
	{
		for (const auto& action : Actions)
		{
			if (action->Execute() == Result::Success)
			{
				return Result::Success;
			}
		}

		return Result::Failure;
	}
}
