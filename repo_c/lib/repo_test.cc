#include <string>
#include <cassert>

#include "lib/repo_c.h"


int main(int argc, char** argv) {

    std::string text = "";
    bazel_include_repo::function_c(text);

    assert(text == std::string("repo_c\n"));

    return 0;
}
