#pragma once

#include "Result.hpp"

namespace Gaia::BehaviorTree
{
	/**
	 * @brief Basic component unit of a behavior tree.
	 * @detials
	 * 	Some types of action can contain other actions,
	 * 	and invoke their children actions according to their own rules.
	 * 	So depending on the specific situations,
	 * 	it can represent a certain action, or the beginning node of a tree.
	 */
	class Action
	{
	public:
		/**
		 * @brief Action behavior body.
		 * @retval Result::Success This action is finished successfully.
		 * @retval Result::Failure This action failed or stopped midway.
		 * @details
		 * 	This function should finish a task once a time.
		 * 	To maintain high reusability, fine-grained operations are recommended.
		 */
		virtual Result Execute() = 0;
	};
}