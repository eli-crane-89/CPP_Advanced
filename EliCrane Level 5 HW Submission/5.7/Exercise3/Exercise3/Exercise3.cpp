#include <iostream>
#include <string>
#include <boost/bimap/bimap.hpp>
#include <boost/bimap/list_of.hpp>
#include <boost/bimap/multiset_of.hpp>
#include <tuple>

struct Author {};
struct Title {};

int main()
{
	//a)
	using namespace boost::bimaps;

	//Create typedef DNS
	typedef bimap
	<
	multiset_of<tagged<std::string, Author>>, //Use multiset to hold 1:N relation
	set_of<tagged<std::string, Title>>, 
	with_info<double> //price
	> BookList;

	BookList bl;

	bl.insert(BookList::value_type("King", "Scary Book1", 3.54));
	bl.insert(BookList::value_type("King", "Scary Book2", 5.87));
	bl.insert(BookList::value_type("Patterson", "Dramatic Book1", 6.47));
	bl.insert(BookList::value_type("Patterson", "Dramatic Book2", 9.28));
	bl.insert(BookList::value_type("King", "Scary Book2", 9.87)); //This is not added since books are a set

	std::string currentAuthor;

	
	//b)
	auto lFindBooks = [](const BookList& bl, const std::string author) {
		
		//Find first
		BookList::map_by<Author>::const_iterator itAuthor = bl.by<Author>().find(author);

		//Have to iterate since keys are no longer unique
		while (itAuthor != bl.left.end()) {
			if (itAuthor->first == author){
				std::cout << "Author: " << itAuthor->get<Author>() << ", Book: " << itAuthor->get<Title>() << ", Price: " << bl.right.info_at(itAuthor->get<Title>()) << std::endl;
			}
			++itAuthor;
		}
	};

	lFindBooks(bl, "King");
	lFindBooks(bl, "Patterson");

	//c)
	typedef bimap
		<
		multiset_of<tagged<std::string, Author>>,
		set_of<tagged<std::string, Title>>,
		with_info<std::tuple<std::string, double>> //price
		> BookListInfo;

	BookListInfo bli;

	bli.insert(BookListInfo::value_type("King", "Scary Book1", std::make_tuple("A very scary book",3.54)));
	bli.insert(BookListInfo::value_type("King", "Scary Book2", std::make_tuple("An even scarier book", 5.87)));
	bli.insert(BookListInfo::value_type("Patterson", "Dramatic Book1", std::make_tuple("A so-so dramatic book", 6.47)));
	bli.insert(BookListInfo::value_type("Patterson", "Dramatic Book2", std::make_tuple("A very dramatic books.", 9.28)));

	auto findKing = bli.by<Author>().find("King");

	std::cout << "The author: " << findKing->get<Author>() << " wrote the book: " << findKing->get<Title>() << " which can be desribed as: ";
	std::cout << std::get<0>(bli.right.info_at(findKing->get<Title>())) << " and has a price of: " << std::get<1>(bli.right.info_at(findKing->get<Title>()));
	std::cout << std::endl;

    return 0;
}

