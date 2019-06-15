#!/bin/bash
SOURCES_DIR=$(dirname "$0")/sources
CLASSES_DIR=$(dirname "$0")/classes

mkdir -p "$CLASSES_DIR"
rm -rf "$CLASSES_DIR/*"

export CLASSPATH="$CLASSPATH:$CLASSES_DIR"


javac -d "$CLASSES_DIR" "$SOURCES_DIR/com/snowwolf/somepackage/SomeClass.java"
javac -d "$CLASSES_DIR" "$SOURCES_DIR/Application.java"
