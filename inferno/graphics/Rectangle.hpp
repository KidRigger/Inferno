//
//  Rectangle.hpp
//  InfernoEngine
//
//  Created by Anish Bhobe on 7/17/17.
//  Copyright © 2017 Anish Bhobe. All rights reserved.
//

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <Eigen/Core>
#include <SDL2/SDL.h>
typedef Eigen::Vector2f Vector2;

namespace inferno {
    namespace graphics {

        // Rectangle class
        // Holds information about a rectangle.
        class Rectangle {
        public:
            // Default constructor, all zero
            Rectangle(): position(0,0), diagonal(0,0) {}

            // Actual constructor
            Rectangle(float x, float y, float w, float h):
            position(x,y), diagonal(w,h) {}

            // Special Span Constructor
            // Takes in the span of the rectangle to construct a
            // rectangle at origin with given span.
            Rectangle(Vector2 dimensions): position(0,0), diagonal(dimensions) {}

            // Component Constructor.
            // Takes in position and dimensions to construct a rectangle
            // at the given position
            Rectangle(Vector2 position, Vector2 dimensions): position(position), diagonal(dimensions) {}

            // Copy Constructor and Move Constructor
            Rectangle(const Rectangle& rect) = default;
            Rectangle(Rectangle&& rect) = default;
            Rectangle& operator=(const Rectangle& rect) = default;
            Rectangle& operator=(Rectangle&& rect) = default;

            // SDL Compatibility
            SDL_Rect GetRectangle() {
                SDL_Rect rect = {(int)position.x(),(int)position.y(),(int)diagonal.x(),(int)diagonal.y()};
                return rect;
            }

            // Returns the position of top left corner of the rectangle
            Vector2& GetPosition(void) {
                return position;
            }

            // Returns a Vector2 containing the diagonal
            Vector2& GetDiagonal(void) {
                return diagonal;
            }

            // Getters with each data piece.
            float& x(void) {
                return position.x();
            }

            float& y(void) {
                return position.y();
            }

            float& w(void) {
                return diagonal.x();
            }

            float& h(void) {
                return diagonal.y();
            }

        private:
            Vector2 position;
            Vector2 diagonal;
        };

        typedef Rectangle Quad;
    }
}

#endif /* Rectangle_hpp */
