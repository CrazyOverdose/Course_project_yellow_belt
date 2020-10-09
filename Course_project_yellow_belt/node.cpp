#include "node.h"

DateComparisonNode::DateComparisonNode(const Comparison& comp, const Date& date_1) : Comp_(comp), date_(date_1) {};

EventComparisonNode::EventComparisonNode(const Comparison& comp, const std::string& value_1)
	: Comp_(comp), value_(value_1) {};

LogicalOperationNode::LogicalOperationNode(const LogicalOperation& oper, const std::shared_ptr<Node>& l, const std::shared_ptr<Node>& r) :
	Operation_(oper), Left_(l), Right_(r) {};

bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
	if (Comp_ == Comparison::Less)
		return date < date_;

	else if (Comp_ == Comparison::LessOrEqual)
		return date <= date_;

	else if (Comp_ == Comparison::Greater)
		return date > date_;

	else if (Comp_ == Comparison::GreaterOrEqual)
		return date >= date_;

	else if (Comp_ == Comparison::Equal)
		return date == date_;

	else if (Comp_ == Comparison::NotEqual)
		return date != date_;

	return false;
}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
	if (Comp_ == Comparison::Less)
		return event < value_;

	else if (Comp_ == Comparison::LessOrEqual)
		return event <= value_;

	else if (Comp_ == Comparison::Greater)
		return event > value_;

	else if (Comp_ == Comparison::GreaterOrEqual)
		return event >= value_;

	else if (Comp_ == Comparison::Equal)
		return event == value_;

	else if (Comp_ == Comparison::NotEqual)
		return event != value_;

	return false;
}

bool EmptyNode::Evaluate(const Date& date, const string& event) const {
	return true;
}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {


	if (Operation_ == LogicalOperation::And)
		return Left_->Evaluate(date, event) && Right_->Evaluate(date, event);

	else if (Operation_ == LogicalOperation::Or)
		return Left_->Evaluate(date, event) || Right_->Evaluate(date, event);

	return false;
}
