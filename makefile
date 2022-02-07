#Fichier de création

#Silent pour echo:
.SILENT:

#Librairie a compiler pour l'app final
*.o = $(bin)/Cours.o $(bin)/Event.o $(bin)/Temps.o $(bin)/Timing.o $(bin)/Planifiable.o $(bin)/Professeur.o $(bin)/Local.o $(bin)/Groupe.o $(bin)/Exception.o $(bin)/TempsException.o $(bin)/TimingException.o $(bin)/HoraireException.o $(bin)/Horaire.o  $(bin)/Liste.o $(bin)/ListeTriee.o $(bin)/Iterateur.o $(bin)/main.o $(bin)/applichorairewindow.o $(bin)/moc_applichorairewindow.o 

#Repertoire des librairies
LibException = ./Exception
LibPlanifiable = ./Planifiable
LibListeTemplate = ./Liste_Template
LibHoraire = ./Horaire
LibQT = ./InterfaceQt

#Repertoire de tout les .o (Parfois en fichier Cacher)
bin = ./.obj

#Application Final:
ApplicHoraire:	$(*.o)
		echo Creation de ApplicHoraire.app
		g++ -Wl,-O1 -o ApplicHoraire.app $(*.o)  /usr/lib64/libQt5Widgets.so /usr/lib64/libQt5Gui.so /usr/lib64/libQt5Core.so /usr/lib64/libGL.so -lpthread 					


#Creation Librairie Graphique:
$(bin)/main.o:	$(LibQT)/main.cpp
				echo Creation de main.o
				g++ -c -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ -o $(bin)/main.o $(LibQT)/main.cpp

$(bin)/applichorairewindow.o:	$(LibQT)/applichorairewindow.cpp $(LibQT)/applichorairewindow.h $(LibQT)/ui_applichorairewindow.h
								echo Creation de applichorairewindow.o
								g++ -c -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ -o $(bin)/applichorairewindow.o $(LibQT)/applichorairewindow.cpp

$(bin)/moc_applichorairewindow.o:	$(LibQT)/moc_applichorairewindow.cpp $(LibQT)/applichorairewindow.h
									echo Creation de moc_applichorairewindow.o
									g++ -c -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ -o $(bin)/moc_applichorairewindow.o $(LibQT)/moc_applichorairewindow.cpp


#creation Librairie HORAIRE:
$(bin)/Horaire.o:	$(LibHoraire)/Horaire.cpp $(LibHoraire)/Horaire.h $(LibHoraire)/Cours.h $(LibPlanifiable)/Groupe.h $(LibPlanifiable)/Professeur.h $(LibPlanifiable)/Local.h $(LibListeTemplate)/ListeTriee.h $(LibListeTemplate)/Iterateur.h
			echo Création Horaire.o
			g++ $(LibHoraire)/Horaire.cpp -c -o $(bin)/Horaire.o

$(bin)/Event.o:	$(LibHoraire)/Event.cpp $(LibHoraire)/Event.h
			echo Création Event.o
			g++ $(LibHoraire)/Event.cpp -c -o $(bin)/Event.o

$(bin)/Temps.o:	$(LibHoraire)/Temps.cpp $(LibHoraire)/Temps.h
			echo Création Temps.o
			g++ $(LibHoraire)/Temps.cpp -c -o $(bin)/Temps.o

$(bin)/Timing.o:	$(LibHoraire)/Timing.cpp $(LibHoraire)/Timing.h
			echo Création Timing.o
			g++ $(LibHoraire)/Timing.cpp -c -o $(bin)/Timing.o


#Creation Event Spéciaux type Cours:
$(bin)/Cours.o:	$(LibHoraire)/Cours.cpp $(LibHoraire)/Cours.h $(LibHoraire)/Event.h
			echo Création Cours.o
			g++ $(LibHoraire)/Cours.cpp -c -o $(bin)/Cours.o


#creation des Planifiables
$(bin)/Planifiable.o:	$(LibPlanifiable)/Planifiable.cpp $(LibPlanifiable)/Planifiable.h
				echo Création Planifiable.o
				g++ $(LibPlanifiable)/Planifiable.cpp -c -o $(bin)/Planifiable.o 

$(bin)/Professeur.o:	$(LibPlanifiable)/Professeur.cpp $(LibPlanifiable)/Professeur.h
				echo Création Professeur.o
				g++ $(LibPlanifiable)/Professeur.cpp -c -o $(bin)/Professeur.o

$(bin)/Local.o:	$(LibPlanifiable)/Local.cpp $(LibPlanifiable)/Local.h
			echo Création Local.o
			g++ $(LibPlanifiable)/Local.cpp -c -o $(bin)/Local.o

$(bin)/Groupe.o:	$(LibPlanifiable)/Groupe.cpp $(LibPlanifiable)/Groupe.h
			echo Création Groupe.o
			g++ $(LibPlanifiable)/Groupe.cpp -c -o $(bin)/Groupe.o


#creation des Exceptions
$(bin)/Exception.o:	$(LibException)/Exception.cpp $(LibException)/Exception.h
				echo Création Exception.o
				g++ $(LibException)/Exception.cpp -c -o $(bin)/Exception.o

$(bin)/TempsException.o:	$(LibException)/TempsException.cpp $(LibException)/TempsException.h
					echo Création TempsException.o
					g++ $(LibException)/TempsException.cpp -c -o $(bin)/TempsException.o

$(bin)/TimingException.o:	$(LibException)/TimingException.cpp $(LibException)/TimingException.h
					echo Création TimingException.o
					g++ $(LibException)/TimingException.cpp -c -o $(bin)/TimingException.o

$(bin)/HoraireException.o:	$(LibException)/HoraireException.cpp $(LibException)/HoraireException.h
					echo Création HoraireException.o
					g++ $(LibException)/HoraireException.cpp -c -o $(bin)/HoraireException.o

#include "../Horaire/Cours.h"
	#include "../Planifiable/Professeur.h"
    #include "../Planifiable/Groupe.h"
    #include "../Planifiable/Local.h"
#Creation Template Liste
$(bin)/Liste.o:	$(LibListeTemplate)/Liste.cpp $(LibListeTemplate)/Liste.h $(LibHoraire)/Cours.h $(LibPlanifiable)/Professeur.h $(LibPlanifiable)/Local.h $(LibPlanifiable)/Groupe.h
			echo Création Liste.o
			g++ $(LibListeTemplate)/Liste.cpp -c -o $(bin)/Liste.o

$(bin)/ListeTriee.o:	$(LibListeTemplate)/ListeTriee.cpp $(LibListeTemplate)/ListeTriee.h $(LibHoraire)/Cours.h $(LibPlanifiable)/Professeur.h $(LibPlanifiable)/Local.h $(LibPlanifiable)/Groupe.h
			echo Création ListeTriee.o
			g++ $(LibListeTemplate)/ListeTriee.cpp -c -o $(bin)/ListeTriee.o

$(bin)/Iterateur.o:	$(LibListeTemplate)/Iterateur.cpp $(LibListeTemplate)/Iterateur.h $(LibHoraire)/Cours.h $(LibPlanifiable)/Professeur.h $(LibPlanifiable)/Local.h $(LibPlanifiable)/Groupe.h
				echo Création Iterateur.o
				g++ $(LibListeTemplate)/Iterateur.cpp -c -o $(bin)/Iterateur.o


#Clean/Clear des .o et de l'application
clean:	
		rm $(*.o)
		rm ApplicHoraire.app
		clear

clear:	
		rm $(*.o)
		rm ApplicHoraire.app
		clear

first: dir ApplicHoraire

dir: 
		mkdir ./.obj