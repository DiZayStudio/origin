#include "sql_query_builder.h"
#include <iostream>

SqlSelectQueryBuilder::SqlSelectQueryBuilder() {
    this->name_table = "";
};

SqlSelectQueryBuilder::~SqlSelectQueryBuilder() {
};

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumns(const std::vector<std::string>& columns) noexcept {
    if (columns.size() != 0) {
        for (auto i : columns) {
            this->columns.push_back(i);
        }
    }
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(std::string name) {
    this->name_table = name;
    return *this;
};


SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::map<std::string, std::string>& kv) noexcept {
    if (!kv.empty()) {
        this->where_status = true;

        for (auto i : kv) {
            this->kv[i.first] = i.second;
        }
    }
    return *this;
}

std::string SqlSelectQueryBuilder::BuildQuery() {
    this->Query = "SELECT ";
    
    if (this->columns.size() != 0) {
        for (int i = 0; i < this->columns.size();i++) {
            this->Query += this->columns[i];

            if (i < this->columns.size()-1) {
                this->Query += ", ";
            }
        }
        
    }
    else {
        this->Query += " * ";
    }

    this->Query += " FROM " + this->name_table;

    if (this->where_status) {
        this->Query += " WHERE ";

            std::map <std::string, std::string> ::iterator it = this->kv.begin();
            for (int i = 0; it != this->kv.end(); it++, i++) {
                this->Query += it->first + "=" + it->second;
                if (i < this->kv.size()-1) {
                    this->Query += " AND ";
                }
            }
        this->Query += ";";
    }

    return this->Query;
}