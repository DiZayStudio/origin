#pragma once
#include <string>

class SqlSelectQueryBuilder {
private:
	std::string column;
	std::string name_table;
	std::string id;
	std::string id_val;
	bool where_status;
	std::string Query;

public:
	SqlSelectQueryBuilder();
	~SqlSelectQueryBuilder();

	SqlSelectQueryBuilder& AddColumn(std::string column);
	SqlSelectQueryBuilder& AddFrom(std::string name);
	SqlSelectQueryBuilder& AddWhere(std::string id, std::string val);

	std::string BuildQuery();
};