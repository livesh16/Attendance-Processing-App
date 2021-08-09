#!/bin/bash

# If number of arguments is not equal to 2, terminate with an error code 1
if [[ $# -ne 2 ]]
then
	echo "Usage fixformat.sh <dirname> <opfile>"
	exit 1
fi

# If the passed argument is not a valid directory, throw an error message and terminate with an error code 1
if [[ ! -d $1 ]]
then
	echo "Error $1 is not a valid directory"
	exit 1
fi

echo "User Email,Name (Original Name),Lab,Total Duration (Minutes)" > $2

labA=$(find $1 -name '[Ll][Aa][Bb]-[Aa].csv')

#echo $labA

# Iterate through each lab A file
for f in $labA
do
	cat $f | awk '
        BEGIN {FS=","} {OFS="," }

        {
                if(NR > 1)
                {
                        if(NF == 4)
                        {
                                { print $2,$1,"A",$3 }
                        }
                        else
                        {
                                { print $2,$1,"A",$5 }
                        }
                }
        }
	' >> $2
done


labB=$(find $1 -name '[Ll][Aa][Bb]-[Bb].csv')

# Iterate through each lab B file
for f in $labB
do
        cat $f | awk '
        BEGIN {FS=","} {OFS="," }
        
        {
		if(NR > 1)
		{
			if(NF == 4)
			{
				{ print $2,$1,"B",$3 }
			}
			else
			{
				{ print $2,$1,"B",$5 }
			}
		}
	}
	' >> $2
done


labC=$(find $1 -name '[Ll][Aa][Bb]-[Cc].csv')

# Iterate through each lab C file
for f in $labC
do
        cat $f | awk '
        BEGIN {FS=","} {OFS="," }

        {
                if(NR > 1)
                {
                        if(NF == 4)
                        {
                                { print $2,$1,"C",$3 }
                        }
                        else
                        {
                                { print $2,$1,"C",$5 }
                        }
                }
        }
        ' >> $2
done


labD=$(find $1 -name '[Ll][Aa][Bb]-[Dd].csv')

# Iterate through each lab B file
for f in $labD
do
        cat $f | awk '
        BEGIN {FS=","} {OFS="," }

        {
                if(NR > 1)
                {
                        if(NF == 4)
                        {
                                { print $2,$1,"D",$3 }
                        }
                        else
                        {
                                { print $2,$1,"D",$5 }
                        }
                }
        }
        ' >> $2
done


labE=$(find $1 -name '[Ll][Aa][Bb]-[Ee].csv')

# Iterate through each lab E file
for f in $labE
do
        cat $f | awk '
        BEGIN {FS=","} {OFS="," }
        
        {
                if(NR > 1)
                {
                        if(NF == 4)
                        {
                                { print $2,$1,"E",$3 }
                        }
                        else
                        {
                                { print $2,$1,"E",$5 }
                        }
                }
        }
        ' >> $2
done



labF=$(find $1 -name '[Ll][Aa][Bb]-[Ff].csv')

# Iterate through each lab F file
for f in $labF
do
        cat $f | awk '
        BEGIN {FS=","} {OFS="," }
        
        {
                if(NR > 1)
                {
                        if(NF == 4)
                        {
                                { print $2,$1,"F",$3 }
                        }
                        else
                        {
                                { print $2,$1,"F",$5 }
                        }
                }
        }
        ' >> $2
done


labG=$(find $1 -name '[Ll][Aa][Bb]-[Gg].csv')

# Iterate through each lab G file
for f in $labG
do
        cat $f | awk '
        BEGIN {FS=","} {OFS="," }

        {
                if(NR > 1)
                {
                        if(NF == 4)
                        {
                                { print $2,$1,"G",$3 }
                        }
                        else
                        {
                                { print $2,$1,"G",$5 }
                        }
                }
        }
        ' >> $2
done


labH=$(find $1 -name '[Ll][Aa][Bb]-[Hh].csv')

# Iterate through each lab H file
for f in $labH
do
        cat $f | awk '
        BEGIN {FS=","} {OFS="," }

        {
                if(NR > 1)
                {
                        if(NF == 4)
                        {
                                { print $2,$1,"H",$3 }
                        }
                        else
                        {
                                { print $2,$1,"H",$5 }
                        }
                }
        }
        ' >> $2
done


labI=$(find $1 -name '[Ll][Aa][Bb]-[Ii].csv')

# Iterate through each lab I file
for f in $labI
do
        cat $f | awk '
        BEGIN {FS=","} {OFS="," }

        {
                if(NR > 1)
                {
                        if(NF == 4)
                        {
                                { print $2,$1,"I",$3 }
                        }
                        else
                        {
                                { print $2,$1,"I",$5 }
                        }
                }
        }
        ' >> $2
done

