#pragma once
#include "finders_interface.h"

using namespace rectpack2D;

const int max_side = 4096;
const int discard_step = -4;
const flipping_option runtime_flipping_mode = flipping_option::ENABLED;
using spaces_type = empty_spaces<true, default_empty_spaces>;
using rect_type = rectpack2D::output_rect_t<spaces_type>;

using vec_rect_type = std::vector<rect_xywhf>;

auto report_successful = [](rect_type&)
{
	return callback_result::CONTINUE_PACKING;
};
auto report_unsuccessful = [](rect_type&)
{
	return callback_result::ABORT_PACKING;
};

auto find_best_packing_spaces_type(vec_rect_type& rectangles)
{
	return rectpack2D::find_best_packing<spaces_type>(
		rectangles,
		make_finder_input(
			max_side,
			discard_step,
			report_successful,
			report_unsuccessful,
			runtime_flipping_mode)
	);
}

auto find_best_packing_dont_sort_spaces_type(vec_rect_type& rectangles)
{
	return rectpack2D::find_best_packing_dont_sort<spaces_type>(
			rectangles,
			make_finder_input(
				max_side,
				discard_step,
				report_successful,
				report_unsuccessful,
				runtime_flipping_mode
			)
		);
}