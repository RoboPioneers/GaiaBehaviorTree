#pragma once

#include "Action.hpp"

#include <memory>

namespace Gaia::BehaviorTree
{
	/**
	 * @brief Decorator can non-intrusively add functions or features to another action.
	 * @details
	 *  Decorator Action represents conditional control logic or result modification.
	 */
	class DecoratorAction : public Action
	{
	protected:
		/// The action which will be added functions or features.
		std::unique_ptr<Action> DecoratedAction;

	public:
		/**
		 * @brief Create a sub action and decorate it.
		 * @tparam ActionClass Type the action to be instantiated.
		 * @tparam ConstructorArguments Types of the parameters for the constructor of ActionClass.
		 * @param arguments Parameters for the constructor of ActionClass.
		 * @details
		 *  This function will create an instance of ActionClass, and manage its memory with unique_ptr.
		 *  The previous action instance will be released if it exists.
		 */
		template<typename ActionClass, typename... ConstructorArguments>
		ActionClass* PlaceAction(ConstructorArguments... arguments)
		{
			static_assert(std::is_base_of_v<Action, ActionClass>);

			auto* action = new ActionClass(arguments...);
			DecoratedAction = std::unique_ptr<Action>(static_cast<Action*>(action));

			return action;
		}
	};
}