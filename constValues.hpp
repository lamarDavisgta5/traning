# ifndef CONST_VALUES_HPP
# define CONST_VALUE_HPP
# include <bitset>


namespace values {
  inline constexpr auto pi { 3.14159265358979323846 };
  inline constexpr auto gravity { 9.8 };
  inline constexpr auto optical_refractive_index_vacuum { 1 };
  inline constexpr auto optical_refractive_index_air { 1.00029 };
  inline constexpr auto optical_refractive_index_ice { 1.31 }; 
  inline constexpr auto optical_refractive_index_water { 1.33 };
  inline constexpr auto optical_refractive_index_aseton { 1.36 };
  inline constexpr auto optical_refractive_index_gas { 1.50 };
  inline constexpr auto optical_refractive_index_glass { 1.52 };  
  inline constexpr auto optical_refractive_index_diamond { 2.42 };  
  inline constexpr auto optical_refractive_index_Quartz { 1.54 };

}

namespace masks {
  inline std::bitset <8> bit_zero { 0b0000'0001 }; 
  inline std::bitset <8> bit_one { 0b0000'0010 }; 
  inline std::bitset <8> bit_two { 0b0000'0100 }; 
  inline std::bitset <8> bit_three { 0b0000'1000 }; 
  inline std::bitset <8> bit_four { 0b0001'0000 }; 
  inline std::bitset <8> bit_five { 0b0010'0000 }; 
  inline std::bitset <8> bit_six { 0b0100'0000 }; 
  inline std::bitset <8> bit_seven { 0b1000'0000 }; 
  inline std::bitset <8> all_eight_bits { 0b1111'1111 }; 
  
  inline std::uint64_t u_bit_zero { 0b0000'0001 }; 
  inline std::uint64_t u_bit_one { 0b0000'0010 }; 
  inline std::uint64_t u_bit_two { 0b0000'0100 }; 
  inline std::uint64_t u_bit_three { 0b0000'1000 }; 
  inline std::uint64_t u_bit_four { 0b0001'0000 }; 
  inline std::uint64_t u_bit_five { 0b0010'0000 }; 
  inline std::uint64_t u_bit_six { 0b0100'0000 }; 
  inline std::uint64_t u_bit_seven { 0b1000'0000 }; 
  inline std::uint64_t u_all_eight_bits { 0b1111'1111 }; 
  

}


# endif