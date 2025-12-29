#pragma once

namespace gbl
{
	namespace PATHFINDING
	{
		constexpr unsigned short CHECKS_PER_FRAME = 8;
	}

	namespace MAP
	{
		constexpr unsigned char CELL_SIZE = 8;
		constexpr unsigned char ORIGIN_X = 8;
		constexpr unsigned char ORIGIN_Y = 8;

		constexpr unsigned short COLUMNS = 78;
		constexpr unsigned short ROWS = 43;

		enum Cell
		{
			Empty,
			Invalid,
			Path,
			Visited,
			Wall
		};
	}

	namespace SCREEN
	{
		constexpr unsigned char RESIZE = 1;

		constexpr unsigned short HEIGHT = 720;
		constexpr unsigned short WIDTH = 1280;

		constexpr std::chrono::microseconds FRAME_DURATION(16667);
	}

    template <typename value_type>
	char sign(const value_type i_value)
	{
		return (0 < i_value) - (0 > i_value);
	}

	template <typename value_type = MAP::Cell>
	using Map = std::array<std::array<value_type, MAP::ROWS>, MAP::COLUMNS>;

	template <typename value_type = unsigned short>
	using Position = std::pair<value_type, value_type>;
}