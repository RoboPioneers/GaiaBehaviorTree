#pragma once

namespace Gaia::BehaviorTree
{
	/**
	 * @brief Execution result of an action.
	 * @details It's widely used to control the logic of the behavior tree.
	 */
	enum class Result
	{
		Success,
		Failure
	};

	/**
	 * @brief Reverse a result
	 * @param source original result
	 * @retval Result::Failure When source is Result::Success
	 * @retval Result::Success When source is Result::Failure
	 */
	inline Result operator!(const Result& source)
	{
		switch (source)
		{
			case Result::Success:
				return Result::Failure;
			case Result::Failure:
				return Result::Success;
			// This tag is not necessary, but is kept in order to erase compiler's warning.
			default:
				return Result::Failure;
		}
	}
}