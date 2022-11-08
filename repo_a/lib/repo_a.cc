#include <iostream>

#include "external/repo_b/lib/repo_b.h"

#include "lib/repo_a.h"

namespace bazel_include_repo {

void function_a(std::string& text)
{
    text += "repo_a\n";
    function_b(text);
}

}
