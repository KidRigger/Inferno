#include "catch.hpp"

#include "../inferno/graphics/Quad.hpp"

using inferno::graphics::Quad;

TEST_CASE("Quad is constructed", "[quad_empty_ctor]") {
	Quad q;
	SECTION("X coordinate was 0") {
		REQUIRE(q.x() == 0);
	}
	SECTION("Y coordinate was 0") {
		REQUIRE(q.y() == 0);
	}
	SECTION("W coordinate was 0") {
		REQUIRE(q.w() == 0);
	}
	SECTION("H coordinate was 0") {
		REQUIRE(q.h() == 0);
	}
}

TEST_CASE("Quad is constructed with span", "[quad_span_ctor]") {
	Vector2 v(3, 4);
	Quad q(v);
	SECTION("X coordinate was 0") {
		REQUIRE(q.x() == 0);
	}
	SECTION("Y coordinate was 0") {
		REQUIRE(q.y() == 0);
	}
	SECTION("W coordinate was 3") {
		REQUIRE(q.w() == 3);
	}
	SECTION("H coordinate was 4") {
		REQUIRE(q.h() == 4);
	}
}

TEST_CASE("Quad is constructed with span with floats", "[quad_span_ctor]") {
	Vector2 v(3.2, 4.5);
	Quad q(v);
	SECTION("X coordinate was 0") {
		REQUIRE(q.x() == 0);
	}
	SECTION("Y coordinate was 0") {
		REQUIRE(q.y() == 0);
	}
	SECTION("W coordinate was 3") {
		REQUIRE(q.w() == 3);
	}
	SECTION("H coordinate was 4") {
		REQUIRE(q.h() == 4);
	}
}

TEST_CASE("Quad is constructed with AABB", "[quad_AABB_ctor]") {
	Vector2 v(3, 4);
	Vector2 p(5, 2);
	Quad q(p, v);
	SECTION("X coordinate was 5") {
		REQUIRE(q.x() == 5);
	}
	SECTION("Y coordinate was 2") {
		REQUIRE(q.y() == 2);
	}
	SECTION("W coordinate was 3") {
		REQUIRE(q.w() == 3);
	}
	SECTION("H coordinate was 4") {
		REQUIRE(q.h() == 4);
	}
}

TEST_CASE("Quad is fully constructed", "[quad_full_ctor]") {
	Quad q(5, 2, 3, 4);
	SECTION("X coordinate was 5") {
		REQUIRE(q.x() == 5);
	}
	SECTION("Y coordinate was 2") {
		REQUIRE(q.y() == 2);
	}
	SECTION("W coordinate was 3") {
		REQUIRE(q.w() == 3);
	}
	SECTION("H coordinate was 4") {
		REQUIRE(q.h() == 4);
	}
}
