#include "catch.hpp"

#include "../inferno/graphics/TextureManager.hpp"
#include "../inferno/graphics/Display.hpp"
using inferno::graphics::TextureManager;
using inferno::graphics::Display;

TEST_CASE ( "Single textures can be loaded", "[load_single]" ) {
    Display disp(0,0);
    TextureManager tm(disp.GetRenderer());
    REQUIRE ( tm.size() == 0 );
    tm.Load("../character_hurt.png","charhurt");
    REQUIRE ( tm.size() == 1 );
    SECTION ( "A second image can be loaded" ) {
        tm.Load("../character_hurt.png","char_hurt");
        REQUIRE ( tm.size() == 2 );
    }
}

TEST_CASE ( "Single textures can be unloaded", "[unload_single]" ) {
    Display disp(0,0);
    TextureManager tm(disp.GetRenderer());
    tm.Load("../character_hurt.png","charhurt");
    SECTION ( "The image can be unloaded" ) {
        tm.Unload("charhurt");
        REQUIRE ( tm.size() == 0 );
    }
}

TEST_CASE ( "Can retrieve loaded texture", "[get_texture]" ) {
    Display disp(0,0);
    TextureManager tm(disp.GetRenderer());
    auto x = tm.Load("../character_hurt.png","charhurt1");
    auto y = tm.Load("../character_hurt.png","charhurt2");
    REQUIRE ( tm.size() == 2 );
    SECTION ( "operator[] overload returns correctly" ) {
        REQUIRE ( x == tm["charhurt1"] );
        REQUIRE ( y == tm["charhurt2"] );
    }
    SECTION ( "get returns correctly" ) {
        REQUIRE ( x == tm.Get("charhurt1") );
        REQUIRE ( y == tm.Get("charhurt2") );
    }
}


TEST_CASE ( "Retrieving nonexistant textures", "[nonexist_texture]" ) {
    Display disp(0,0);
    TextureManager tm(disp.GetRenderer());
    auto x = tm.Load("../character_hurt.png","charhurt1");
    auto y = tm.Load("../character_hurt.png","charhurt2");
    SECTION ( "Texture doesn't exist" ) {
        REQUIRE_THROWS_AS ( tm.Get("charhurt"), std::runtime_error );
        REQUIRE_THROWS_WITH ( tm.Get("charhurt"), Catch::Contains("No such texture") );
    }
    SECTION ( "Texture doesn't exist" ) {
        REQUIRE_THROWS_AS ( tm["charhurt"], std::runtime_error );
        REQUIRE_THROWS_WITH ( tm["charhurt"], Catch::Contains("No such texture") );
    }
}

TEST_CASE ( "Retrieving unloaded textures" , "[get_unloaded_texture]" ) {
    Display disp(0,0);
    TextureManager tm(disp.GetRenderer());
    auto x = tm.Load("../character_hurt.png","charhurt1");
    auto y = tm.Load("../character_hurt.png","charhurt2");
    tm.Unload("charhurt1");
    SECTION ( "deleted recall throws, undeleted returns." ) {
        CHECK_THROWS_AS ( tm.Get("charhurt1"), std::runtime_error );
        REQUIRE ( tm.Get("charhurt2") == y );
    }
}

TEST_CASE ( "Unload all" , "[unload_all]" ) {
    Display disp(0,0);
    TextureManager tm(disp.GetRenderer());
    auto x = tm.Load("../character_hurt.png","charhurt1");
    auto y = tm.Load("../character_hurt.png","charhurt2");
    REQUIRE ( tm.size() == 2 );
    tm.UnloadAll();
    REQUIRE ( tm.size() == 0 );
}

TEST_CASE ( "Adding multiple of same" , "[repeat_add]" ) {
    Display disp(0,0);
    TextureManager tm(disp.GetRenderer());
    auto x = tm.Load("../character_hurt.png","charhurt1");
    auto y = tm.Load("../character_hurt.png","charhurt1");
    REQUIRE ( tm.size() == 1 );
    SECTION ( "Post loaded files" ){
        CHECK ( x == y );
        REQUIRE ( tm["charhurt1"] == x );
    }
}

TEST_CASE ( "Adding another of same after removing" , "[unload_add]" ) {
    Display disp(0,0);
    TextureManager tm(disp.GetRenderer());
    auto x = tm.Load("../character_hurt.png","charhurt1");
    auto y = tm.Load("../character_hurt.png","charhurt1");
    REQUIRE ( tm.size() == 1 );
    tm.Unload("charhurt1");
    auto z = tm.Load("../character_hurt.png","charhurt1");
    SECTION ( "Post loaded files" ){
        CHECK ( x != z );
        REQUIRE ( tm["charhurt1"] != x );
    }
}

#include <vector>

TEST_CASE ( "Check if TextureManager::LoadAll works" , "[unload_add]" ) {
    Display disp(0,0);
    TextureManager tm(disp.GetRenderer());
    std::vector<std::string> files(10,"../character_hurt.png");
    std::vector<std::string> names{"c1","c2","c3","c4","c5","c6","c7","c8","c9","ca"};
    SECTION ( "All files loaded" ){
        REQUIRE_NOTHROW ( tm.LoadAll(files,names) );
        REQUIRE ( tm.size() == 10);
        for (std::string str: names) {
            CHECK_NOTHROW( tm[str] );
        }
    }
    SECTION ( "Throws on unequal" ){
        files.push_back(files.back());
        CHECK_THROWS_AS( tm.LoadAll(files,names), std::runtime_error );
        REQUIRE ( tm.size() == 0 );
    }
    SECTION ( "Multiple get included as 1" ){
        std::vector<std::string> namesrep(10,"c1");
        CHECK_NOTHROW ( tm.LoadAll(files,namesrep) );
        REQUIRE ( tm.size() == 1 );
    }
}
