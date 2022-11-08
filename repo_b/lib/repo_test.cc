#include <string>
#include <cassert>

#include "lib/repo_b.h"


int main(int argc, char** argv) {

    std::string text = "";
    bazel_include_repo::function_b(text);

    assert(text == std::string("repo_b\nrepo_c\n"));

    return 0;
}
