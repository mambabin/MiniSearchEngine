#include <string>
#include <muduo/base/Logging.h>
#include "MakePageLib.h"

int main(int argc, char const *argv[])
{
    MakePageLib pagelib(
            "/home/test/art",
            "../data/pagelib.xml",
            "../data/page.index");

    pagelib.traversDirectory();

    return 0;
}


