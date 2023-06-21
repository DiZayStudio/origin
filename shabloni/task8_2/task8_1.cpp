#include <iostream>
#include "sql_query_builder.h"
#include <string>
#include <map>
#include <vector>


int main() {
    SqlSelectQueryBuilder query_builder;

    std::vector<std::string> columns;
    columns.push_back("name");
    columns.push_back("phone");
    query_builder.AddColumns(columns);

    query_builder.AddFrom("students");

    std::map<std::string, std::string> kv;
    kv["id"]= "42";
    kv["name"] = "John";

    query_builder.AddWhere(kv);
  
    std::cout << query_builder.BuildQuery();
    //static_assert(query_builder.BuildQuery(),"SELECT name, phone FROM students WHERE id=42 AND name=John;");

    return 0;
}