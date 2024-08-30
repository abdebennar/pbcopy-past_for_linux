


all :	copy past bin

copy :
	gcc -lreadline copy.c -o copy

past :
	gcc -lreadline past.c -o past

bin	:
	mv ./copy /bin/
	mv ./past /bin/