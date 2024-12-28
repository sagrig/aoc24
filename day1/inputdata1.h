#pragma once

#include <set>
#include <string>
#include <utility>
#include <vector>

#include "inputdata_base.h"

using std::vector;

template <typename _Tp>
class InputData1 : public InputDataBase<_Tp> {
public:
     InputData1(void)                          = delete;
     InputData1(const InputData1 &)            = delete;
     InputData1(InputData1 &&)                 = delete;
     InputData1 &operator=(const InputData1 &) = delete;
     InputData1 &operator=(InputData1 &&)      = delete;
     ~InputData1(void)                         = default;

     explicit InputData1(const std::string &rawd);
     void printd(void) const;
     void sort(void);

     /* part one */
     _Tp calc_totd(void);

     /* part two */
     _Tp calc_uniq(void);

private:
     mutable int          pnum_; /* pair number */
     mutable vector<_Tp>  pvec_; /* pair vector */
     bool                 srtd_; /* pairs sorted */
};

template <typename _Tp>
InputData1<_Tp>::InputData1(const std::string &rawd) : InputDataBase<_Tp>(rawd), srtd_{false}
{
     pnum_   = std::count(rawd.cbegin(), rawd.cend(), '\n');
     pnum_ <<= 1;
     vector<_Tp> pairs(pnum_, 0);

     {
	  bool     row = 0;
	  std::stringstream ss(rawd);
	  auto frwi = pairs.begin();
	  auto srwi = (frwi + (pnum_ >> 1));

	  for (_Tp val; ss >> val; ) {
	       if (row)
		    *(srwi++) = val;
	       else
		    *(frwi++) = val;
	       row = !row;
	  }
     }
     pvec_ = std::move(pairs);
}

template <typename _Tp>
void InputData1<_Tp>::printd(void) const
{
     const auto half = (pnum_ >> 1);
     auto frow       = pvec_.cbegin();
     auto srow       = (frow + half);

     for (; frow < srow; ++frow)
	  std::cout << *frow << " " << *(frow + half) << "\n";
}

template <typename _Tp>
void InputData1<_Tp>::sort(void)
{
     auto frow = pvec_.begin();
     auto srow = (frow + (pnum_ >> 1));
     auto end  = pvec_.end();

     std::sort(frow, srow);
     std::sort(srow, end);

     srtd_ = true;
}

template <typename _Tp>
_Tp InputData1<_Tp>::calc_totd(void)
{
     if (!srtd_)
	  this->sort();

     const auto half = (pnum_ >> 1);
     auto       frow = pvec_.cbegin();
     auto       srow = (frow + half);
     auto       end  = pvec_.cend();

     _Tp        totd = 0;
     for (; srow < end;)
	  totd += std::abs((*(frow++) - *(srow++)));
     return totd;
}

template <typename _Tp>
_Tp InputData1<_Tp>::calc_uniq(void)
{
     using std::pair;
     using std::set;

     constexpr auto cmp = [](const pair<_Tp, _Tp> a, const pair<_Tp, _Tp> b) {
	  return (a.first <= b.first);
     };
     set<pair<_Tp, _Tp>, decltype(cmp)> umap;

     const auto half = (pnum_ >> 1);
     auto       frow = pvec_.cbegin();
     auto       srow = (frow + half);
     auto       end  = pvec_.cend();

     for (; frow < srow; ++frow)
	  (void)umap.emplace(*frow, std::count(srow, end, *frow));

     _Tp utot = 0;
     for (const auto e : umap)
	  utot += (e.first * e.second);
     return utot;
}
