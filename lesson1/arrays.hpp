#include <vector>

//! @brief Func to reverse vector elements consequence
void reverse_vector(std::vector<int>& vec);



//! @brief Func to reverse part of container
template <typename Iter>
void reverse_part(Iter start, Iter finish);

//! @brief Func to cycle shift vector
void cycle_shift_vector(std::vector<int>& vec, int k);



//! @brief Func to merge sorted vectors
//! @return vector n + m size
std::vector<int> merge_sorted_vectors_into_new(std::vector<int>& vec1, std::vector<int>& vec2);



//! @brief Func to merge sorted vectors and write them to vec1
void merge_sorted_vectors(std::vector<int>& vec1, std::vector<int>& vec2);



//! @brief Put even elems to the begining of vector
void even_first(std::vector<int>& vec);



//! @brief Put zeros to the end of vector
void zeros_to_end(std::vector<int>& vec);
