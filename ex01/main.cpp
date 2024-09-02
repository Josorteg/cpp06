#include "Serializer.hpp"

int	main()
{
	Data	    *test_after;
	Data		*ptr_test;
	uintptr_t	result;
   

   
    ptr_test = new Data;
    //ptr_test->test0 = 1;
    //ptr_test->test1 = "vaya";
    //ptr_test->test2 = 'c';
	
    result = Serializer::serialize(ptr_test);
    ptr_test->test0 = 1;
    ptr_test->test1 = "vaya";
    ptr_test->test2 = 'c';
	test_after = Serializer::deserialize(result);
   	std::cout << "uintptr_t test : " << result << '\n'
	<< "uintptr_t test hex value : " << std::hex << "0x" << result << '\n'
	<< "deserialize test ; ptr_test : " << ptr_test << '\n'
	<< "serialize test ; result hex value : " << test_after << '\n'
	<< "serialize test ; result : " << std::dec << test_after << '\n';
    std::cout<<"After process data->test0 : "<<test_after->test0<<std::endl;
    std::cout<<"After process data->test1 : "<<test_after->test1<<std::endl;
    std::cout<<"After process data->test2 : "<<test_after->test2<<std::endl;

    std::cout <<"changing test_after"<<std::endl;
    test_after->test0 = 25;
    std::cout<<"ptr_test->test0 : "<<ptr_test->test0<<std::endl;
    
    delete ptr_test;
	return 0;
}