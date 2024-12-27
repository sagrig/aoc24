#include "inputreader.h"

InputReader::InputReader(const std::string_view  &fname,
			 const ios_base::openmode &mode) :
     path_(fname), ifsm_(path_, mode)
{
     if (!ifsm_.is_open())
	  throw std::runtime_error("file open");

     fsize_ = std::filesystem::file_size(path_);
}

template <template <typename> typename _DTp, typename _Tp>
_DTp<_Tp> InputReader::readf(void)
{
     std::string data(fsize_, '\0');
     ifsm_.read(&data[0], fsize_);

     return _DTp<_Tp>(std::move(data));
}
