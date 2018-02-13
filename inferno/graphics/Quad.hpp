//
//  Quad.hpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 7/17/17.
//  Copyright © 2017 Anish Bhobe. All rights reserved.
//

#ifndef Quad_hpp
#define Quad_hpp

#include <Eigen/Core>
#include <SDL2/SDL.h>
typedef Eigen::Vector2f Vector2;

namespace inferno {
    namespace graphics {

        /// @class Quad
        /// Holds information about a rectangle.
        class Quad {
        public:

            /// Default constructor, all zeros.
            /// Constructs a Quad with at origin with 0 area.
            Quad(): rect{0,0,0,0} {}

            /// Full Constructor.
            /// Constructs a Quad completely.
            /// @param x The x coordinate of the Quad.
            /// @param y The y coordinate of the Quad.
            /// @param w The w width of the Quad.
            /// @param h The h height of the Quad.
            Quad(int x, int y, int w, int h):
            rect{x,y,w,h} {}

            /// Special Span Constructor.
            /// Takes in the span of the Quad to construct a
            /// Quad at origin with given span.
            /// @param dimensions The dimension (diagonal) of the Quad
            Quad(Vector2 dimensions): rect{0,0,(int)dimensions.x(),(int)dimensions.y()} {}

            /// Component Constructor.
            /// Takes in position and dimensions to construct a Quad
            /// at the given position
            Quad(Vector2 position, Vector2 dimensions): rect{(int)position.x(),(int)position.y(),(int)dimensions.x(),(int)dimensions.y()} {}

            // Copy Constructor and Move Constructor
            Quad(const Quad& rect) = default;
            Quad(Quad&& rect) = default;
            Quad& operator=(const Quad& rect) = default;
            Quad& operator=(Quad&& rect) = default;

            // SDL Compatibility
            SDL_Rect* GetRect() {
                return &rect;
            }

            // Returns the position of top left corner of the Quad
            Vector2 GetPosition(void) {
                return {rect.x,rect.y};
            }

            // Returns a Vector2 containing the diagonal
            Vector2 GetDiagonal(void) {
                return {rect.w,rect.h};
            }

            // Getters with each data piece.
            int& x(void) {
                return rect.x;
            }

            int& y(void) {
                return rect.y;
            }

            int& w(void) {
                return rect.w;
            }

            int& h(void) {
                return rect.h;
            }

        private:
            SDL_Rect rect;
        };
    }
}

#endif /* Quad_hpp */
