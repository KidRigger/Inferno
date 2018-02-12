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
            Rectangle(Vector2 dimensions): rect(0,0,dimensions.x(),dimensions.y()) {}

            // Component Constructor.
            // Takes in position and dimensions to construct a rectangle
            // at the given position
            Rectangle(Vector2 position, Vector2 dimensions): rect(position.x(),position.y(),dimensions.x(),dimensions.y()) {}

            // Copy Constructor and Move Constructor
            Rectangle(const Rectangle& rect) = default;
            Rectangle(Rectangle&& rect) = default;
            Rectangle& operator=(const Rectangle& rect) = default;
            Rectangle& operator=(Rectangle&& rect) = default;

            // SDL Compatibility
            SDL_Rect* GetRect() {
                return &rect;
            }

            // Returns the position of top left corner of the rectangle
            Vector2& GetPosition(void) {
                return position;
            }

            // Returns a Vector2 containing the diagonal
            Vector2& GetDiagonal(void) {
                return {rect.};
            }

            // Getters with each data piece.
            int x(void) {
                return rect.x;
            }

            int y(void) {
                return rect.y;
            }

            int w(void) {
                return rect.w;
            }

            int h(void) {
                return rect.h;
            }

        private:
            SDL_Rect rect;
        };

        typedef Rectangle Quad;
    }
}

#endif /* Rectangle_hpp */
