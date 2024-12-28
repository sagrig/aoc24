#include <iostream>

#include "inputreader.h"
#include "inputdata1.h"

template InputData1<long> InputReader::readf<InputData1, long>();

int main(void)
{
     using std::cout;
     using std::endl;

     constexpr std::string_view   fname = "input1.txt";
     constexpr ios_base::openmode mode  = (ios_base::in | ios_base::binary);

     InputReader      reader{fname, mode};
     auto rdata = reader.readf<InputData1, long>();

     cout << "total distance: "   << rdata.calc_totd() << '\n';
     cout << "similarity score: " << rdata.calc_uniq() << std::endl;
     return 0;
}
