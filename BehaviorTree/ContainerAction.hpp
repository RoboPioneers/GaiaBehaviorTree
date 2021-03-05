#pragma once

#include "Action.hpp"

#include <list>
#include <memory>

namespace Gaia::BehaviorTree
{
	/**
	 * @brief Container can contain other actions.
	 * @details
	 *  Container Action represents an abstract container which can contain several actions,
	 *  and invoke them according to its specific rule.
	 */
	class ContainerAction : public Action
	{
	protected:
		/// Actions in this container
		std::list<std::unique_ptr<Action>> Actions;

	public:
		/**
		 * @brief Add an action to this container.
		 * @tparam ActionClass Type of the new action.
		 * @tparam ConstructorArguments Types of the parameters for the constructor.
		 * @param arguments Parameters for the constructor.
		 * @return Pointer of the new instance of ActionClass.
		 * @details
		 *  This function will create a instance of the ActionClass and maintain its memory with unique_ptr.
		 */
		template<typename ActionClass, typename... ConstructorArguments>
		ActionClass* AddAction(ConstructorArguments... arguments)
		{
			static_assert(std::is_base_of_v<Action, ActionClass>);

			auto* action = new ActionClass(arguments...);
			Actions.emplace_back(static_cast<Action*>(action));

			return action;
		}
	};
}
