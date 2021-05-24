#include "paginator.h"
#include "document.h"
#include "search_server.h"
#include "read_input_functions.h"
#include "request_queue.h"
#include "string_processing.h"
#include "remove_duplicates.h"
#include "test_example_functions.h"

int main() {

    setlocale(LC_ALL, "Russian");
    /*TestSearchServer();
    std::cout << "Search server testing finished"s << std::endl; */

    SearchServer search_server("and with"s);
  
    AddDocument(search_server, 1, "funny pet and nasty rat"s, DocumentStatus::ACTUAL, { 7, 2, 7 });
    AddDocument(search_server, 2, "funny pet with curly hair"s, DocumentStatus::ACTUAL, { 1, 2 });    
    AddDocument(search_server, 3, "funny pet with curly hair rat"s, DocumentStatus::ACTUAL, { 1, 2 });
    AddDocument(search_server, 4, "funny pet and curly hair"s, DocumentStatus::ACTUAL, { 1, 2 });   
    AddDocument(search_server, 5, "funny funny pet and nasty nasty rat"s, DocumentStatus::ACTUAL, { 1, 2 });   
    AddDocument(search_server, 6, "funny pet and not very nasty rat"s, DocumentStatus::ACTUAL, { 1, 2 });   
    AddDocument(search_server, 7, "very nasty rat and not very funny pet"s, DocumentStatus::ACTUAL, { 1, 2 });   
    AddDocument(search_server, 8, "pet with rat and rat and rat"s, DocumentStatus::ACTUAL, { 1, 2 });   
    AddDocument(search_server, 9, "nasty rat with curly hair"s, DocumentStatus::ACTUAL, { 1, 2 });
    

    std::cout << "Before duplicates removed: "s << search_server.GetDocumentCount() << std::endl;
    RemoveDuplicates(search_server);
    
    std::cout << "After duplicates removed: "s << search_server.GetDocumentCount() << std::endl;

    return 0;
}



