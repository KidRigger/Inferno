//
//  Sprite.hpp
//  InfernoEngine2
//
//  Created by Anish Bhobe on 7/19/17.
//  Copyright © 2017 Anish Bhobe. All rights reserved.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include "Texture.hpp"

namespace inferno {
namespace graphics {
/// @class Sprite
/// @brief Holds a texture and the corresponding required region.
/// @details A class to easily access smaller regions of a texture atlas
/// or for frames in a particular animation sheet. \n
/// Use this for drawing.
/// @author Anish Bhobe
/// @date 07.19.2017
class Sprite {

public:
	/// Simple Constructor. Initializes the texture and region according to the parameters.
	/// @param texture_handle TextureHandle referencing to the atlas the sprite is a part of.
	/// @param region Quad containing the details of the region to be used.
	Sprite(TextureHandle texture_handle, Quad region) :
			txr(texture_handle),
			region(region) {}

	/// Constructor without region argument.
	/// The constructor automatically selects the entire image as a region
	/// for the construction.
	/// @param texture_handle TextureHandle referencing to the atlas the sprite is a part of.
	Sprite(TextureHandle texture_handle) :
			txr(texture_handle),
			region(texture_handle->get_quad()) {}

	/// Default Constructor
	Sprite() = default;

	/// Gets the atlas
	/// @returns TextureHandle to the texture atlas used by the sprite.
	TextureHandle get_texture() { return txr; }

	/// Gets the region
	/// @returns Quad containing the source region mapped by the sprite.
	Quad get_region() { return region; }

private:
	TextureHandle txr;
	Quad region;
};
} // namespace graphics
} // namespace inferno

#endif // Sprite_hpp //
