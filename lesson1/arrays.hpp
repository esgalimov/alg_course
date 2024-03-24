#include <vector>

//! @brief Func to reverse vector elements consequence
void reverse_vector(std::vector<int>& vec);



//! @brief Func to reverse part of container
template <typename Iter>
void reverse_part(Iter start, Iter finish);

//! @brief Func to cycle shift vector
void cycle_shift_vector(std::vector<int>& vec, int k);
