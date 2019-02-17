#!/bin/bash

text="one
two
three"
while read -r line; do
	echo "<$line>"
done <<< "$text"
