#include <string>
#include <cassert>

#include "lib/repo_a.h"


int main(int argc, char** argv) {

    std::string text = "";
    bazel_include_repo::function_a(text);

    assert(text == std::string("repo_a\nrepo_b\nrepo_c\n"));

    return 0;
}
