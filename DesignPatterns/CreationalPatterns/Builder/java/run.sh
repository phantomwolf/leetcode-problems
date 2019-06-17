#!/bin/bash
DIR=$(dirname "$0")
pushd "$DIR" &> /dev/null
rm -f *.class
javac Main.java
java Main $@
rm -f *.class
popd &> /dev/null
