#pragma once
#include <string>
#include <map>
#include <vector>

class SqlSelectQueryBuilder {
private:

	std::string name_table;

	std::map<std::string, std::string> kv;
	std::vector<std::string> columns;
	bool where_status;
	std::string Query;

public:
	SqlSelectQueryBuilder();
	~SqlSelectQueryBuilder();

	SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept;

	SqlSelectQueryBuilder& AddFrom(const std::string name);

	SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept;

	std::string BuildQuery();
};