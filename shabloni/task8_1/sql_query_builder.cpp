#include "sql_query_builder.h"
#include <iostream>

SqlSelectQueryBuilder::SqlSelectQueryBuilder() {
    this->column = "";
    this->name_table = "";
};

SqlSelectQueryBuilder::~SqlSelectQueryBuilder() {
};

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(std::string column) {
    if ((this->column).size() == 0) {
        this->column += column;
    }
    else {
        this->column += (", " + column);
    }
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(std::string name) {
    this->name_table = name;
    return *this;
};

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(std::string id,  std::string val) {
    this->id = id;
    this->id_val = val;
    this->where_status = true;
    return *this;
};

std::string SqlSelectQueryBuilder::BuildQuery() {
    this->Query = "SELECT ";
    
    if ((this->column).size() != 0) {
        this->Query += this->column;
    }
    else {
        this->Query += " * ";
    }

    this->Query += " FROM " + this->name_table;

    if (this->where_status) {
        this->Query += " WHERE " + this->id + "=" + this->id_val;

        this->Query += ";";
    }

    return this->Query;
}