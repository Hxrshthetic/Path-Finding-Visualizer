#include <array>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

#include "Header/Global.hpp"
#include "Header/DrawText.hpp"

void draw_stats(const short i_x, const short i_y, const unsigned short i_path_length, const unsigned short i_total_checks, const std::chrono::microseconds& i_duration, const std::string& i_algorithm_name, sf::RenderWindow& i_window, const sf::Texture& i_font_texture)
{
	std::stringstream string_stream;
	string_stream << std::fixed << std::setprecision(2) << i_duration.count() / 1000.f;

	draw_text(1, 1, i_x, i_y, "-- " + i_algorithm_name + " --\nLength: " + std::to_string(i_path_length) + "\nChecks: " + std::to_string(i_total_checks) + "\nTime: " + string_stream.str() + "ms", i_window, i_font_texture);
}

void draw_text(const bool i_center_x, const bool i_center_y, const short i_x, const short i_y, const std::string& i_text, sf::RenderWindow& i_window, const sf::Texture& i_font_texture)
{
	short character_x;
	short character_y;

	unsigned char character_width = i_font_texture.getSize().x / 96;

	sf::Sprite character_sprite(i_font_texture);

	if (1 == i_center_x)
	{
		character_x = static_cast<short>(round(i_x - 0.5f * character_width * i_text.substr(0, i_text.find_first_of('\n')).size()));
	}
	else
	{
		character_x = i_x;
	}

	if (1 == i_center_y)
	{
		character_y = static_cast<short>(round(i_y - 0.5f * i_font_texture.getSize().y * (1 + std::count(i_text.begin(), i_text.end(), '\n'))));
	}
	else
	{
		character_y = i_y;
	}

	for (std::string::const_iterator a = i_text.begin(); a != i_text.end(); a++)
	{
		if ('\n' == *a)
		{
			if (i_center_x == 1)
			{
				character_x = static_cast<short>(round(i_x - 0.5f * character_width * i_text.substr(1 + a - i_text.begin(), i_text.find_first_of('\n', 1 + a - i_text.begin()) - (1 + a - i_text.begin())).size()));
			}
			else
			{
				character_x = i_x;
			}

			character_y += i_font_texture.getSize().y;

			continue;
		}

		character_sprite.setPosition(character_x, character_y);
		character_sprite.setTextureRect(sf::IntRect(character_width * (*a - 32), 0, character_width, i_font_texture.getSize().y));

		character_x += character_width;

		i_window.draw(character_sprite);
	}
}