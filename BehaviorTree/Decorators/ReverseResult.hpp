#pragma once

#include "../DecoratorAction.hpp"

namespace Gaia::BehaviorTree::Decorators
{
	/**
	 * @brief Used to reverse the execution result of an action.
	 */
	class ReverseResult : public DecoratorAction
	{
	public:
		/**
		 * @brief Perform the decorated action and reverse its result.
		 * @retval Result::Success When DecoratedAction returns Result::Failure or it's empty.
		 * @retval Result::Failure When DecoratedAction returns Result::Success.
		 */
		Result Execute() override
		{
			if (DecoratedAction)
			{
				return !DecoratedNode->Execute();
			}
			return Result::Failure;
		}
	};
}