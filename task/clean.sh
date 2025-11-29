#!/bin/sh -x

ROOT_DIR=$(dirname $0)/..

cd ${ROOT_DIR}

for i in examples/*; do (cd ${i}; ./clean.sh); done
