
#include "doctest.h"
#include "snowman.hpp"
#include <string>
#include <math.h>

using namespace ariel;
using namespace std;

#define LEN 8 // the size of the num
#define LEGAL_NUM 4 // the right number
#define SEED 3 // number of tests
#define BAD_NUM 10 // checking the bad numbers


string *split(string s, string delimiter)//split s by delimiter
{
    string *ans = new string[5];
    size_t pos = 0;
    int i = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos)
    {
        token = s.substr(0, pos);
        ans[i] = token;
        i++;
        s.erase(0, pos + delimiter.length());
    }
    ans[i] = s;
    return ans;
}

int build_snowman(int num, int tav)
{
    int ans = 0;
    for (size_t i = 0; i < LEN; i++)
    {
        if (i + 1 != tav)
        {
            ans = ans + pow(10, i)*(rand()%4 + 1);
        }
        else
        {
            ans = ans + pow(10, tav)*num;
        }
    }
    return ans;
}

int build_snowman(int num, char tav)
{
    int ans;
    switch (tav)
    {
    case 'h':
        ans = build_snowman(num, 8);
        break;

    case 'n':
        ans = build_snowman(num, 7);
        break;

    case 'l':
        ans = build_snowman(num, 6);
        break;

    case 'r':
        ans = build_snowman(num, 5);
        break;

    case 'x':
        ans = build_snowman(num, 4);
        break;

    case 'y':
        ans = build_snowman(num, 3);
        break;

    case 't':
        ans = build_snowman(num, 2);
        break;

    case 'b':
        ans = build_snowman(num, 1);
        break;
    default:
        break;
    }
    return ans;
}


TEST_CASE("Hat") //h
{
    for (size_t i = 0; i < SEED; i++)
    {
        string* s = split(snowman(build_snowman(1, 'h')), "\n");
        bool b = (s[0].find("_===_") != std::string::npos) || (s[1].find("_===_") != std::string::npos);
        CHECK(b);
        s = split(snowman(build_snowman(2, 'h')), "\n");
        b = (s[0].find(" ___") != std::string::npos) && (s[1].find(".....") != std::string::npos);
        CHECK(b);
        s = split(snowman(build_snowman(3, 'h')), "\n");
        b = (s[0].find(" _") != std::string::npos) && (s[1].find("/_\\") != std::string::npos);
        CHECK(b);
        s = split(snowman(build_snowman(4, 'h')), "\n");
        b = (s[0].find(" ___") != std::string::npos) && (s[1].find("(_*_)") != std::string::npos);
        CHECK(b);
    }
}

TEST_CASE("Nose/Mouth") //n
{
    for (size_t i = 0; i < SEED; i++)
    {
        string* s = split(snowman(build_snowman(1, 'n')), "\n");
        CHECK(s[2].find(",") != std::string::npos);
        s = split(snowman(build_snowman(2, 'n')), "\n");
        CHECK(s[2].find(".") != std::string::npos);
        s = split(snowman(build_snowman(3, 'n')), "\n");
        CHECK(s[2].find("_") != std::string::npos);
        s = split(snowman(build_snowman(4, 'n')), "\n");
        CHECK(s[2].find("") != std::string::npos);
    }
}

TEST_CASE("Left Eye") //l
{
    for (size_t i = 0; i < SEED; i++)
    {
        string* s = split(snowman(build_snowman(1, 'l')), "\n");
        CHECK(s[2].find(".") != std::string::npos);
        s = split(snowman(build_snowman(2, 'l')), "\n");
        CHECK(s[2].find("o") != std::string::npos);
        s = split(snowman(build_snowman(3, 'l')), "\n");
        CHECK(s[2].find("O") != std::string::npos);
        s = split(snowman(build_snowman(4, 'l')), "\n");
        CHECK(s[2].find("-") != std::string::npos);
    }
}

TEST_CASE("Right Eye") //r
{
    for (size_t i = 0; i < SEED; i++)
    {
        string* s = split(snowman(build_snowman(1, 'r')), "\n");
        CHECK(s[2].find(".") != std::string::npos);
        s = split(snowman(build_snowman(2, 'r')), "\n");
        CHECK(s[2].find("o") != std::string::npos);
        s = split(snowman(build_snowman(3, 'r')), "\n");
        CHECK(s[2].find("O") != std::string::npos);
        s = split(snowman(build_snowman(4, 'r')), "\n");
        CHECK(s[2].find("-") != std::string::npos);
    }
}

TEST_CASE("Left Arm") //x
{
    for (size_t i = 0; i < SEED; i++)
    {
        string* s = split(snowman(build_snowman(1, 'x')), "\n");
        CHECK(s[3].find("<") != std::string::npos);
        s = split(snowman(build_snowman(2, 'x')), "\n");
        CHECK(s[2].find("\\") != std::string::npos);
        s = split(snowman(build_snowman(3, 'x')), "\n");
        CHECK(s[3].find("/") != std::string::npos);
        s = split(snowman(build_snowman(4, 'x')), "\n");
        CHECK(s[2].find("") != std::string::npos);
    }
}

TEST_CASE("Right Arm") //y
{
    for (size_t i = 0; i < SEED; i++)
    {
        string* s = split(snowman(build_snowman(1, 'y')), "\n");
        CHECK(s[3].find(">") != std::string::npos);
        s = split(snowman(build_snowman(2, 'y')), "\n");
        CHECK(s[2].find("/") != std::string::npos);
        s = split(snowman(build_snowman(3, 'y')), "\n");
        CHECK(s[3].find("\\") != std::string::npos);
        s = split(snowman(build_snowman(4, 'y')), "\n");
        CHECK(s[2].find("") != std::string::npos);
    }
}

TEST_CASE("Torso") //t
{
    for (size_t i = 0; i < SEED; i++)
    {
        string* s = split(snowman(build_snowman(1, 't')), "\n");
        CHECK(s[3].find(" : ") != std::string::npos);
        s = split(snowman(build_snowman(2, 't')), "\n");
        CHECK(s[3].find("] [") != std::string::npos);
        s = split(snowman(build_snowman(3, 't')), "\n");
        CHECK(s[3].find("> <") != std::string::npos);
        s = split(snowman(build_snowman(4, 't')), "\n");
        CHECK(s[3].find("   ") != std::string::npos);
    }
}

TEST_CASE("Base") //b
{
    for (size_t i = 0; i < SEED; i++)
    {
        string* s = split(snowman(build_snowman(1, 'b')), "\n");
        CHECK(s[4].find(" : ") != std::string::npos);
        s = split(snowman(build_snowman(2, 'b')), "\n");
        CHECK(s[4].find("\" \"") != std::string::npos);
        s = split(snowman(build_snowman(3, 'b')), "\n");
        CHECK(s[4].find("___") != std::string::npos);
        s = split(snowman(build_snowman(4, 'b')), "\n");
        CHECK(s[4].find("   ") != std::string::npos);
    }
}

TEST_CASE("Bad snowman")
{
    CHECK_THROWS(snowman(444));
    CHECK_THROWS(snowman(-23400000));
    //range 1 - 7 numers
    CHECK_THROWS(snowman(1));
    CHECK_THROWS(snowman(11));
    CHECK_THROWS(snowman(111));
    CHECK_THROWS(snowman(1111));
    CHECK_THROWS(snowman(11111));
    CHECK_THROWS(snowman(111111));
    CHECK_THROWS(snowman(1111111));
}

TEST_CASE("Bad Hat") //h
{
    for (size_t i = LEGAL_NUM+1; i < BAD_NUM; i++)
    {
        CHECK_THROWS(snowman(build_snowman(i, 'h')));
    }
}

TEST_CASE("Bad Nose/Mouth") //n
{
    for (size_t i = LEGAL_NUM+1; i < BAD_NUM; i++)
    {
        CHECK_THROWS(snowman(build_snowman(i, 'n')));
    }
}

TEST_CASE("Bad Left Eye") //l
{
    for (size_t i = LEGAL_NUM+1; i < BAD_NUM; i++)
    {
        CHECK_THROWS(snowman(build_snowman(i, 'l')));
    }
}

TEST_CASE("Bad Right Eye") //r
{
    for (size_t i = LEGAL_NUM+1; i < BAD_NUM; i++)
    {
        CHECK_THROWS(snowman(build_snowman(i, 'r')));
    }
}

TEST_CASE("Bad Left Arm") //x
{
    for (size_t i = LEGAL_NUM+1; i < BAD_NUM; i++)
    {
        CHECK_THROWS(snowman(build_snowman(i, 'x')));
    }
}

TEST_CASE("Bad Right Arm") //y
{
    for (size_t i = LEGAL_NUM+1; i < BAD_NUM; i++)
    {
        CHECK_THROWS(snowman(build_snowman(i, 'y')));
    }
}

TEST_CASE("Bad Torso") //t
{
    for (size_t i = LEGAL_NUM+1; i < BAD_NUM; i++)
    {
        CHECK_THROWS(snowman(build_snowman(i, 't')));
    }
}

TEST_CASE("Bad Base") //b
{
    for (size_t i = LEGAL_NUM+1; i < BAD_NUM; i++)
    {
        CHECK_THROWS(snowman(build_snowman(i, 'b')));
    }
}