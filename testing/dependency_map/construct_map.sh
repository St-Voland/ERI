
#dependency_folder=$(pwd)
cd $code_folder
for f in $(find . -name '*.cpp' -or -name '*.c');
do 
	purePathFileName=$code_folder/${f#*/}
	fullName=${dependency_folder}${purePathFileName#*"code"};
#	echo $fullName;
	mkdir -p ${fullName%/*};
	touch ${fullName%.*}.dependency;
	echo $(date) > ${fullName%.*}.dependency;

	while read line
	do
    		if [[ "$line" = \#include* ]]
		then
			tempLine=${line#*"\""}
    			echo ${tempLine%\"*} >> ${fullName%.*}.dependency;
		fi
	done < $f
done
cd $dependency_folder

