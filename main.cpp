#include <iostream>
#include <cstring>
using namespace std;

char nible_to_hex(uint8_t i) {
    char symbols[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C',
            'D', 'E', 'F'};
     return symbols[i];
}

void print_byte (uint8_t byte){
    uint8_t low=byte & 0b00001111;
    uint8_t high=(byte & 0b11110000)>>4;
    cout<<nible_to_hex(high)<<nible_to_hex(low);
}

void  print_in_hex (const void* data, size_t size){
    const char* p= reinterpret_cast<const char*>(data);
    for (size_t i=0; i<size; i++){
        print_byte(p[i]);
        cout<<" ";
    }}

struct student{
    char name[17];
    int year;
    float srbal;
    int sex:1;
    int courses;
    student* str;
};

int
main() {
student s[4];
    int i, N;
    strcpy(s[0].name, "Ivan I");
    s[0].year=1989;
    s[0].srbal=5;
    s[0].sex=1;
    s[0].courses=5;
    s[0].str=nullptr;
    strcpy(s[1].name, "Ivan II");
    s[1].year=2014;
    s[1].srbal=2;
    s[1].sex=1;
    s[1].courses=2;
    s[1].str=&s[0];
    strcpy(s[2].name, "Ivan III");
    s[2].year=2000;
    s[2].srbal=3;
    s[2].sex=1;
    s[2].courses=5;
    s[2].str=&s[0];
    strcpy(s[3].name, "Ivan IV");
    s[3].year=3015;
    s[3].srbal=0;
    s[3].sex=1;
    s[3].courses=0;
    s[3].str=&s[0];
    cout<<"address massiva="<<&s<<"\n";
    cout<<"size of array = "<<sizeof(s)<<"\n";
    for (i=1; i<3; i++) {
        cout<<"address elementa="<<&s[i]<<"\n";
        cout<<"size elementa="<<sizeof(s[i])<<"\n";
        print_in_hex(&s[i], sizeof s[i]);
        cout<<"\n";
    }

    return 0;
}