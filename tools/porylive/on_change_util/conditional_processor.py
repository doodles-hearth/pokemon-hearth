import re
from typing import Dict, List, Any, Union
from .logger import Logger
from .porylive_types import ScriptParams

class ConditionalProcessor:
    """Handles complex conditional logic for macro adjustments"""

    def __init__(self, logger: Logger):
        self.logger = logger

    def evaluate_condition(self, script: ScriptParams, condition: Dict[str, Any]) -> bool:
        """Evaluate a single condition against the script parameters"""

        condition_type = condition.get("$condition")
        expected_value = condition.get("$value")

        if not condition_type:
            self.logger.log_message(f"[evaluate_condition] Missing $condition in condition: {condition}")
            return False

        actual_value = self._get_actual_value_for_condition(script, condition_type)
        if actual_value is None:
            return False

        return self._match_value(actual_value, expected_value)

    def _get_actual_value_for_condition(self, script: ScriptParams, condition_type: str) -> Any:
        """Get the actual value from the script based on the condition type"""

        # Handle num_args condition
        if condition_type == "num_args" or condition_type == "arg_num":
            return len(script["params"])

        # Handle arg[n] conditions
        elif re.match(r'^arg\[\d+\]$', condition_type):
            try:
                arg_index = int(condition_type[4:-1])  # Remove "arg[" and "]"
            except (ValueError, IndexError):
                self.logger.log_message(f"[_get_actual_value_for_condition] Invalid arg condition format: {condition_type}")
                return None

            if arg_index >= len(script["params"]):
                self.logger.log_message(f"[_get_actual_value_for_condition] Argument index {arg_index} out of range for {script['name']}")
                return None

            return script["params"][arg_index]

        else:
            self.logger.log_message(f"[_get_actual_value_for_condition] Unknown condition type: {condition_type}")
            return None

    def _match_value(self, actual_value: Any, expected_value: Any) -> bool:
        """Match actual value against expected value, handling special operators"""

        if isinstance(expected_value, dict):
            # Handle special value operators
            if "$in" in expected_value:
                return actual_value in expected_value["$in"]
            elif "$nin" in expected_value:
                return actual_value not in expected_value["$nin"]
            else:
                self.logger.log_message(f"[_match_value] Unknown value operator in: {expected_value}")
                return False
        else:
            # Direct value comparison
            return actual_value == expected_value

    def evaluate_logical_expression(self, script: ScriptParams, expression: Union[Dict[str, Any], List[Dict[str, Any]]]) -> bool:
        """Evaluate a logical expression (with $or, $and, or single condition)"""

        if isinstance(expression, dict):
            if "$or" in expression:
                # At least one condition must be true
                conditions = expression["$or"]
                return any(self.evaluate_logical_expression(script, cond) for cond in conditions)

            elif "$and" in expression:
                # All conditions must be true
                conditions = expression["$and"]
                return all(self.evaluate_logical_expression(script, cond) for cond in conditions)

            elif "$condition" in expression:
                # Single condition
                return self.evaluate_condition(script, expression)

            else:
                self.logger.log_message(f"[evaluate_logical_expression] Unknown logical operator in: {expression}")
                return False

        elif isinstance(expression, list):
            # Treat list as implicit $and
            return all(self.evaluate_logical_expression(script, cond) for cond in expression)

        else:
            self.logger.log_message(f"[evaluate_logical_expression] Invalid expression type: {type(expression)}")
            return False

    def process_conditional_macro(self, script: ScriptParams, macro_info: Dict[str, Any]) -> List[Dict[str, Any]]:
        """Process a conditional macro with $if/$true/$false structure or $condition-based structure"""

        if "$if" in macro_info:
            # $if/$true/$false format
            if_condition = macro_info["$if"]
            true_branch = macro_info.get("$true", [])
            false_branch = macro_info.get("$false", [])

            if self.evaluate_logical_expression(script, if_condition):
                selected_branch = true_branch
            else:
                selected_branch = false_branch

            # Check if the selected branch is a recursive conditional
            if isinstance(selected_branch, dict):
                # Recursively process the conditional branch
                return self.process_conditional_macro(script, selected_branch)
            elif isinstance(selected_branch, list):
                # Return the list of adjustments
                return selected_branch
            else:
                self.logger.log_message(f"[process_conditional_macro] Invalid branch type: {type(selected_branch)}")
                return []

        elif "$condition" in macro_info:
            # $condition-based format (with either $value or $matches)
            if "$value" in macro_info:
                # $condition + $value format - single condition check
                if self.evaluate_condition(script, macro_info):
                    return macro_info.get("$adjustments", [])
                else:
                    return []
            elif "$matches" in macro_info:
                # $condition + $matches format - multiple condition checks
                return self._handle_matches_condition(script, macro_info)
            else:
                self.logger.log_message(f"[process_conditional_macro] $condition requires either $value or $matches")
                return []

        else:
            self.logger.log_message(f"[process_conditional_macro] Unknown conditional format: {macro_info}")
            return []

    def _handle_matches_condition(self, script: ScriptParams, macro_info: Dict[str, Any]) -> List[Dict[str, Any]]:
        """Handle $condition + $matches format"""

        condition_type = macro_info.get("$condition")
        matches = macro_info.get("$matches", [])

        if not condition_type:
            return []

        actual_value = self._get_actual_value_for_condition(script, condition_type)
        if actual_value is None:
            return []

        # Check each match in the list
        if not isinstance(matches, list):
            self.logger.log_message(f"[_handle_matches_condition] $matches must be a list, got: {type(matches)}")
            return []

        # Process each match item
        for match_item in matches:
            if not isinstance(match_item, dict):
                continue

            expected_value = match_item.get("$value")
            if expected_value is not None and self._match_value(actual_value, expected_value):
                return match_item.get("$adjustments", [])

        # Return empty list if no condition matches
        return []
