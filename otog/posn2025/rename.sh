#!/bin/bash
if [ -z "$1" ]
then
    echo "Usage: ./test.sh ASSIGNMENT_DIR"
    exit 1
fi

if [ -d "$1" ]
then
    ASSIGNMENT_DIR="$1"
else
    echo "Error: $1 is not a directory"
    exit 1
fi

REPOSITORIES=$(cd "$ASSIGNMENT_DIR"; ls -d *)

rm -rf rename/
mkdir -p rename/

for FILE in $REPOSITORIES; do
    echo "Processing $FILE"
    NAME=`echo "$FILE" | cut -d'.' -f1`
    FULL=`echo "$FILE"`
    if [ NAME != FULL ]; then 
    echo " -> $NAME"
    TARGET=$(find "$ASSIGNMENT_DIR/" -name "$NAME")
    cp "$TARGET" rename/"$NAME.in"
    TARGET=$(find "$ASSIGNMENT_DIR/" -name "$NAME.a")
    cp "$TARGET" rename/"$NAME.out"
    fi
    # echo "exit $PWD"
    # break
done
