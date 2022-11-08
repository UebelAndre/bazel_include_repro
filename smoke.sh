#!/usr/bin/env bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

WORKSPACES=(
repo_c
repo_b
repo_a
)

set -xeuo pipefail

for workspace in ${WORKSPACES[@]}; do
    pushd "${SCRIPT_DIR}/${workspace}" > /dev/null
    bazel test //...
    popd > /dev/null
done

pushd "${SCRIPT_DIR}" > /dev/null
bazel test //...
popd
