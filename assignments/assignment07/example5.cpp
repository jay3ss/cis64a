/* Example 5 - Deleting an entry */
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
        table.remove()
			 .where("Name = :name AND CountryCode = :code AND District = :district")
			 .bind("name", "Twin Peaks")
			 .bind("code", "USA")
			 .bind("district", "Washington")
			 .execute();

        std::cout << "Done!\n";
    }
    catch (const mysqlx::Error &error)
    {
        std::cerr << "The following error occurred: " << error << "\n";
    }
}
