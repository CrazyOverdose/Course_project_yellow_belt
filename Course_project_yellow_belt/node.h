#pragma once
#include "date.h"

using std::string;



enum class Comparison {
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual,
};

enum class LogicalOperation {
	And,
	Or,
};

class Node {

public:
	virtual bool Evaluate(const Date& date, const string& event) const = 0;

};

class DateComparisonNode : public Node {
public:
	DateComparisonNode(const Comparison& comp, const Date& date_1);
	bool Evaluate(const Date& date, const string& event) const override;

private:
	const Date date_;
	const Comparison Comp_;
};

class EventComparisonNode : public Node {
public:
	EventComparisonNode(const Comparison& comp, const std::string& value_1);
	bool Evaluate(const Date& date, const string& event) const override;

private:
	const std::string value_;
	const Comparison Comp_;
};

class EmptyNode : public Node {
public:
	bool Evaluate(const Date& date, const string& event) const override;
};


class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(const LogicalOperation& oper, const std::shared_ptr<Node>& l, const std::shared_ptr<Node>& r);
	bool Evaluate(const Date& date, const string& event) const override;

private:
	const LogicalOperation Operation_;
	const std::shared_ptr<Node> Left_;
	const std::shared_ptr<Node> Right_;
};
