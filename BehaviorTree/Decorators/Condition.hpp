#pragma once

#include "../DecoratorAction.hpp"

namespace Gaia::BehaviorTree::Decorators
{
	/**
	 * @brief Conditionally perform the decorated action.
	 * @details
	 *  When Execute() function is called, the decorated action will be conditionally performed,
	 *  according to the return value of IsConditionSatisfied().
	 *  Only when IsConditionSatisfied() returns true, the decorated action will be performed,
	 *  otherwise Execute() will return SubstitutionResult, and it's Result::Failure by default.
	 */
	class Condition : public DecoratorAction
	{
	protected:
		/**
		 * @brief Check whether the condition is satisfied or not.
		 * @retval true The condition is satisfied and the action will be performed.
		 * @retval false The condition is not satisfied and the action won't be performed.
		 */
		virtual bool IsConditionSatisfied() = 0;

	public:
		/// When condition is not satisfied, Execute() will return this value.
		Result SubstitutionResult {Result::Failure};

		/**
		 * @brief Check the condition and conditionally perform the action.
		 * @retval SubstitutionResult - When condition is not satisfied.
		 * @retval Result form the decorated action - When condition is satisfied.
		 */
		Result Execute() override;
	};
}
