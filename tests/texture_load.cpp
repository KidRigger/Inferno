#include "catch.hpp"

#include "../inferno/graphics/Display.hpp"
#include "../inferno/graphics/Texture.hpp"

TEST_CASE("Textures are loaded", "[texture_load]") {
	std::string id = "char_hurt";
	inferno::graphics::Display disp(0, 0);
	inferno::graphics::Texture tex(disp.get_renderer(), "../character_hurt.png", id);
	SECTION("Hashes are correct") {
		REQUIRE(tex.get_hash() == std::hash<std::string>{}(id));
	}
	SECTION("Texture position is correct") {
		REQUIRE(tex.get_quad().x() == 0);
		REQUIRE(tex.get_quad().y() == 0);
	}
	SECTION("Texture size is correct") {
		REQUIRE(tex.get_quad().w() == 40);
		REQUIRE(tex.get_quad().h() == 40);
	}
}
