#define CATCH_CONFIG_MAIN
#include <vector>
#include "catch.hpp"
#include "Basic.hpp"
#include "Lexer.hpp"

TEST_CASE("Test Lexer")
{
	SECTION("Check PLUS + ")
	{
		Basic::Lexer lexer = Basic::Lexer("TEST", "+");
		auto [tokens, errors] = lexer.MakeTokens();
		REQUIRE(tokens[0].GetType() == Basic::TT::PLUS);
	}

	SECTION("Check MINUS - ")
	{
		Basic::Lexer lexer = Basic::Lexer("TEST", "-");
		auto [tokens, errors] = lexer.MakeTokens();
		REQUIRE(tokens[0].GetType() == Basic::TT::MINUS);
	}

	SECTION("Check MUL * ")
	{
		Basic::Lexer lexer = Basic::Lexer("TEST", "*");
		auto [tokens, errors] = lexer.MakeTokens();
		REQUIRE(tokens[0].GetType() == Basic::TT::MUL);
	}

	SECTION("Check DIV / ")
	{
		Basic::Lexer lexer = Basic::Lexer("TEST", "/");
		auto [tokens, errors] = lexer.MakeTokens();
		REQUIRE(tokens[0].GetType() == Basic::TT::DIV);
	}

	SECTION("Check LPAREN ( ")
	{
		Basic::Lexer lexer = Basic::Lexer("TEST", "(");
		auto [tokens, errors] = lexer.MakeTokens();
		REQUIRE(tokens[0].GetType() == Basic::TT::LPAREN);
	}

	SECTION("Check RPAREN ) ")
	{
		Basic::Lexer lexer = Basic::Lexer("TEST", ")");
		auto [tokens, errors] = lexer.MakeTokens();
		REQUIRE(tokens[0].GetType() == Basic::TT::RPAREN);
	}


	SECTION("Check INT 10 ")
	{
		Basic::Lexer lexer = Basic::Lexer("TEST", "10");
		auto [tokens, errors] = lexer.MakeTokens();
		REQUIRE(tokens[0].GetType() == Basic::TT::INT);
		REQUIRE(tokens[0].GetValue() == "10");
	}

	SECTION("Check FLOAT 10.10 ")
	{
		Basic::Lexer lexer = Basic::Lexer("TEST", "10.10");
		auto [tokens, errors] = lexer.MakeTokens();
		REQUIRE(tokens[0].GetType() == Basic::TT::FLOAT);
		REQUIRE(tokens[0].GetValue() == "10.10");
	}

	SECTION("Check ALL +-*/() ")
	{
		Basic::Lexer lexer = Basic::Lexer("TEST", "+10- */ 10.10( )");
		auto [tokens, errors] = lexer.MakeTokens();
		REQUIRE(tokens[0].GetType() == Basic::TT::PLUS);
		REQUIRE(tokens[1].GetType() == Basic::TT::INT);
		REQUIRE(tokens[1].GetValue() == "10");
		REQUIRE(tokens[2].GetType() == Basic::TT::MINUS);
		REQUIRE(tokens[3].GetType() == Basic::TT::MUL);
		REQUIRE(tokens[4].GetType() == Basic::TT::DIV);
		REQUIRE(tokens[5].GetType() == Basic::TT::FLOAT);
		REQUIRE(tokens[5].GetValue() == "10.10");
		REQUIRE(tokens[6].GetType() == Basic::TT::LPAREN);
		REQUIRE(tokens[7].GetType() == Basic::TT::RPAREN);
	}
}