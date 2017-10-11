#!/usr/bin/env bash

SUBDIR=~/Documents/
echo Enter submission name
read ZIP_NAME
COMMAND=$SUBDIR$ZIP_NAME.zip
#echo $COMMAND
zip $COMMAND *.cpp *.h
zip $COMMAND -d testMain.cpp
