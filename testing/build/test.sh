sleepTime=2

function get_obj_timestamp
{
stat -c %Y $build_folder/$1
}

cur_dir=$(pwd)
code_folder=$cur_dir/../../code
build_folder=$cur_dir/../../build
dependency_folder=$cur_dir/../dependency_map
cd $dependency_folder
for f in $(find . -name '*.header_dependency');
do
	file_to_change=${f/header_dependency/h}
	file_to_change=${file_to_change#*/}
#	echo $file_to_change

	purePathFileName=$code_folder/${f#*/}
	fullName=${dependency_folder}${purePathFileName#*"code"};
#	echo $fullName
	mkdir -p ${fullName%/*};
	rm -rf ${fullName%.*}.time_stamps;
	touch ${fullName%.*}.time_stamps;

	while read line
	do
#		echo "${line/.cpp/.o}"
		timestamp=$(get_obj_timestamp ${line/.cpp/.o});
		echo $timestamp
		echo "$timestamp" >> ${fullName%.*}.time_stamps
	done < $f
done
sleep "$sleepTime"


for f in $(find . -name '*.header_dependency');
do
	file_to_change=${f/header_dependency/h}
	file_to_change=${file_to_change#*/}
	#echo $file_to_change
	actual_path=$code_folder/$file_to_change
	cp $actual_path $actual_path".temporary_copy"
	rm $actual_path
	mv $actual_path".temporary_copy" $actual_path
	cd $build_folder
	./build_all.sh
	cd $dependency_folder
	
#	echo $file_to_change

	purePathFileName=$code_folder/${f#*/}
	fullName=${dependency_folder}${purePathFileName#*"code"};
	mkdir -p ${fullName%/*};
	rm -rf ${fullName%.*}.time_stamps_temporary_copy;
	touch ${fullName%.*}.time_stamps_temporary_copy;

	currentLine=0
	while read line
	do
#		echo "${line/.cpp/.o}"
		timestamp=$(get_obj_timestamp ${line/.cpp/.o});
#		echo $timestamp
		echo "$timestamp" >> ${fullName%.*}.time_stamps_temporary_copy
		
		currentLine=$((currentLine+1))
		origStamp=$(sed -n "${currentLine}p" < ${fullName%.*}.time_stamps);
		echo "$f: [$origStamp, $timestamp]"
		if [ "$origStamp" = "$timestamp" ];
		then
			echo "test failed for ${f}";
		fi
	done < $f

	rm -rf ${fullName%.*}.time_stamps
	mv ${fullName%.*}.time_stamps_temporary_copy ${fullName%.*}.time_stamps
done
