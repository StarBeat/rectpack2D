%module rectpack2d

%{
#include "export.h"
%}

%include "std_vector.i"

%include "../src/finders_interface.h"
%include "../src/export.h"
%include "../src/rect_structs.h"

using namespace rectpack2D;

%template(rect_type) output_rect_t<spaces_type>;
%template(vec_rect_type) std::vector<rect_xywhf>;

rect_wh find_best_packing_spaces_type(vec_rect_type& rectangles);
rect_wh find_best_packing_dont_sort_spaces_type(vec_rect_type& rectangles);
