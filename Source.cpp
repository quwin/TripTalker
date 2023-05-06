#include <iostream>
#include <sqlite3.h>

void instantiate_db()
{
    sqlite3* db;

    int rc = sqlite3_open("mydatabase.db", &db);

    if (rc != SQLITE_OK) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        return;
    }
    std::cout << "Opening Worked!\n";

    // Create table
    const char* create_table_query = "CREATE TABLE items (id INTEGER PRIMARY KEY, name TEXT, quantity INTEGER, size TEXT, location TEXT)";
    rc = sqlite3_exec(db, create_table_query, NULL, 0, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "Error creating table: " << sqlite3_errmsg(db) << std::endl;
        return;
    }
    else {
        std::cout << "Creation Worked!\n";
    }

    // Insert data
    const char* insert_query = "INSERT INTO items (name, quantity, size, location) VALUES ('water bottle', 1, 'medium', 'checkpoint')";
    rc = sqlite3_exec(db, insert_query, NULL, 0, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "Error inserting data: " << sqlite3_errmsg(db) << std::endl;
        return;
    }
    else {
        std::cout << "Insert Worked!\n";
    }

    // Close connection to database
    sqlite3_close(db);

    return;
}

int main()
{
    instantiate_db();

    std::cout << "Hello World!\n";
}
