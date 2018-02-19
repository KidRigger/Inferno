//
//  Quad.hpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 7/17/17.
//  Copyright © 2017 Anish Bhobe. All rights reserved.
//

#ifndef Quad_hpp
#define Quad_hpp

#include <SDL2/SDL.h>
#include <Eigen/Core>
typedef Eigen::Vector2f Vector2;

namespace inferno {
namespace graphics {

/// @class Quad
/// @author Anish Bhobe
/// @date 07.17.2017
/// @brief Holds information about a rectangle.
class Quad {
public:
	/// Default constructor, all zeros.
	/// Constructs a Quad with at origin with 0 area.
	Quad() :
			rect{ 0, 0, 0, 0 } {}

	/// Full Constructor.
	/// Constructs a Quad completely.
	/// @param x The x coordinate of the Quad.
	/// @param y The y coordinate of the Quad.
	/// @param w The w width of the Quad.
	/// @param h The h height of the Quad.
	Quad(int x, int y, int w, int h) :
			rect{ x, y, w, h } {}

	/// Special Span Constructor.
	/// Takes in the span of the Quad to construct a
	/// Quad at origin with given span.
	/// @param dimensions The dimension (diagonal) of the Quad.
	Quad(Vector2 dimensions) :
			rect{ 0, 0, (int)dimensions.x(), (int)dimensions.y() } {}

	/// Component Constructor.
	/// Takes in position and dimensions to construct a Quad
	/// at the given position
	/// @param position The position of the top left corner of the Quad.
	/// @param dimensions The dimensions (diagonal) of the Quad.
	Quad(Vector2 position, Vector2 dimensions) :
			rect{ (int)position.x(), (int)position.y(), (int)dimensions.x(), (int)dimensions.y() } {}

	/// Copy Constructor.
	/// Default copy construction.
	/// @param rect Reference to the source Quad.
	Quad(const Quad &rect) = default;

	/// Move Constructor.
	/// Default move construction.
	/// @param rect Rvalue reference to the source Quad.
	Quad(Quad &&rect) = default;

	/// Copy assignment.
	/// Default.
	/// @param rect Reference to the source Quad.
	/// @returns Reference to self.
	Quad &operator=(const Quad &rect) = default;

	/// Move assignment.
	/// Default.
	/// @param rect Rvalue reference to the source Quad.
	/// @returns Reference to self.
	Quad &operator=(Quad &&rect) = default;

	/// Gets the SDL_Rect for SDL interfacing.
	/// @returns Pointer to SDL_Rect containing data. [DO NOT DELETE].
	SDL_Rect *get_rect() {
		return &rect;
	}

	/// Returns the position of top left corner of the Quad
	/// @returns Vector2 containing position of top left corner of the Quad.
	Vector2 get_position(void) {
		return { rect.x, rect.y };
	}

	/// Returns the dimensions
	/// @returns Vector2 containing the diagonal of the Quad.
	Vector2 get_diagonal(void) {
		return { rect.w, rect.h };
	}

	/// Get X.
	/// @returns X coordinate of top-left corner.
	int &x(void) {
		return rect.x;
	}

	/// Get Y.
	/// @returns Y coordinate of top-left corner.
	int &y(void) {
		return rect.y;
	}

	/// Get W.
	/// @returns The width of the Quad.
	int &w(void) {
		return rect.w;
	}

	/// Get H.
	/// @returns The height of the Quad.
	int &h(void) {
		return rect.h;
	}

private:
	SDL_Rect rect;
};
} // namespace graphics
} // namespace inferno

#endif /* Quad_hpp */
