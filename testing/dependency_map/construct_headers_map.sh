code_folder=../../code
dependency_folder=$(pwd)
cd $code_folder
for f in $(find . -name '*.hpp' -or -name '*.h');
do
	dependencies=$(grep -r "${f#*/}" .)

	purePathFileName=$code_folder/${f#*/}
	fullName=${dependency_folder}${purePathFileName#*"code"};
	mkdir -p ${fullName%/*};
	rm -rf ${fullName%.*}.header_dependency;
	touch ${fullName%.*}.header_dependency;
#	echo $(date) > ${fullName%.*}.header_dependency;

	line=$dependencies
	while [ "$line" != "" ];
	do
		line=${line#*/}
		tempLine=${line%%\:*}
		if [[ ${tempLine##*\.} != "h" ]];
		then
			if [[ "$tempLine" = *"source/"* ]];
			then
				tempLine=${tempLine/"source/"/""}
			fi
			echo $tempLine >> ${fullName%.*}.header_dependency
		fi
		line=${line#*$tempLine}
		line=${line#*\"}
		line=${line#*\"}
		if [[ "$line" != *"include"* ]];
		then
			line=""
		fi
#		echo $line
	done
done
