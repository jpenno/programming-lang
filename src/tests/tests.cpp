#define CATCH_CONFIG_MAIN

#include <vector>

#include "catch.hpp"

#include "basic.hpp"

TEST_CASE("Test Lexer")
{
	SECTION("Check PLUS + ")
	{
		Basic::Lexer lexer = Basic::Lexer("+");
		vector<Basic::Token> tokens = lexer.MakeTokens();
		REQUIRE(tokens[0].GetType() == Basic::TT::PLUS);
	}

	SECTION("Check MINUS - ")
	{
		Basic::Lexer lexer = Basic::Lexer("-");
		vector<Basic::Token> tokens = lexer.MakeTokens();
		REQUIRE(tokens[0].GetType() == Basic::TT::MINUS);
	}

	SECTION("Check MUL * ")
	{
		Basic::Lexer lexer = Basic::Lexer("*");
		vector<Basic::Token> tokens = lexer.MakeTokens();
		REQUIRE(tokens[0].GetType() == Basic::TT::MUL);
	}

	SECTION("Check DIV / ")
	{
		Basic::Lexer lexer = Basic::Lexer("/");
		vector<Basic::Token> tokens = lexer.MakeTokens();
		REQUIRE(tokens[0].GetType() == Basic::TT::DIV);
	}

	SECTION("Check LPAREN ( ")
	{
		Basic::Lexer lexer = Basic::Lexer("(");
		vector<Basic::Token> tokens = lexer.MakeTokens();
		REQUIRE(tokens[0].GetType() == Basic::TT::LPAREN);
	}

	SECTION("Check RPAREN ) ")
	{
		Basic::Lexer lexer = Basic::Lexer(")");
		vector<Basic::Token> tokens = lexer.MakeTokens();
		REQUIRE(tokens[0].GetType() == Basic::TT::RPAREN);
	}

	SECTION("Check ALL +-*/() ")
	{
		Basic::Lexer lexer = Basic::Lexer("+-*/()");
		vector<Basic::Token> tokens = lexer.MakeTokens();
		REQUIRE(tokens[0].GetType() == Basic::TT::PLUS);
		REQUIRE(tokens[1].GetType() == Basic::TT::MINUS);
		REQUIRE(tokens[2].GetType() == Basic::TT::MUL);
		REQUIRE(tokens[3].GetType() == Basic::TT::DIV);
		REQUIRE(tokens[4].GetType() == Basic::TT::LPAREN);
		REQUIRE(tokens[5].GetType() == Basic::TT::RPAREN);
	}
}
