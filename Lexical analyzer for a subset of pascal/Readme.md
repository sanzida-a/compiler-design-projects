To run this code use the following commands in ubuntu terminal.

flex -t sample.l >sample.c

g++ -c -o sample.o sample.c

g++ -o samp sample.o -ll

./samp <in.txt>out.txt
