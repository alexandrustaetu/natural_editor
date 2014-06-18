#!/bin/sh
bindir=$(pwd)
cd /home/alexander/projects/natural_editor/src/
export LD_LIBRARY_PATH=:$LD_LIBRARY_PATH

if test "x$1" = "x--debugger"; then
	shift
	if test "x" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		 -batch -command=$bindir/gdbscript  /home/alexander/projects/natural_editor/bui2/natural 
	else
		"/home/alexander/projects/natural_editor/bui2/natural"  
	fi
else
	"/home/alexander/projects/natural_editor/bui2/natural"  
fi
