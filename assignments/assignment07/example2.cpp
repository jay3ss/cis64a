/* Example 2 - Creating an entry */
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
        table.insert("ID", "Name", "CountryCode", "District", "Population")
             .values(4080, "Twin Peaks", "USA", "Washington", 10500)
             .execute();

        std::cout << "Done!\n";
    }
    catch (const mysqlx::Error &error)
    {
        std::cerr << "The following error occurred: " << error << "\n";
    }
}
