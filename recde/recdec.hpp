#pragma once

#include <unordered_set>
#include <stack>
#include <rulestore.hpp>

class RecurDec {
	typedef Trie<RulePart,bool> GrammarPrefix;
	std::unordered_set<std::string> allreadyDone;
	std::vector<std::string> nameStack;
	std::string current;

	void genRules(const std::string&);
	std::ostream& headerS;
	std::ostream& srcS;

	void walkTrie(const GrammarPrefix::TrieEntry*, const size_t);

public:
	RuleStore& rs;

	RecurDec(RuleStore&,std::ostream&,std::ostream&);

	void computeFirstSet();
	void genRules();
};
