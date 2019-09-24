#include <string>

class StatementNode {
public:
	StatementNode* left;
	StatementNode* right;
	std::string value
};

class StatementParser {
private:
	StatementParser();
	StatementParser(std::string statement);
	

	StatementNode* Head;

}