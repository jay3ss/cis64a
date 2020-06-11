/* Example 4 - Updating an entry */
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
        table.update()
			 .set("population", 123456)
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
