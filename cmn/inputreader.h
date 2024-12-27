#pragma once

#include <string>
#include <fstream>
#include <filesystem>

#include "inputdata_base.h"

using std::ios_base;

class InputReader {
public:
     explicit InputReader(const std::string_view   &fname,
			  const ios_base::openmode &mode);

     template <template <typename> typename _DTp, typename _Tp>
     _DTp<_Tp> readf(void);

private:
     mutable std::uintmax_t      fsize_;
     const std::filesystem::path path_;
     std::ifstream               ifsm_;
};
