
all:
	g++ *.cpp `sdl-config --cflags --libs` -lglut -omain

publish:
	bzr export cg1.tar.gz
	scp cg1.tar.gz gilmore:public_html/sources/
	bzr push sftp://gilmore/home/sol/public_html/sources/cg1

clean:
	rm main
