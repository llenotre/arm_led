while true;
do
	clear;
	st-util;
	sleep 1;
	while pidof st-flash;
	do
		sleep 1;
	done
done
