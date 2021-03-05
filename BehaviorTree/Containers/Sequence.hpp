#pragma once

#include "../ContainerAction.hpp"

#include <list>
#include <memory>

namespace Gaia::BehaviorTree::Containers
{
	/**
	 * @brief Container of actions which will be performed in sequence and stop if an action fails.
	 * @details
	 *  Actions in a sequence will be performed from the beginning of the sequence to the end,
	 *  and once an action returns Result::Failure, the execution of Sequence will immediately stop.
	 *  In other words, a sequence will succeed only if all of its children actions succeed.
	 */
	class Sequence : public ContainerAction
	{
	public:
		/**
		 * @brief Invoke all action from the beginning action in sequence, and stop if an action fails.
		 * @retval Result::Failure When One or more actions failed.
		 * @retval Result::Success When it is empty or all action succeeded.
		 */
		Result Execute() override;
	};
}