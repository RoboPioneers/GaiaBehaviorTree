#pragma once

#include "../ContainerAction.hpp"

namespace Gaia::BehaviorTree::Containers
{
	/**
	 * @brief Container of actions which will be performed in sequence and stop if an action succeeds.
	 * @details
	 *  Actions in a sequence will be performed from the beginning of the sequence to the end,
	 *  and once an action returns Result::Success, the execution of Sequence will immediately stop.
	 *  In other words, a sequence will fail only if all of its children actions fail.
	 */
	class Select : public ContainerAction
	{
	public:
		/**
		 * @brief Invoke all action from the beginning action in sequence, and stops if an action succeeds.
		 * @retval Result::Failure When it is empty or all action fails.
		 * @retval Result::Success When One or more actions succeeds.
		 */
		Result Execute() override;
	};
}
