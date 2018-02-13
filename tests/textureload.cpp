#include "catch.hpp"

#include "../inferno/graphics/Texture.hpp"
#include "../inferno/graphics/Display.hpp"

TEST_CASE ( "Textures are loaded" , "[texture_load]" ) {
    std::string id = "char_hurt";
    inferno::graphics::Display disp(640,480);
    inferno::graphics::Texture tex( disp.GetRenderer() , "../character_hurt.png" , id );
    SECTION ( "Hashes are correct " ) {
        REQUIRE( tex.GetHash() == std::hash<std::string>{}(id) );
    }
    SECTION ( "Texture sizes are correct " ) {
        REQUIRE( tex.GetQuad().x() == 0 );
        REQUIRE( tex.GetQuad().y() == 0 );
        REQUIRE( tex.GetQuad().w() == 40 );
        REQUIRE( tex.GetQuad().h() == 40 );
    }
}
