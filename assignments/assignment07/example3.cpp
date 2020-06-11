/* Example 3 - Reading from the database */
#include <iostream>

#include <mysqlx/xdevapi.h>

int main()
{
    std::cout << "Connecting to the database...\n";

    try
    {
        mysqlx::Session session("localhost", 33060, "user", "password");
        mysqlx::Schema db = session.getSchema("cis64a");

        mysqlx::Table table = db.getTable("CITY");
        mysqlx::RowResult result = table.select("*")
                                        .where("ID = :id")
                                        .bind("id", 4080)
                                        .execute();

        mysqlx::Row row = result.fetchOne();

        std::cout << "ID:          " << row[0] << "\n"
                  << "Name:        " << row[1] << "\n"
                  << "CountryCode: " << row[2] << "\n"
                  << "District:    " << row[3] << "\n"
                  << "Population:  " << row[4] << "\n\n";

        std::cout << "Done!\n";
    }
    catch (const mysqlx::Error &error)
    {
        std::cerr << "The following error occurred: " << error << "\n";
    }
}
