
#ifndef _STATEMENT_EVALUATOR_H_
#define _STATEMENT_EVALUATOR_H_

#include "Tree.h"
#include <functional>
#include <unordered_map>
#include <vector>
#include <iomanip>

class StatementEvaluator{
	public:
		bool evaluateStatement(const StatementParser& s, const std::vector<std::pair<std::string, bool> >& variableTruthValues) const;
		void printTruthTable(const StatementParser& s, const std::vector<std::string>& variableNames) const;
		bool areLogicallyEquivalent(const StatementParser& s1, const StatementParser& s2) const;

	private:
		//Mapping of operation characters to the corresponding functions.
		std::unordered_map<char, std::function<bool (bool, bool)> > functionMap = {
			{'|', [](bool p, bool q){return p || q;}},
			{'&', [](bool p, bool q){return p && q;}},
			{'@', [](bool p, bool q){return p xor q;}}
		};

		bool evaluateBranch(StatementNode* p, const std::unordered_map<std::string, bool>& variableValues) const;
		void recurseDownArray(const StatementParser& s, std::vector<std::pair<std::string, bool> >& variableTruthValues, unsigned int index, unsigned int maxStringSize) const;
		void printVariableHeaders(const std::vector<std::string>& variableNames, int maxStringSize) const;
};

#endif