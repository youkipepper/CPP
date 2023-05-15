#include <iostream>
#include <mysql.h>

int main()
{
    MYSQL mysql;
    mysql_init(&mysql);

    if (!mysql_real_connect(&mysql, "localhost", "root", "youki123", "test", 0, NULL, 0))
    {
        std::cerr << "Failed to connect to database: Error message: " << mysql_error(&mysql) << "\n";
        return 1;
    }
    else
    {
        std::cout << "Successfully connected to the database.\n";
    }

    mysql_close(&mysql);
    return 0;
}
