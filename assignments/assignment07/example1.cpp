/* Example 1 - Connecting to the database */
#include <iostream>

#include <mysqlx/xdevapi.h>

int main()
{
	std::cout << "Connecting to the database...\n";

	try
	{
		mysqlx::Session session("localhost", 33060, "user", "password");
		mysqlx::Schema schema = session.getSchema("cis64a");
	}
	catch (const mysqlx::Error& error)
	{
		std::cerr << "The following error occurred: " << error << "\n";
	}
}
