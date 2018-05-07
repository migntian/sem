.PHONY:clean
main:comm.c test_sem.c
	gcc -o $@ $^
clean:
	rm -f main
