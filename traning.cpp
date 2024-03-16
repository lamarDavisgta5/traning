# include <iostream>
# include <math.h>
# include <cmath>
# include <iomanip>
# include <bitset>
# include <cstdint>
# include "prototype.h"
# include "constValues.hpp"
# define n std::cout << '\n';


int main() {

  light ();
  physics_calculation_related_to_lights();
  end ();

return 0;
}

void light() {
  std::cout << "There is a light that shining from air in an object " << '\n';
  std::cout << "The objects can be one or more depending on a user decision " << '\n';
  std::cout << "The main goal of this progeram is to calculate refraction angle of each object " << '\n';
  std::cout << "When the light is passing throught " << '\n';
  n
  std::cout << "Press any key to start the progeram : " << '\n';
  std::string start_key {};
  std::getline ( std::cin >> std::ws , start_key ); 

}

const std::string& one_or_mulity_objects() {
  again:
  n
  std::cout << "Type ( one.O ) : To calculate the lights refraction angle in one object " << '\n';
  std::cout << "Type ( mulity.O ) : To calculate the lights refraction angle in mulity objects " << '\n';
  static std::string enter {};
  std::getline ( std::cin >> std::ws , enter );

  if ( enter != "one.O" && enter != "mulity.O" ) {
    n
    std::cout << "Wrong input " << '\n';
    std::cout << "Please enter again " << '\n';
    goto again;
  }

return enter;
}

std::string* object() {
  again:
  n
  std::cout << "These objects you can enter " << '\n';
  n
  std::cout << "Vacuum  Air  Ice  Water  Diamond  Gas  Glass  Aseton  Quartz " << '\n';
  n
  std::cout << "Enter your objects with capital letter : " << '\n';
  static std::string object {};
  std::getline ( std :: cin >> std::ws , object ); 

  if ( object != "Vacuum" &&  object != "Air" && object != "Ice" && object != "Water" && object != "Diamond" && object != "Gas" && object != "Glass" && object != "Aseton" && object != "Quartz" ) {
    n
    std::cout << "Wrong input " << '\n';
    std::cout << "Please enter again " << '\n';
    goto again;

  }

return &object;
}

double get_optical_refractive_index( std::string* O ) {
  if ( *O == "Vacuum" )
    return values::optical_refractive_index_vacuum;
  
  if ( *O == "Air" )
    return values::optical_refractive_index_air;

  if ( *O == "Glass" )
    return values::optical_refractive_index_glass;

  if ( *O == "Ice" )
    return values::optical_refractive_index_ice;

  if ( *O == "Gas" )
    return values::optical_refractive_index_gas;

  if ( *O == "Diamond" )
    return values::optical_refractive_index_diamond;

  if ( *O == "Water" )
    return values::optical_refractive_index_water;
  
  if ( *O == "Aseton" )
    return values::optical_refractive_index_aseton;
 
  if ( *O == "Quartz" )
    return values::optical_refractive_index_Quartz;

return 0;
}

const auto get_angle_of_radiation() {
  again:
  n
  std::cout << "Enter the angel of radiation of the first object in degree : " << '\n';
  double degree {};
  std::cin >> degree;

  if ( degree < 0 || degree > 360 ) {
    n
    std::cout << "Wrong input " << '\n';
    std::cout << "Please enter again " << '\n';
    goto again;
  }

return degree;
}

std::string* change_into_bits_or_quit() {
  again:
  n
  std::cout << "Type bitset : To change the item to bits " << '\n';
  std::cout << "Type quit : To end the progeram " << '\n';
  static std::string word {};
  std::getline ( std::cin >> std::ws , word );

  if ( word != "quit" && word != "bitset" ) {
    n
    std::cout << "Wrong input " << '\n';
    std::cout << "Please enter again " << '\n';
    goto again;
  }

return &word;
}

std::string* get_set_flip_reset() {
  again:  
  std::bitset <4> numbers [ 3 ] { 1110 , 0001 , 1000 }; 
  n
  std::cout << "Type set : To make the 0 bits into 1 " << '\n';
  std::cout << "Type reset : To make the 1 bits into 0 " << '\n';
  std::cout << "Type flip : To filp the bits ( 1 to 0 and 0 to 1 ) " << '\n'; 
  static std::string word {};
  std::getline ( std::cin >> std::ws , word );
  
  if ( word != "set" && word != "reset" && word != "flip" ) {
    n
    std::cout << "Wrong input " << '\n';
    std::cout << "Please enter again " << '\n';
    goto again;

  }

return &word;
}

double get_bit_position() {
  n
  std::cout << "Enter the bit position you want to change ( 1 to 8 ) : " << '\n';
  double bit_position {};
  std::cin >> bit_position;

  if ( bit_position - static_cast<int> ( bit_position ) != 0 || bit_position <= 0 || bit_position > 9 ) {
    n
    std::cout << "Wrong input " << '\n';
    std::cout << "Please enter again " << '\n';
    return get_bit_position();
  }

return bit_position;
}

void bit_changer_for_one_object( std::bitset<8> object_in_8_bits , std::uint64_t u_object_in_8_bits , std::string* R_S_F , std::bitset<8> bit_mask , std::uint64_t u_bit_mask ) {
  
  if ( *R_S_F == "set" ) {
    n
    std::cout << "You entered set " << '\n';
    n

    if ( ( ( u_object_in_8_bits & u_bit_mask )? " 1 " : " 0 " ) == " 1 " ) {
      std::cout << "This bit position is already 1 " << '\n';

    }

    else {
      n
      object_in_8_bits |= bit_mask;
      std::cout << "Your new bits are " << object_in_8_bits << '\n'; 
    }

  }

  else if ( *R_S_F == "reset" ) {
    n
    std::cout << "You entered reset " << '\n';
    n

    if ( ( ( u_object_in_8_bits & u_bit_mask ) ? " 1 " : " 0 " ) == " 1 " )  {
      n
      object_in_8_bits &= ~bit_mask;
      std::cout << "Your new bits are " << object_in_8_bits << '\n'; 
    }

    else {
      std::cout << "This bit position is already 0 " << '\n';

    }

  } 

  else {
    n
    std::cout << "You entered flip " << '\n';
    n
    object_in_8_bits ^= bit_mask;
    std::cout << "Your new bits are " << object_in_8_bits << '\n';   

  }

}

void bit_manipuation_for_one_object ( std::bitset<8> object_in_eight_bits , std::uint64_t u_object_in_eight_bits , std::string* S_R_F , double bit_p ) {

  switch ( static_cast <int> ( bit_p ) ) {
    case 1:
      std::cout << "You entered 1 " << '\n';
      bit_changer_for_one_object ( object_in_eight_bits , u_object_in_eight_bits ,  S_R_F , masks :: bit_zero , masks :: u_bit_zero );
      return;

    case 2:
      std::cout << "You entered 2 " << '\n';
      bit_changer_for_one_object ( object_in_eight_bits , u_object_in_eight_bits ,  S_R_F , masks :: bit_one , masks :: u_bit_one );
      return;

    case 3:
      std::cout << "You entered 3 " << '\n';
      bit_changer_for_one_object ( object_in_eight_bits , u_object_in_eight_bits ,  S_R_F , masks :: bit_two , masks :: u_bit_two );
      return;

    case 4:
      std::cout << "You entered 4 " << '\n';
      bit_changer_for_one_object ( object_in_eight_bits , u_object_in_eight_bits ,  S_R_F , masks :: bit_three , masks :: u_bit_three );  
      return;

    case 5:
      std::cout << "You entered 5 " << '\n';
      bit_changer_for_one_object ( object_in_eight_bits , u_object_in_eight_bits ,  S_R_F , masks :: bit_four , masks :: u_bit_four );
      return;

    case 6:
      std::cout << "You entered 6 " << '\n';
      bit_changer_for_one_object ( object_in_eight_bits , u_object_in_eight_bits ,  S_R_F , masks :: bit_five , masks :: u_bit_five );
      return;

    case 7:
      std::cout << "You entered 7 " << '\n';
      bit_changer_for_one_object ( object_in_eight_bits , u_object_in_eight_bits ,  S_R_F , masks :: bit_six , masks :: u_bit_six );
      return;

    case 8:
      std::cout << "You entered 8 " << '\n';
      bit_changer_for_one_object ( object_in_eight_bits , u_object_in_eight_bits ,  S_R_F , masks :: bit_seven , masks :: u_bit_seven );
      return;

  }

}

void refraction_angle_on_one_objects() {
  auto object_that_light_pass_throught { object() }; 
  auto ORI { get_optical_refractive_index ( object_that_light_pass_throught ) };
  auto lights_angel { get_angle_of_radiation() };
  auto rad_lights_angel { ( values::pi / 180.0  ) * lights_angel };
  auto refraction_angel { ( sin ( rad_lights_angel ) * values :: optical_refractive_index_vacuum) / ORI };
  auto asin_refraction_angel { ( 180 / values::pi ) *  ( asin ( ( sin ( rad_lights_angel ) * values :: optical_refractive_index_vacuum) / ORI ) ) };
  std::cout << "The lights refraction angel is : " << asin_refraction_angel << " degrees " << '\n';
  n
  std::bitset<8> asin_refraction_angel_in_8_bits { static_cast < unsigned long long > ( asin_refraction_angel ) };
  std::cout << "The lights refraction angel in 8 bit is : " << asin_refraction_angel_in_8_bits << '\n';
  std::uint64_t u_asin_refraction_angel { static_cast < unsigned long long > ( asin_refraction_angel ) }; 
  auto R_S_F { get_set_flip_reset () };
  auto bit_position { get_bit_position() };
  bit_manipuation_for_one_object ( asin_refraction_angel_in_8_bits , u_asin_refraction_angel , R_S_F , bit_position );


} 

const double get_number_of_the_objects() {
  n
  std::cout << "Enter the number of the objects that lights pass throught : " << '\n';
  double number_of_items {};
  std::cin >> number_of_items;
  
  if ( number_of_items - static_cast<int> ( number_of_items ) != 0 || number_of_items <= 0 || number_of_items == 1 ) {
    n
    std::cout << "Wrong input " << '\n';
    std::cout << "Please enter again " << '\n';
    return get_number_of_the_objects();

  }

return number_of_items;
}


void bit_changers_of_arrays_of_bits( std::bitset<8> array_of_eight_bits [] , std::uint64_t u_array_of_eight_bits [] , std::string* S_R_F , std::uint64_t u_bitmask_number , std::bitset <8> bitmask_number , int size ) {

  if ( *S_R_F == "set" ) {
    std::cout << "You typed set " << '\n';
    std::cout << "Your new bits are : " << '\n';
    n
    int number_of_the_objects { 0 };
    bool error [ 1 ] { false };

    for ( int counter { 0 }; counter < size; ++ counter ) {
      ++ number_of_the_objects;
      array_of_eight_bits [ counter ] |= bitmask_number;
      std::cout << "Object " << number_of_the_objects << " : " << ( ( u_array_of_eight_bits [ counter ] & u_bitmask_number )? error [ 0 ] : array_of_eight_bits [ counter ] ) << '\n';

    }
    n
  }

  else if ( *S_R_F == "reset" ) {
    std::cout << "You typed reset " << '\n';
    std::cout << "Your new bits are : " << '\n';
    n
    bool error [ 1 ] { false }; 
    auto number_of_the_object { 0 };
    

    std::cout << "00000000 = This bit position is already 0 " << '\n'; 
    n
    for ( int counter { 0 }; counter < size; ++ counter ) {
      ++ number_of_the_object;
      array_of_eight_bits [ counter ] &= ~bitmask_number;
      std::cout << "Object " << number_of_the_object << " : " << ( ( u_array_of_eight_bits [ counter ] & u_bitmask_number )? array_of_eight_bits [ counter ] : error [ 0 ] ) << '\n';
      
    }
    n
  }

  else {
    std::cout << "You typed flip " << '\n';
    std::cout << "Your new bits are : " << '\n';
    n
    auto number_of_the_object { 0 };

    for ( int counter { 0 }; counter < size; ++ counter ) {
      ++ number_of_the_object;
      array_of_eight_bits [ counter ] ^= bitmask_number;
      std::cout << "Object " << number_of_the_object << " : " << array_of_eight_bits [ counter ] << '\n';

    }
    n

  }

}


void bit_manipuation( double bit_p , std::string*R_S_F , int size , std::bitset<8> array_of_bits [] , std::uint64_t u_array_of_bits [] ) {
  
  std::bitset<8> array_of_bits2 [ size ] {};

  for ( int counter { 0 }; counter < size; ++ counter ) {
    array_of_bits2 [ counter ] = array_of_bits [ counter ] ;
  }


  switch ( static_cast<int> ( bit_p ) ) {
    case 1:
      std::cout << "You entered 1 " << '\n';
      n
      bit_changers_of_arrays_of_bits ( array_of_bits2 , u_array_of_bits , R_S_F, masks::u_bit_zero , masks::bit_zero , size ); 
      return;

    case 2:
      std::cout << "You entered 2 " << '\n';
      n
      bit_changers_of_arrays_of_bits ( array_of_bits2 , u_array_of_bits ,R_S_F, masks::u_bit_one , masks::bit_one , size ); 
      return;

    case 3:
      std::cout << "You entered 3 " << '\n';
      n
      bit_changers_of_arrays_of_bits ( array_of_bits2 , u_array_of_bits ,R_S_F, masks::u_bit_two , masks::bit_two , size ); 
      return;

    case 4:
      bit_changers_of_arrays_of_bits ( array_of_bits2 , u_array_of_bits ,R_S_F, masks::u_bit_three , masks::bit_three , size ); 
      return;

    case 5:
      std::cout << "You entered 5 " << '\n';
      n
      bit_changers_of_arrays_of_bits ( array_of_bits2 , u_array_of_bits ,R_S_F, masks::u_bit_four , masks::bit_four , size ); 
      return;

    case 6:
      std::cout << "You entered 6 " << '\n';
      n
      bit_changers_of_arrays_of_bits ( array_of_bits2 , u_array_of_bits ,R_S_F, masks::u_bit_five , masks::bit_five , size ); 
      return;

    case 7:
      std::cout << "You entered 7 " << '\n';
      n
      bit_changers_of_arrays_of_bits ( array_of_bits2 , u_array_of_bits ,R_S_F, masks::u_bit_six , masks::bit_six , size ); 
      return;

    case 8:
      n
      bit_changers_of_arrays_of_bits ( array_of_bits2 , u_array_of_bits ,R_S_F, masks::u_bit_seven , masks::bit_seven , size ); 
      return;
  }
  
}

void refraction_angle_on_mulity_objects_in_bits( double array_of_bits [] , int size ) {
  
  auto number_of_the_answers { 0 };

  double numbers [ size ] {};

  for ( int counter { 0 }; counter < size; ++ counter ) {
    numbers [ counter ] = { array_of_bits [ counter ] };

  }

  std::bitset<8> answers_in_bits [ size ] {};

  for ( int counter { 0 }; counter < size; ++ counter ) {
    answers_in_bits [ counter ] = { static_cast < unsigned long long > ( array_of_bits [ counter ] ) };

  }

  std::uint64_t answers_in_u_bits [ size ] {};

  for ( int counter { 0 }; counter < size; ++ counter ) {
    answers_in_u_bits [ counter ] = array_of_bits [ counter ]; 

  }


  for ( int counter { 0 }; counter < size; ++ counter ) {
    ++ number_of_the_answers;
    std::cout << "The refraction angle of object " << number_of_the_answers<< " in 8 bit is : " << std::bitset <8> { static_cast < unsigned long long > ( array_of_bits [ counter ] ) } << '\n'; 
  }

  auto quit_or_continue { change_into_bits_or_quit () };

  if ( *quit_or_continue == "bitset" ) {
    n
    std::cout << "You typed bitset " << '\n';
    auto RSF { get_set_flip_reset() };
    auto bit_position { get_bit_position() };
    bit_manipuation ( bit_position , RSF , size , answers_in_bits , answers_in_u_bits ); 

  }

  else {
    n
    std::cout << "You typed quit " << '\n';
  }

  


}

void refraction_angle_on_mulity_objects ( double array_of_refractive_index [] , int size ) {
  auto radition_angel_of_first_object { get_angle_of_radiation() };
  auto deg_radition_angel { ( values::pi / 180.0  ) * radition_angel_of_first_object };
  auto sin_radition_angel { sin( deg_radition_angel ) }; 
  auto refraction_angle { ( values :: optical_refractive_index_vacuum * sin_radition_angel ) / array_of_refractive_index [ 0 ] };
  auto deg_refraction_angle { asin ( refraction_angle ) };
  auto final_answer_of_refraction_angle { ( 180.0 / values :: pi ) * deg_refraction_angle };
  auto number_of_the_objects { 0 };  
  n

  double array_of_final_answers [ size ] {};

  for ( int counter { 0 }; counter < size; ++ counter ) {
    ++ number_of_the_objects;
    auto deg_radition_angel { ( values::pi / 180.0  ) * radition_angel_of_first_object };
    auto sin_radition_angel { sin( deg_radition_angel ) }; 
    auto refraction_angle { ( values :: optical_refractive_index_vacuum * sin_radition_angel ) / array_of_refractive_index [ counter ] };
    auto deg_refraction_angle { asin ( refraction_angle ) };
    auto final_answer_of_refraction_angle { ( 180.0 / values :: pi ) * deg_refraction_angle };
    std::cout << "The refraction angle of object " << number_of_the_objects << " is : " << final_answer_of_refraction_angle << '\n'; 
    array_of_final_answers [ counter ] = { final_answer_of_refraction_angle };

  }
  
  refraction_angle_on_mulity_objects_in_bits ( array_of_final_answers , size );

} 


void display ( std::string objects [] , int size ) {

  double vlaue_of_objects [ size ] {};  

  for ( int counter { 0 }; counter < size; ++ counter ) {

    // Vacuum  Air  Ice  Water  Diamond  Gas  Glass  Aseton  Quartz
    if ( objects [ counter ] == "vacuum" )
      vlaue_of_objects [ counter ] = { values::optical_refractive_index_vacuum };

    if ( objects [ counter ] == "air" )
      vlaue_of_objects [ counter ] = { values::optical_refractive_index_air };

    if ( objects [ counter ] == "ice" )
      vlaue_of_objects [ counter ] = { values::optical_refractive_index_ice };

    if ( objects [ counter ] == "water" )
      vlaue_of_objects [ counter ] = { values::optical_refractive_index_water };

    if ( objects [ counter ] == "diamond" )
      vlaue_of_objects [ counter ] = { values::optical_refractive_index_diamond };

    if ( objects [ counter ] == "gas" )
      vlaue_of_objects [ counter ] = { values::optical_refractive_index_gas };

    if ( objects [ counter ] == "glass" )
      vlaue_of_objects [ counter ] = { values::optical_refractive_index_glass };

    if ( objects [ counter ] == "aseton" )
      vlaue_of_objects [ counter ] = { values::optical_refractive_index_aseton };
    
    if ( objects [ counter ] == "quartz" )
      vlaue_of_objects [ counter ] = { values::optical_refractive_index_Quartz };

  }

  refraction_angle_on_mulity_objects ( vlaue_of_objects , size );


}


void get_the_mulity_objects () {
  int objects_number { static_cast < int > ( get_number_of_the_objects() ) }; 
  n
  std::cout << "These objects you can enter " << '\n';
  n
  std::cout << "vacuum  air  ice  water  diamond  gas  glass  aseton  quartz " << '\n';
  n
  auto objects_counter { 0 };
  std::string arrray_of_objects [ objects_number ] {}; 

  for ( int counter { 0 }; counter < objects_number; ++ counter ) {
    n
    ++ objects_counter;
    std::cout << "Enter object " << objects_counter << " with small letters " << " : " << '\n';
    //std::cin >> arrray_of_objects [ counter ];
    std::getline ( std::cin >> std::ws , arrray_of_objects [ counter ] );

    if ( *arrray_of_objects != "vacuum" &&  *arrray_of_objects != "air" && *arrray_of_objects != "ice" && *arrray_of_objects != "water" && *arrray_of_objects != "diamond" && *arrray_of_objects != "gas" && *arrray_of_objects != "glass" && *arrray_of_objects != "aseton" && *arrray_of_objects != "quartz" ) {
      n
      std::cout << "Wrong input " << '\n';
      std::cout << "You should enter all your objects again  " << '\n';
      --counter;
      --objects_counter;
      return get_the_mulity_objects();
    }


  }
  
  const int size { static_cast <int> ( sizeof ( arrray_of_objects ) / sizeof ( arrray_of_objects [ 0 ] ) ) };
  display ( arrray_of_objects , size ); 
  



}

void physics_calculation_related_to_lights() {
  const auto& one_or_more_objects { one_or_mulity_objects() };

  if ( one_or_more_objects == "one.O" ) {
    n
    std::cout << "The light will pass on one object " << '\n';
    refraction_angle_on_one_objects (); 
  }

  else {
    n
    std::cout << "The light will pass on mulity objects " << '\n';
    get_the_mulity_objects(); 

  }



}


void end() {
  n
  std::cout << "Press any key to quit : " << '\n';
  std::string enter_to_end {};
  std::cin >> enter_to_end;

}