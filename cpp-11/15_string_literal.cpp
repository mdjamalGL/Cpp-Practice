#include <iostream>
#include <cstring>

int main()
{
    char *arr1 = "jamal";
    char *arr2 = u8"jamal";
    char16_t *arr3 = u"jamal";
    wchar_t *arr4 = L"jamal";
    char32_t *arr5 = U"jamal";
    
    char *arr6 = "\\njamal\\n\\n";
    char *arr7 = R"(\njamal\n\n)";

    std::cout<<"char : "<<sizeof(arr1[0])<<std::endl;
    std::cout<<"char u8 : "<<sizeof(arr2[0])<<std::endl;
    std::cout<<"char 16 : "<<sizeof(arr3[0])<<std::endl;
    std::cout<<"char wchar : "<<sizeof(arr4[0])<<std::endl;
    std::cout<<"char 32 : "<<sizeof(arr5[0])<<std::endl;

    std::cout<<"char string : "<<arr6<<" : "<<std::strlen(arr6)<<std::endl;
    std::cout<<"raw char string : "<<arr7<<" : "<<std::strlen(arr7)<<std::endl;
    return 0;
}