#include "PageQuery.h"
#include "SegmentSingleton.h"
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{

    SegmentSingleton::getInstance();

    PageQuery pageQuery;

    pageQuery.readPageLibIndex();
    pageQuery.readInvertedIndex();

    string word;
    while(getline(cin, word))
    {
        pageQuery.queryPage(word);
    }

    return 0;
}