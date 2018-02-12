#include <cereal/archives/xml.hpp>
#include <fstream>

int main()
{
	std::ofstream file( "out.xml" );
	cereal::XMLOutputArchive archive( file );	// depending on the archive type, data may be
												// output to the stream as it is serialized, or
												// only on destruction
	int t=123;


	archive( t );

return (0);
}