#pragma once

#include "node.h"
#include "token.h"

#include <iostream>
#include <map>

std::shared_ptr<Node> ParseCondition(std::istream& is);

void TestParseCondition();
