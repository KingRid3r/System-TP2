echo "compilation de la structure de données"
g++ -c -Wall -std=c++11 -I../cereal-1.2.2/include myClass.cpp

echo "compilation de l'écriture JSON"
g++ -c -Wall -std=c++11 -I../cereal-1.2.2/include ecritureJson.cpp
g++ -Wall -std=c++11 ecritureJson.o myClass.o -o ecriture


echo "compilation de lecture JSON"
g++ -c -Wall -std=c++11 -I../cereal-1.2.2/include lectureJson.cpp
g++ -Wall -std=c++11 lectureJson.o myClass.o -o lecture
