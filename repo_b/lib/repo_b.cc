#include <iostream>

#include "external/repo_c/lib/repo_c.h"

#include "lib/repo_b.h"

namespace bazel_include_repo {

void function_b(std::string& text)
{
    text += "repo_b\n";
    function_c(text);
}

}
