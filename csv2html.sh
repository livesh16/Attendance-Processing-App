#!/bin/bash

echo "<TABLE>" > $2
sed -e 's/^/<TR><TD>/' -e 's/,/<\/TD><TD>/g' -e 's/$/<\/TD><\/TR>/' < $1 >> $2
echo "</TABLE>" >> $2

