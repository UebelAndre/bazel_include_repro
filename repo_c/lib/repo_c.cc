#include <iostream>

#include "lib/repo_c.h"

namespace bazel_include_repo {

void function_c(std::string& text)
{
    text += "repo_c\n";
}

}
