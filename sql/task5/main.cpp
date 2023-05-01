#include <iostream>
#include <pqxx/pqxx>
#include <string>
#include <Windows.h>
#pragma execution_character_set("utf-8")

const std::string CONST_CONNECTION = "host=localhost port=5432 dbname=postgres user=postgres password=12345678";

class posdb {

public:
	posdb() {}
	
	void SetConnection(std::unique_ptr<pqxx::connection> in_c)
	{
		c = std::move(in_c);
	}
	posdb(const posdb&) = delete;
	posdb& operator=(const posdb&) = delete;

	void CreateTable() {
		pqxx::work tx{ *c };
		tx.exec("CREATE TABLE IF NOT EXISTS clients (id SERIAL PRIMARY KEY, first_name VARCHAR(100) NOT NULL, last_name VARCHAR(100) NOT NULL, e_mail VARCHAR(100) UNIQUE NOT NULL); ");
		tx.exec("CREATE TABLE IF NOT EXISTS phones (phone VARCHAR(100) UNIQUE NOT NULL, client_id integer NOT NULL); ");
		tx.commit();
	}

	void InsertClient(std::string first_name, std::string last_name, std::string e_mail) {
		pqxx::work tx{ *c };
		std::string query = "INSERT INTO clients (first_name, last_name, e_mail) VALUES('" + tx.esc(first_name) + "','" + tx.esc(last_name) + "','" + tx.esc(e_mail) + "')";
		tx.exec(query);
		tx.commit();
	};

	void InsertPhone(std::string first_name, std::string last_name, std::string phone) {
		pqxx::work tx{ *c };
		int id = tx.query_value<int>("SELECT id FROM clients WHERE first_name = '" + first_name + "' and last_name = '" + last_name + "'; ");	
		if (id > 0) {
			std::string query = "INSERT INTO phones (phone, client_id) VALUES('" + tx.esc(phone) + "', '" + tx.esc(std::to_string(id)) + "')";
			tx.exec(query);
			tx.commit();
		}
	};

	void СhangeFirstName(std::string first_name, std::string last_name, std::string NewFirstName) {
		pqxx::work tx{ *c };
		int id = tx.query_value<int>("SELECT id FROM clients WHERE first_name = '" + first_name + "' and last_name = '" + last_name + "'; ");
		if (id > 0) {
			std::string query = "UPDATE clients SET first_name = '" + tx.esc(NewFirstName) + "' WHERE id = " + std::to_string(id);
			tx.exec(query);
			tx.commit();
		}
	}

	void СhangeLastName(std::string first_name, std::string last_name, std::string NewLastName) {
		pqxx::work tx{ *c };
		int id = tx.query_value<int>("SELECT id FROM clients WHERE first_name = '" + first_name + "' and last_name = '" + last_name + "'; ");
		if (id > 0) {
			std::string query = "UPDATE clients SET last_name = '" + tx.esc(NewLastName) + "' WHERE id = " + std::to_string(id);
			tx.exec(query);
			tx.commit();
		}
	}

	void СhangeE_mail(std::string first_name, std::string last_name, std::string NewE_mail) {
		pqxx::work tx{ *c };
		int id = tx.query_value<int>("SELECT id FROM clients WHERE first_name = '" + first_name + "' and last_name = '" + last_name + "'; ");
		if (id > 0){
			std::string query = "UPDATE clients SET e_mail = '" + tx.esc(NewE_mail) + "' WHERE id = " + std::to_string(id);
			tx.exec(query);
			tx.commit();
		}
	}

	void DeletePhone(std::string phone) {
		pqxx::work tx{ *c };

		std::string query = "DELETE FROM phones WHERE phone = '" + tx.esc(phone) + "'";
		tx.exec(query);
		tx.commit();		
	} 

	void DeleteClient(std::string first_name, std::string last_name) {
		pqxx::work tx{ *c };
		int id = tx.query_value<int>("SELECT id FROM clients WHERE first_name = '" + first_name + "' and last_name = '" + last_name + "'; ");
		if (id > 0) {
			std::string query = "DELETE FROM phones WHERE client_id = " + std::to_string(id);
			tx.exec(query);
			query = "DELETE FROM clients WHERE id = " + std::to_string(id);
			tx.exec(query);
			tx.commit();
		}
	}

	int SerchIDByName(std::string first_name, std::string last_name) {
		if (!c)	{
			return { };
		}
		pqxx::work tx{ *c };
		int id = tx.query_value<int>("SELECT id FROM clients WHERE first_name = '" + first_name + "' and last_name = '" + last_name + "'; ");
		return id;
	}

	int SerchIDByEmail(std::string e_mail) {
		pqxx::work tx{ *c };
		int id = tx.query_value<int>("SELECT id FROM clients WHERE e_mail = '" + e_mail + "'");
		return id;
	}

	int SerchIDByPhone(std::string phone) {
		pqxx::work tx{ *c };
		int id = tx.query_value<int>("SELECT client_id FROM phones WHERE phone = '" + phone + "'");
		return id;
	}

protected:

	std::unique_ptr<pqxx::connection> c;
};


int main (){
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	setvbuf(stdout, nullptr, _IOFBF, 1000);
	
	try {
		posdb db;
		std::unique_ptr<pqxx::connection> c = std::make_unique<pqxx::connection>(CONST_CONNECTION);

		db.SetConnection(std::move(c));

		db.CreateTable();
	
		// добавить нового клиента
		db.InsertClient("Vasya", "Pupkin", "12345@mail.ru");
		db.InsertClient("Vasya2", "Pupkin2", "134@mail.ru");
		db.InsertClient("Vasya3", "Pupkin3", "13@mail.ru");
		db.InsertClient("Vasya4", "Pupkin4", "1@mail.ru");
	// добавить телефон для существующего клиента
		db.InsertPhone("Vasya", "Pupkin", "7302-11-23");
		db.InsertPhone("Vasya", "Pupkin", "7320-22-23");
		db.InsertPhone("Vasya2", "Pupkin2", "3420-1-23");
		db.InsertPhone("Vasya4", "Pupkin4", "740-55-23");

	// поиск id клиента по имени 
		int id = db.SerchIDByName("Vasya", "Pupkin");
		std::cout << id << std::endl;
	
	// поиск id клиента по e_mail 
		id = db.SerchIDByEmail("134@mail.ru");
		std::cout << id << std::endl;

	// поиск id клиента по телефону
		id = db.SerchIDByPhone("7302-11-23");
		std::cout << id << std::endl;

	// изменить имя клиентa
		db.СhangeFirstName("Vasya3", "Pupkin3", "VasyaNew");
	 
	// изменить фамилию клиентa
		db.СhangeLastName("Vasya4", "Pupkin4", "PupkinNew");
	
	// изменить e-mail клиентa
		db.СhangeE_mail("Vasya", "Pupkin", "new@mail.ru");

	// удалить телефон для существующего клиента
		db.DeletePhone("740-55-23");

	// удалить клиента
		db.DeleteClient("Vasya", "Pupkin");
	}
	catch (pqxx::sql_error e) {
		std::cout << e.what() << std::endl;
	}
	 catch (std::exception e) {
	 	std::cout << e.what() << std::endl;
	 }
}
