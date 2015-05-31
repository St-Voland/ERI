# Name: build_all.sh
# Description: Script that build the entire project
# Author: G.Molyboga(St.George.Molyboga@gmail.com)
# Date: 24 May, 2015
# Review: 31 May, 2015
echo "build_all.sh started..."
export Makefile_PWD=$(pwd)

cd core/
export Makefile_core_PWD=$(pwd)
cd $Makefile_PWD

cd ../code
export code_PWD=$(pwd)
cd $Makefile_PWD

cd ../bin
export bin_PWD=$(pwd)
cd $Makefile_PWD

export DEBUG="false"

if [ $? == 1 ]
then
    make
else
    make $1
fi

